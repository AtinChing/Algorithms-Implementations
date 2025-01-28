#include "Data Structures used/WeightedGraphNode.h"
#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>
#include <deque>
#include <algorithm>
using namespace std;
void dfs(GraphNode* node, unordered_map<int, int>& mapping, unordered_map<int, int>& id, int& curLL, set<GraphNode*>& visited, vector<vector<GraphNode*>>& res, vector<GraphNode*>& stack, set<GraphNode*>& stackset){
        if(mapping.find(node->val) == mapping.end()){
            id[node->val] = curLL;
            mapping[node->val] = curLL;
            curLL++;
        }
        stack.push_back(node);
        stackset.insert(node);
        visited.insert(node);
        for(auto nodeToPair : node->adj){
            auto nodeTo = nodeToPair.first;
            auto dist = nodeToPair.second;
            if(visited.find(nodeTo) == visited.end()){
                dfs(nodeTo, mapping, id, curLL, visited, res, stack, stackset);
                mapping[node->val] = min(mapping[node->val], mapping[nodeTo->val]); // we just visited this node so we can min low link values with it
            }
            else if(stackset.find(nodeTo) != stackset.end()){ // otherwise, if node to has been visited and IS on the stack, then we can min low link values with it.
                mapping[node->val] = min(mapping[node->val], mapping[nodeTo->val]);
            }
        }
        // After visiting all edges, if current node's low link value is equal to its ID, then its the beginning of an SCC.
        if(mapping[node->val] == id[node->val]){
            vector<GraphNode*> currentSCC;
            while(stack.back()->val != node->val){
                auto node = stack.back();
                currentSCC.push_back(node);
                stack.pop_back();
                stackset.erase(node);
            }
            // pop one more time to ensure that the node, that starts the SCC, is included in the current SCC group
            auto node = stack.back();
            currentSCC.push_back(node);
            res.push_back(currentSCC);
            stack.pop_back();
            stackset.erase(node);
        }
}
vector<vector<GraphNode*>> TarjansStronglyConnectedComponents(GraphNode* nodes[], int num_nodes, set<GraphNode*> visited = {}){
    unordered_map<int, int> mapping; // mapping of node val to low link value
    unordered_map<int, int> id;
    vector<GraphNode*> stack;
    set<GraphNode*> stackset;
    int cur = 0;
    vector<vector<GraphNode*>> stronglyConnectedComponentsList;
    for(int i =0; i < num_nodes; i++){
        if(visited.find(nodes[i]) == visited.end()) dfs(nodes[i], mapping, id, cur, visited, stronglyConnectedComponentsList, stack, stackset);
    }
    return stronglyConnectedComponentsList;
}

int main(){
    GraphNode* A = new GraphNode(0); // Node 0
    GraphNode* B = new GraphNode(1); // Node 1
    GraphNode* C = new GraphNode(2); // Node 2
    GraphNode* D = new GraphNode(3); // Node 3
    GraphNode* E = new GraphNode(4); // Node 4
    GraphNode* F = new GraphNode(5); // Node 5
    GraphNode* G = new GraphNode(6); // Node 6
    GraphNode* H = new GraphNode(7); // Node 7
    GraphNode* nodes[] = {A, B, C, D, E, F, G, H};
    int nodesCount = sizeof(nodes)/sizeof(GraphNode*);
    A->addEdge(B, 1);
    A->addEdge(E, 1);
    B->addEdge(F, 1);
    C->addEdge(B, 1);
    C->addEdge(D, 1);
    C->addEdge(G, 1);
    D->addEdge(G, 1);
    E->addEdge(A, 1);
    E->addEdge(F, 1);
    F->addEdge(C, 1);
    F->addEdge(G, 1);
    G->addEdge(H, 1);
    H->addEdge(D, 1);
    vector<vector<GraphNode*>> resNodesList = TarjansStronglyConnectedComponents(nodes, nodesCount);
    cout << "Here are all the strongly connected components found in the given graph:" << endl;
    for(int i = 0; i < resNodesList.size(); i++){
        cout << "This is strongly connected component " << i+1 << ":" << endl;
        for(int j = 0; j < resNodesList[i].size(); j++){
            cout << "NODE " << resNodesList[i][j]->val<< endl;
        }
        cout << endl;
    }
    return 0;
}
