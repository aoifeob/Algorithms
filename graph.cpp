#include <iostream>
#include <cstdlib>
#include "graph.hpp"
using namespace std;

//create a new node
struct Node* newNode(char data, int weight){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->weight=weight;
    newNode->next=NULL;
    return newNode;
}

//create a graph with V vertices
struct Graph* makeGraph(int Vertex){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->Vertex=Vertex;

    //create array[Vertex] of lists
    graph->array = (struct List*)malloc(sizeof(struct List));

    //make start of each list null
    for (int i=0; i<Vertex; i++){
        graph->array[i].start=NULL;
    }
    return graph;
}

//add an edge
void newEdge(struct Graph* graph, int source, int data, int weight){

    //add edge from source to data
    struct Node* newNode1 = newNode(data, weight);
    newNode1->next = graph->array[source].start;
    graph->array[source].start = newNode1;

    //add edge from data to source
    newNode1=newNode(source,weight);
    newNode1->next = graph->array[data].start;
    graph->array[data].start = newNode1;
}

int main(){
    int Vertex=12;
    struct Graph* graph = makeGraph(Vertex);
    newEdge(graph,0,1,1);
    newEdge(graph,1,2,2);
    newEdge(graph,1,3,2);
    newEdge(graph,2,4,3);
    newEdge(graph,2,5,2);
    newEdge(graph,3,6,2);
    newEdge(graph,5,7,1);
    newEdge(graph,5,9,4);
    newEdge(graph,6,9,1);
    newEdge(graph,6,11,3);
    newEdge(graph,6,10,2);
    newEdge(graph,9,8,2);
    newEdge(graph,9,11,5);
    newEdge(graph,8,10,11);
}
