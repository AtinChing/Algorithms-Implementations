#include "Data Structures used/WeightedGraphNode.h"
#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>
#include <deque>
#include <algorithm>
using namespace std;
vector<int> combinations(int i, int n){ // so we want to generate combinations which are of size n and specifically have i bits set to 1.
    vector<int> combs; // remember that one combination of bits just makes up an integer, so our combinations is just stored as a vector/collection of integers.
    combinations(0, 0, i, n, combs);
    return combs;
}
vector<int> combinations(int curSet, int at, int r, int n, vector<int>& combs){ 
    if (r == 0){ // if we need to place none, then that means we've reached the base case/a valid state for the set to be added to our list of combinations
        for(int i = at; i < n; i++){
            curSet = curSet | (1 << i); // this flips the ith bit.
            combinations(curSet, i+1, r-1, n, combs);
            curSet = curSet & ~(1 << i); // backtracking and setting this bit's value back to what it originally was.
        }
    }
}
int findMinCost(vector<vector<int>>& dists, vector<vector<int>>& dp, int start, int num_nodes){
    // end state is the bit mask
    int endState = (1 << num_nodes) - 1;
    int minTourCost = INT_MAX;
    for(int i = 0; i < num_nodes; i++){
        if(i == start) continue;
        int tourCost = dp[i][endState] + dists[i][start]; // checking with every possible combination of looping our last/end node back to the start node
        minTourCost = min(minTourCost, tourCost);
    }
    return minTourCost;
}
int findOptimalTour(vector<vector<int>>& dists, vector<vector<int>>& dp, int start, int num_nodes){
}
bool notIn(int num, int subset){
    return ((1 << num) & subset) == 0;
}
vector<GraphNode*> TSP(GraphNode* nodes[], int num_nodes, GraphNode* nodeFrom, int* size, vector<vector<int>>& dists, set<GraphNode*> visited = {}){
    vector<vector<int>> dp;
    for(int i = 0; i < num_nodes; i++){
        vector<int> innerrow;
        for(int j = 0; j < num_nodes; j++){
            innerrow.push_back(0);
        }
        dp.push_back(innerrow);
    }    

    for(auto nodeToPair: nodeFrom->adj){
        auto nodeTo = nodeToPair.first;
        auto dist = nodeToPair.second;
        dp[nodeTo->val][1 << nodeFrom->val | 1 << nodeTo->val] = dist;    
    }

    for(int i = 0; i < num_nodes; i++){
        auto node = nodes[i];
        for(int subset : combinations(i, num_nodes)){
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
    int nodesCount = sizeof(nodes)/sizeof(GraphNode*);
    vector<vector<int>> dists;
        for(int i = 0; i < nodesCount; i++){
            vector<int> innerrow;
            for(int j = 0; j < nodesCount; j++){
                innerrow.push_back(0);
            }
            dists.push_back(innerrow);
        }   
    auto node1 = root;
    int size = 0;
    auto res = TSP(nodes, nodesCount, node1, &size, dists);
    cout << "TSP algorithm path:" << endl;
    for(int i = 0; i < res.size(); i++){
        cout << res[i]->val << " ";
    }
    cout << endl;
    cout << "size was " << size << endl;
    return 0;
}
