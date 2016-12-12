//start of header guard
#ifndef GRAPH_H
#define GRAPH_H

//create node structure
struct Node{
    char data; //node name eg A,B,C
    int weight; //weight of edge
    bool visited=false;
    struct Node* next; //pointer to next node in list
};

//create list structure
struct List{
    struct Node *start; //pointer to start point of list
};

//create graph structure
struct Graph{
        int Vertex; //number of vertices in the graph
        struct List* array; //array of lists to make the graph
};

//end of header guard
#endif

