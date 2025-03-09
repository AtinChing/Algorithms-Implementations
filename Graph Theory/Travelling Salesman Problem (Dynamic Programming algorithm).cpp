#include "Data Structures used/WeightedGraphNode.h"
#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>
#include <deque>
#include <algorithm>
#include <utility>
using namespace std;
void combinations(int curSet, int at, int r, int n, vector<int>& combs){ 
    if (r != 0){ // if we need to place none, then that means we've reached the base case/a valid state for the set to be added to our list of combinations
        // otherwise keep backtracking/recursing
        for(int i = at; i < n; i++){
            curSet = curSet ^ (1 << i); // this flips the ith bit.
            /*
            if curSet is 0101110
            and i is 3, (1 << i) is 1000.
            0100110
            0001000 (XOR)
            0101110
            */
            //cout << "Flipping bit " << i << " | curSet: " << curSet << endl; // Debugging output
           
            combinations(curSet, i+1, r-1, n, combs);
            // the bit we just flipped, go one higher than that so i+1, r-1 because now we have less bit to flip
            curSet = curSet ^ (1 << i); // backtracking and setting this bit's value back to what it originally was.
            // so back to originally 0100110
        }

    }
    else if(r==0){
        //cout << "Pushing " << curSet << " to combs" << endl; // Debugging output
        combs.push_back(curSet);
        return;
    }

}
vector<int> combinations(int i, int n){ // so we want to generate combinations which are of size n and specifically have i bits set to 1.
    vector<int> combs; // remember that one combination of bits just makes up an integer, so our combinations is just stored as a vector/collection of integers.
    combs.reserve(10000);
    combinations(0, 0, i, n, combs);
    return combs;
}
bool notIn(int num, int subset){
    return ((1 << num) & subset) == 0;
}

int findMinCost(vector<vector<int>>& dists, vector<vector<int>>& dp, int start, int num_nodes){
    // end state is the bit mask with N bits set to 1 (which mathematically is 2^N -1 so could also write it as that)
    int endState = (1 << num_nodes) - 1; // can also be written as 2**N - 1
    int minTourCost = INT_MAX;
    for(int i = 0; i < num_nodes; i++){
        if(i == start) continue; // obviously not goting to check subsets that end at the start node
        int tourCost = dp[i][endState] + dists[i][start]; // checking with every possible combination of looping our last/end node back to the start node
        minTourCost = min(minTourCost, tourCost);
    }
    return minTourCost;
}
vector<int> findOptimalTour(vector<vector<int>>& dists, vector<vector<int>>& dp, int start, int num_nodes){
    int lastIndex = start; // we want the 
    int state = (1 << num_nodes) - 1; // end state is the bit mask with N bits set to 1 (which mathematically is 2^N -1 so could also write it as that)
    vector<int> tour(num_nodes+1);
    for(int i = num_nodes-1; i >= 1; i--){
        int index = -1;
        for(int j = 0; j < num_nodes; j++){
            if(j == start || notIn(j, state)) continue;
            if(index == -1) index = j;
            int prevDist = dp[index][state] + dists[index][lastIndex];
            int newDist = dp[j][state] + dists[j][lastIndex];
            if(newDist<prevDist) index = j;
        }
        tour[i] = index;
        state = state ^ (1 << index);
        lastIndex = index;
    }
    tour[0] = start;
    tour[num_nodes] = start;
    return tour; 
}

pair<int, vector<int>> TSP(GraphNode* nodes[], int num_nodes, GraphNode* nodeFrom, int* size, vector<vector<int>>& dists, set<GraphNode*> visited = {}){
    vector<vector<int>> dp; // setting up our DP table
    for(int i = 0; i < num_nodes; i++){
        vector<int> innerrow;
        for(int j = 0; j < (1 << num_nodes); j++){
            innerrow.push_back(0);
        }
        dp.push_back(innerrow);
    }    
    // dp[i][j] represents a path where the last visited node is i, and the path is represented by the int j (where the binary representation of j will tell you the set bits which tell you what the current subpath is). 
    
    for(auto nodeToPair: nodeFrom->adj){ // setting up all subpaths of length 2 in our DP table
        auto nodeTo = nodeToPair.first;
        auto dist = nodeToPair.second;
        dp[nodeTo->val][1 << nodeFrom->val | 1 << nodeTo->val] = dist;    
    }

    for(int i = 0; i < num_nodes; i++){
        auto node = nodes[i];
        for(int subset : combinations(i, num_nodes)){ // all combinations which are of size num_nodes and specifically have i bits set to 1.
            // here, combinations would result in something like (for node 0), 000, (for node 1) 001, 010, 100, (for node 2), 110, 101, 011, (for node 3), 111
            if (notIn(nodeFrom->val, subset)){ // we only check combinations for when our start node is included
                for(int next = 0; next < num_nodes; next++){
                    auto nextNode = nodes[next];
                    if(nextNode == nodeFrom || notIn(next, subset)){
                        auto state = subset ^ (1 << next); // create a state without the next node were going to add
                        int minDist = INT_MAX;
                        for (int end = 0; end < num_nodes; end++){
                            auto endNode = nodes[end];
                            if(endNode == nodeFrom || endNode == nodeFrom || notIn(end, subset)){
                                continue;
                            }
                            int newDist = dp[end][state] + dists[end][next];
                            if(newDist < minDist){
                                minDist = newDist;
                            }
                            dp[next][subset] = minDist;
                        }
                    }
                }
            }
        }
    }
    int minCost = findMinCost(dists, dp, nodeFrom->val, num_nodes);
    vector<int> tour = findOptimalTour(dists, dp, nodeFrom->val, num_nodes);
    return std::make_pair(minCost, tour);

}

