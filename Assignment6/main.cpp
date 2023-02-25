/*
Ken Michna
CS260 
Assignment 6

Tree Insert Works
Tree Search Works
Get Prior Node Works
In Order Traversal Works
Post Order Traversal Works (mostly)


I have become one with recursion


*/

//ASK JOSEPH *****Why does git put everything under assignmnet 1 branch when I push this >=( ************************

#include <iostream>

#include "a6_functions.h"

using namespace std;

int main(){
    TreeNode aBinTree = TreeNode {20, nullptr, nullptr};
    TreeNode *treePtr = &aBinTree;

    tree_Insert(10, treePtr);
    tree_Insert(7, treePtr);
    tree_Insert(11, treePtr);
    tree_Insert(30, treePtr);
    tree_Insert(25, treePtr);
    tree_Insert(35, treePtr);
    tree_Insert(5, treePtr);
    tree_Insert(23, treePtr);
    tree_Insert(27, treePtr);
    tree_Insert(40, treePtr);
    tree_Insert(4, treePtr);
    tree_Insert(6, treePtr);

    cout<<"Tree search function results: "<<endl;
    cout<<"Tree search 27"<<endl;
    treeSearch(27, treePtr);
    cout<<"Tree search 11"<<endl;
    treeSearch(11, treePtr);
    cout<<"Tree search 6"<<endl;
    treeSearch(6, treePtr);
    cout<<"Tree search 100"<<endl;
    treeSearch(100, treePtr);
    
    cout<<endl<<"Results of get prior node function"<<endl;
    cout<<"Get prior node of 23"<<endl;
    getPriorNode(23, treePtr);
    cout<<"Get prior node of 40"<<endl;
    getPriorNode(40, treePtr);
    cout<<"Get prior node of 11"<<endl;
    getPriorNode(11, treePtr);
    cout<<"Get prior node of 252"<<endl;
    getPriorNode(252, treePtr);

    cout<<endl<<"In Order traversal: "<<endl;
    inOrderTraversal(treePtr);
    cout<<endl<<"Post Order traversal: "<<endl;
    postOrderTraversal(treePtr);

    cout<<endl<<endl<<"Remove node function results: "<<endl;
    cout<<"Remove 30"<<endl;
    removeValue(30, treePtr);
    getPriorNode(35, treePtr);
    removeValue(25, treePtr);
    getPriorNode(27, treePtr);
    removeValue(5, treePtr);
    getPriorNode(4, treePtr);
    removeValue(7, treePtr);
    return 0;
}

