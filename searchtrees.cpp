/*
Tree visualisation:

                      |110|
                   /        \
                 |73|       |115|
               /      \    /     \
            |46|    |90|  |112|  |126|

*/


#include "treenode.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Tree_Node* root; //gobal variable root

//inserts a new node in the appropriate position
void tree_insert( Tree_Node* root, char data){

    //if the tree is empty, create a node at the root
    //otherwise, identify whether the node should be created to the left of right of the root
    //recurse until an appropriate place is found to insert the new node

    if (root == NULL){ //if the tree is empty
        root = new Tree_Node; //create the new node
        root->data = data;
        root->left = NULL;
        root->right=NULL;
    }
    else {
        if (data <= root->data){
            //if new node is to be inserted to the left
            if (root->left != NULL){
                //if a left child exists, recurse
                tree_insert(root->left, data);
            }
            else{
                //if no left child exists, create the new node as a left child
                root->left = new Tree_Node;
                root = root->left;
                root->data = data;
                root->left = NULL;
                root->right = NULL;
            }
        }
        else if(data > root->data){
            //similar to previous else if, but considering the right side instead of the left
            if (root->right != NULL){
                tree_insert(root->right, data);
            }
            else{
                root->right = new Tree_Node;
                root = root->right;
                root->data = data;
                root->left = NULL;
                root->right = NULL;
            }
        }
    }

}


void tree_delete(Tree_Node* root){

    //uses recursion to delete children first and then to delete parent nodes

    if (root == NULL){
        return;
    } //if node is empty, start again
    //delete children
    tree_delete(root->left);
    tree_delete(root->right);
    //
    if (root->left==NULL && root->right==NULL){ //if node has no children, delete it
        free(root); //free allocated memory
    }

}

//in-order tree traversal with printed results
void tree_print_sorted(Tree_Node* root){
    //for in order traversal, travel in the order left>root>right
    //use recursion to go as far left as possible, print the result in that node
    if (root!=NULL){
        tree_print_sorted(root->left);
        cout<< root->data;
        cout<<" /n";
        tree_print_sorted(root->right);
    }
}

int main(){
    //create a pointer to represent the root
    Tree_Node* root = (Tree_Node*)malloc(sizeof(Tree_Node));
    root = NULL;
    tree_insert(root, 110);
    tree_insert(root, 73);
    tree_insert(root, 115);
    tree_insert(root, 90);
    tree_insert(root, 46);
    tree_insert(root, 126);
    tree_insert(root, 112);
    tree_print_sorted(root);
    tree_delete(root);
    return 0;
}