int main(){
    GraphNode* root = new GraphNode(0);
    GraphNode* B = new GraphNode(1);
    GraphNode* C = new GraphNode(2);
    GraphNode* D = new GraphNode(3);
    GraphNode* E = new GraphNode(4);
    GraphNode* F = new GraphNode(5);
    GraphNode* G = new GraphNode(6);
    GraphNode* H = new GraphNode(7);
    GraphNode* nodes[] = {root, B, C, D, E, F, G, H};
    root->addEdge(B, 12);
    root->addEdge(C, 7);
    root->addEdge(D, 19);
    root->addEdge(E, 3);
    root->addEdge(F, 15);
    root->addEdge(G, 9);
    root->addEdge(H, 11);

    // From B (1)
    B->addEdge(root, 12);
    B->addEdge(C, 5);
    B->addEdge(D, 17);
    B->addEdge(E, 8);
    B->addEdge(F, 13);
    B->addEdge(G, 4);
    B->addEdge(H, 20);

    // From C (2)
    C->addEdge(root, 7);
    C->addEdge(B, 5);
    C->addEdge(D, 10);
    C->addEdge(E, 16);
    C->addEdge(F, 2);
    C->addEdge(G, 18);
    C->addEdge(H, 6);

    // From D (3)
    D->addEdge(root, 19);
    D->addEdge(B, 17);
    D->addEdge(C, 10);
    D->addEdge(E, 14);
    D->addEdge(F, 11);
    D->addEdge(G, 1);
    D->addEdge(H, 15);

    // From E (4)
    E->addEdge(root, 3);
    E->addEdge(B, 8);
    E->addEdge(C, 16);
    E->addEdge(D, 14);
    E->addEdge(F, 9);
    E->addEdge(G, 12);
    E->addEdge(H, 7);

    // From F (5)
    F->addEdge(root, 15);
    F->addEdge(B, 13);
    F->addEdge(C, 2);
    F->addEdge(D, 11);
    F->addEdge(E, 9);
    F->addEdge(G, 20);
    F->addEdge(H, 4);

    // From G (6)
    G->addEdge(root, 9);
    G->addEdge(B, 4);
    G->addEdge(C, 18);
    G->addEdge(D, 1);
    G->addEdge(E, 12);
    G->addEdge(F, 20);
    G->addEdge(H, 13);

    // From H (7)
    H->addEdge(root, 11);
    H->addEdge(B, 20);
    H->addEdge(C, 6);
    H->addEdge(D, 15);
    H->addEdge(E, 7);
    H->addEdge(F, 4);
    H->addEdge(G, 13);
    int nodesCount = sizeof(nodes)/sizeof(GraphNode*);

    // setting up adjacency matrix of distances
    vector<vector<int>> dists;
        for(int i = 0; i < nodesCount; i++){
            vector<int> innerrow;
            for(int j = 0; j < nodesCount; j++){
                if (i != j){
                innerrow.push_back( nodes[i]->adj[nodes[i]->getInd(nodes[j])].second );
                }
            }
            dists.push_back(innerrow);
        }   
    auto node1 = root;
    int size = 0;
    auto res = TSP(nodes, nodesCount, node1, &size, dists);
    auto path = res.second;
    int pathSize = res.first;
    cout << "TSP algorithm path:" << endl;
    for(int i = 0; i < path.size(); i++){
        cout << path[i] << " ";
    }
    cout << endl;
    cout << "size was " << pathSize << endl;
    return 0;
}
