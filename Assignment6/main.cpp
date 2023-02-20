/*
Ken Michna
CS260 
Assignment 6

*/

#include <iostream>

using namespace std;

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
};


TreeNode tree_Insert(int a_value, TreeNode *topNode){
    TreeNode newNode{a_value, nullptr, nullptr};
    if(a_value <= topNode->value && topNode->left != nullptr){
        cout<<"left loop "<<a_value<<endl;
        tree_Insert(a_value, topNode->left);
    }else if(a_value > topNode->value && topNode->right != nullptr){
        cout<<"right loop "<<a_value<<endl;
        tree_Insert(a_value, topNode->right);
    }else{
        if(a_value <= topNode->value){
            topNode->left = &newNode;
            cout<<"left "<<a_value<<endl;
            return newNode;
        }else{
            topNode->right = &newNode;
            cout<<"right "<<a_value<<endl;
            return newNode;
        }
    }
}

// Me trying to do cool recursion stuff.
// Return a pointer to the node holding the value being searched for. Returns nullptr if value not found.
TreeNode* treeSearch(int a_value, TreeNode *topNode){
    int branchLvl = 1;
    if (topNode->value == a_value){
        cout<<a_value<<" found at level "<<branchLvl<<endl;
        return topNode;
    }else if(a_value < topNode->value && topNode->left != nullptr){
        treeSearch(a_value, topNode->left);
    }else if(a_value > topNode->value && topNode->right != nullptr){
        treeSearch(a_value, topNode->right);
    }else{
        cout<<a_value<<" not found"<<endl;
        return nullptr;
    }

}

//Josephs in-Order Traversal Code.
void inOrderTraversal(TreeNode *current) {
    //inOrderTraversal of left child, if it exists
    if(current->left != nullptr) {
        inOrderTraversal(current->left);
    }
    //print value of self
    cout << current->value << ", ";
    //inOrderTraversal of right child, if it exists
    if(current->right != nullptr) {
        inOrderTraversal(current->right);
    }
}

// Oh my goodness is this MORE recursion?? whoa =O
TreeNode *getPriorNode(int a_value, TreeNode *topNode){
    if((*topNode->right).value == a_value || (*topNode->left).value == a_value){
        return topNode;
    }else if(a_value > topNode->value){
        getPriorNode(a_value, topNode->right);
    }else{
        getPriorNode(a_value, topNode->left);
    }

}

void removeValue(int a_value, TreeNode *topNode){
    // Get a pointer to the Node holding the value.
    TreeNode *nodeHoldingValuePtr = treeSearch(a_value, topNode);

    //First IF statement handles right branch adjustments. 2nd handles Left branch.
    if(nodeHoldingValuePtr != nullptr && nodeHoldingValuePtr->value > topNode->value){
        // Get a ptr to the Node before it
        TreeNode *rPriorNode = getPriorNode(a_value, nodeHoldingValuePtr);
        // Right branch moves up to removed node's place. Point the node above the removed node to where removed node USED to point.
        rPriorNode->right = nodeHoldingValuePtr->right;
        // Transfer pointers from removed node to the node that moved up to replace it.
        (*nodeHoldingValuePtr->right).left = nodeHoldingValuePtr->left;
        delete nodeHoldingValuePtr; // <--------Ask Joseph about this. Want to delte node itself not just its ptr*********************

    //Left branch adjustments
    }else if(nodeHoldingValuePtr != nullptr && nodeHoldingValuePtr->value < topNode->value){
        TreeNode *lPriorNode = getPriorNode(a_value, nodeHoldingValuePtr);
        (*nodeHoldingValuePtr->right).left = nodeHoldingValuePtr->left;
        lPriorNode->left = nodeHoldingValuePtr->right;
    }else{
        cout<<"Value not found in tree"<<endl;
    }

}

int main(){
    TreeNode aBinTree = TreeNode {20, nullptr, nullptr};
    TreeNode *treePtr = &aBinTree;

    //cout<<aBinTree.value<<endl;

    tree_Insert(10, treePtr);
    cout<<(*treePtr->left).value<<endl;
    tree_Insert(7, treePtr);
    cout<<(*(*treePtr->left).left).value<<endl;
    tree_Insert(11, treePtr);
    cout<<(*(*treePtr->left).right).value<<endl;
    tree_Insert(30, treePtr);
    cout<<(*treePtr->right).value<<endl;
    cout<<(*treePtr->left).value<<endl;
    tree_Insert(25, treePtr);
    tree_Insert(35, treePtr);
    tree_Insert(5, treePtr);
    tree_Insert(23, treePtr);
    tree_Insert(27, treePtr);
    tree_Insert(40, treePtr);
    tree_Insert(4, treePtr);
    tree_Insert(6, treePtr);

    //cout<<treePtr->value<<endl;
    

    return 0;
}

