#include "Topological Sort.cpp"
#include "Data Structures used/WeightedGraphNode.h"
#include <vector>
using namespace std;
vector<int> ShortestPathDAG(auto ordering){

}

int main(){
    GraphNode* A = new GraphNode(3);
    GraphNode* B = new GraphNode(11);
    GraphNode* C = new GraphNode(6);
    GraphNode* D = new GraphNode(5);
    GraphNode* E = new GraphNode(9);
    GraphNode* F = new GraphNode(1);
    GraphNode* G = new GraphNode(2);
    GraphNode* H = new GraphNode(0);

    // Add the edges
    A->addEdge(B, 4);
    B->addEdge(A, 3);
    B->addEdge(C, 8);
    B->addEdge(D, -4);
    B->addEdge(E, -4);
    D->addEdge(B, 5);
    D->addEdge(F, 2);
    E->addEdge(F, 1);
    E->addEdge(H, 9);
    F->addEdge(G, 11);
    G->addEdge(E, 2);
    return 0;
}
