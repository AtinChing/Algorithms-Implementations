#include "Data Structures used/UndirectedWeightedGraphNode.h"
#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>
#include <deque>
#include <algorithm>
using namespace std;
void dfs(GraphNode* node, GraphNode* parent, unordered_map<int, int>& mapping, unordered_map<int, int>& id, int& curLL, set<GraphNode*>& visited, vector<GraphNode*>& res, unordered_map<int, int>& outgoingEdges){
        if(mapping.find(node->val) == mapping.end()){
            id[node->val] = curLL;
            mapping[node->val] = curLL;
            curLL++;
        }
        visited.insert(node);
        for(auto nodeToPair : node->adj){
            auto nodeTo = nodeToPair.first;
            auto dist = nodeToPair.second;
            if(nodeTo==parent) continue;
            if(visited.find(nodeTo) == visited.end()){ // if this node wasn't visited
                outgoingEdges[node->val]++;
                dfs(nodeTo, node, mapping, id, curLL, visited, res, outgoingEdges);
                mapping[node->val] = min(mapping[node->val], mapping[nodeTo->val]);
                
            }
            else{
                mapping[node->val] = min(mapping[node->val], id[nodeTo->val]);
            }
        }
        for(auto nodeToPair : node->adj){
            auto nodeTo = nodeToPair.first;
            auto dist = nodeToPair.second;
            if(nodeTo==parent) continue;
            if(outgoingEdges[node->val] > 1 && mapping[nodeTo->val] == id[node->val]){
                res.push_back(node);
                break;
            }
        }
        
}
vector<GraphNode*> ArticulationPointFinder(GraphNode* nodes[], int num_nodes, set<GraphNode*> visited = {}){
    unordered_map<int, int> mapping; // mapping of node val to low link value
    unordered_map<int, int> id;
    int cur = 0;
    vector<GraphNode*> nodeList;
    unordered_map<int, int> outgoingEdges;
    for(int i =0; i < num_nodes; i++){
        dfs(nodes[i], nullptr, mapping, id, cur, visited, nodeList, outgoingEdges);

    }
    return nodeList;
}

int main(){
    /*GraphNode* root = new GraphNode(0);
    GraphNode* B = new GraphNode(1);
    GraphNode* C = new GraphNode(2);
    GraphNode* D = new GraphNode(3);
    GraphNode* E = new GraphNode(4);
    GraphNode* nodes[] = {root, B, C, D, E};
    int nodesCount = sizeof(nodes)/sizeof(GraphNode*);
    root->addEdge(B, 1);  // 0 -> 1
    root->addEdge(E, 1);  // 0 -> 4
    B->addEdge(C, 1);     // 1 -> 2
    C->addEdge(D, 1);     // 2 -> 3
    D->addEdge(root, 1);  // 3 -> 0
    auto resNodesList = ArticulationPointFinder(nodes, nodesCount);
    cout << "Here are all the articulation points found in the given graph:" << endl;
    for(int i = 0; i < resNodesList.size(); i++){
        GraphNode* node = resNodesList[i];
        cout << "NODE " << node->val<< endl;
    }
    */
    // Test Case 2: Star-like Graph
    /*GraphNode* A = new GraphNode(0);
    GraphNode* B = new GraphNode(1);
    GraphNode* C = new GraphNode(2);
    GraphNode* D = new GraphNode(3);
    GraphNode* E = new GraphNode(4);
    GraphNode* nodes1[] = {A, B, C, D, E};
    int nodesCount1 = sizeof(nodes1)/sizeof(GraphNode*);

    A->addEdge(B, 1);
    A->addEdge(C, 1);
    A->addEdge(D, 1);
    A->addEdge(E, 1);

    auto resNodesList1 = ArticulationPointFinder(nodes1, nodesCount1);
    cout << "Test Case 1 Articulation Points:" << endl;
    for(auto node : resNodesList1){
        cout << "NODE " << node->val << endl;
    }

    // Test Case 3: Circular Graph
    GraphNode* F = new GraphNode(0);
    GraphNode* G = new GraphNode(1);
    GraphNode* H = new GraphNode(2);
    GraphNode* I = new GraphNode(3);
    GraphNode* nodes2[] = {F, G, H, I};
    int nodesCount2 = sizeof(nodes2)/sizeof(GraphNode*);

    F->addEdge(G, 1);
    G->addEdge(H, 1);
    H->addEdge(I, 1);
    I->addEdge(F, 1);

    auto resNodesList2 = ArticulationPointFinder(nodes2, nodesCount2);
    cout << "Test Case 2 Articulation Points:" << endl;
    for(auto node : resNodesList2){
        cout << "NODE " << node->val << endl;
    }*/
    // Complex Graph example
    GraphNode* J = new GraphNode(0);
    GraphNode* K = new GraphNode(1);
    GraphNode* L = new GraphNode(2);
    GraphNode* M = new GraphNode(3);
    GraphNode* N = new GraphNode(4);
    GraphNode* O = new GraphNode(5);
    GraphNode* nodes3[] = {J, K, L, M, N, O};
    int nodesCount3 = sizeof(nodes3)/sizeof(GraphNode*);

    J->addEdge(K, 1);
    J->addEdge(L, 1);
    K->addEdge(M, 1);
    L->addEdge(M, 1);
    M->addEdge(N, 1);
    M->addEdge(O, 1);

    auto resNodesList3 = ArticulationPointFinder(nodes3, nodesCount3);
    cout << "Here are all the articulation points found in the given graph:" << endl;
    for(auto node : resNodesList3){
        cout << "NODE " << node->val << endl;
    }
    return 0;
}
