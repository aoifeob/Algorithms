//start of header guard
#ifndef GRAPH_H
#define GRAPH_H

//create an adjacenecy linked list node structure
struct Node{
    char data; //node name eg A,B,C
    int weight; //weight of edge
    bool visited; //visited tracker for dfs
    struct Node* next; //pointer to next node in list
};

//create adjacency linked list structure
struct List{
    struct Node *start; //pointer to start point of list
    struct Node adj_list;
};

//create graph structure
struct Graph{
        int Vertex; //number of vertices in the graph
        struct List* array; //array of lists to make the graph
};

//create min heap node structure
struct HeapNode{
    int vertex; //vertex value of the node
    int distance; //weight of vertex
};

//create min heap structure
struct Heap{
    int num_heapNodes; //number of nodes in the heap
    int heap_capacity; //number of nodes the heap can contain
    int *position; //position of node within the heap
    struct HeapNode **array; //array of nodes
};

//end of header guard
#endif



