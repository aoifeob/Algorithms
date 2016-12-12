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

bool dfs(Graph* graph, char start_at, char find_value){
    for (int i=0;i<12;i++){
           
    }
          
        if (start_at==find_value){
            return 1;
        }
       else{
            if ("start at hasn't been visited"){   
                //mark it visited
                for ("all nodes connected to it"){
                    if ("specific node hasn't been visited"){
                        dfs(mygraph, specificNode, find_value);//visit it   
                    }
                }
            }
       }
}

int main(){
    int Vertex=12;
    struct Graph* mygraph = makeGraph(Vertex);
    newEdge(mygraph,0,1,1);
    newEdge(mygraph,1,2,2);
    newEdge(mygraph,1,3,2);
    newEdge(mygraph,2,4,3);
    newEdge(mygraph,2,5,2);
    newEdge(mygraph,3,6,2);
    newEdge(mygraph,5,7,1);
    newEdge(mygraph,5,9,4);
    newEdge(mygraph,6,9,1);
    newEdge(mygraph,6,11,3);
    newEdge(mygraph,6,10,2);
    newEdge(mygraph,9,8,2);
    newEdge(mygraph,9,11,5);
    newEdge(mygraph,8,10,11);
    
    dfs(mygraph, 0, 23);
    dfs(mygraph, 10, 1)
    
    free(Graph);
    free(List);
    free(Node);
}
