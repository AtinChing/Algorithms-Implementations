#include "Data Structures used/GraphNode.h"
#include <iostream>
#include <set>
using std::set;
using namespace std;
void TopSort(GraphNode* node, vector<GraphNode*>* ordering, set<int> *visited){
    for(auto nodeVisit : node->adj){
        if(visited->find(nodeVisit->val) == visited->end()){
            visited->insert(nodeVisit->val);
            TopSort(nodeVisit, ordering, visited);
        }
    }
    ordering->insert(ordering->begin(), node);
}   
int main(){
    /*
    More simple graph to test on
    GraphNode root(1);
    GraphNode node1(2);
    GraphNode node2(3);
    GraphNode node3(4);
    root.addEdge(&node1);
    node1.addEdge(&node2);
    node2.addEdge(&node3);
    */
    // More complex graph to test on
    GraphNode root(1);  // A
    GraphNode nodeB(2);  // B
    GraphNode nodeC(3);  // C
    GraphNode nodeD(4);  // D
    GraphNode nodeE(5);  // E
    GraphNode nodeF(6);  // F

    // Add edges (directed)
    root.addEdge(&nodeB); // A -> B
    root.addEdge(&nodeC); // A -> C
    nodeB.addEdge(&nodeD); // B -> D
    nodeC.addEdge(&nodeD); // C -> D
    nodeD.addEdge(&nodeE); // D -> E
    nodeE.addEdge(&nodeF); // E -> F

    vector<GraphNode*> order;
    set<int> visited;
    TopSort(&root, &order, &visited);
    cout << "TOPOLOGICAL ORDERING:" << endl;
    for(auto node : order){
        cout << node->val << ' ';    
    }
}
