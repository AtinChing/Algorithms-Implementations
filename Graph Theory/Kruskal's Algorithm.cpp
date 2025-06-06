#include "Data Structures used/UndirectedWeightedGraphNode.h"
#include "Data Structures used/Union Find.cpp"
#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>
#include <deque>
#include <algorithm>
using namespace std;
struct Edge{
    GraphNode* nodeA;
    GraphNode* nodeB;
    int distance;
};
vector<Edge> Kruskals(GraphNode* nodes[], int num_nodes, set<GraphNode*> included = {}){
    vector<Edge> edges;
    for(int i = 0; i < num_nodes; i++){
        auto node = nodes[i];
        for(auto pair: node->adj){
            Edge edge = {node, pair.first, pair.second};
            edges.push_back(edge);
        }
    }
    UnionFind<GraphNode> uf = UnionFind(num_nodes, &(nodes[0]));
    sort(edges.begin(), edges.end(), [](Edge e1, Edge e2){return e1.distance < e2.distance;});
    vector<Edge> approvedEdges = {};
    for(auto edge : edges){
        if(uf.components() == 1){
            break;
        }
        if(uf.find(*edge.nodeA) != uf.find(*edge.nodeB)){
            approvedEdges.push_back(edge);
            included.insert(edge.nodeA);
            included.insert(edge.nodeB);
            uf.unify(*edge.nodeA, *edge.nodeB);
        }
    }
    return approvedEdges;
    // Optional code below to convert the graph into the MST (remove any edges that aren't part of the final MST set of edges)
    /*for(auto node : nodes){
        for(auto pair : node->adj){
            Edge edge = {node, pair.first, pair.second};
            if(approvedEdges.find(edge) == approvedEdges.end()){
                node->removeEdge(pair.first, pair.second);
            }
        }
    }*/
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
    root->addEdge(B, 3);
    root->addEdge(C, 6);
    B->addEdge(C, 4);
    B->addEdge(D, 4);
    B->addEdge(E, 11);
    C->addEdge(D, 8);
    C->addEdge(G, 11);
    D->addEdge(E, 4);
    D->addEdge(G, 2);
    D->addEdge(F, 5);
    E->addEdge(H, 9);
    F->addEdge(H, 1);
    G->addEdge(H, 2);
    auto mstEdges = Kruskals(nodes, nodesCount);
    int sum = 0;
    for(int i = 0; i < mstEdges.size(); i++){
        sum += mstEdges[i].distance;
    }
    cout << "Found an MST, with weight " << sum << ", that contains the following edges:" << endl;
    for(int i = 0; i < mstEdges.size(); i++){
        Edge edge = mstEdges[i];
        cout << edge.nodeA->val << " TO " << edge.nodeB->val << " WITH DISTANCE " << edge.distance << endl;
    }
    return 0;
}
