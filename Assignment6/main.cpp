/*
Ken Michna
CS260 
Assignment 6

*/

//Why does git put everything under assignmnet 1 branch when I push this ************************

#include <iostream>

using namespace std;

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
};


TreeNode *tree_Insert(int a_value, TreeNode *topNode){

    if(a_value <= topNode->value && topNode->left != nullptr){
        cout<<"left loop "<<a_value<<"    comp value-> "<<topNode->value<<endl;
        tree_Insert(a_value, topNode->left);

    }else if(a_value > topNode->value && topNode->right != nullptr){
        cout<<"right loop "<<a_value<<"    comp value-> "<<topNode->value<<endl;
        tree_Insert(a_value, topNode->right);

    }else{    //Doesnt create a new node until final left/right decision
        TreeNode *newNode = new TreeNode{a_value, nullptr, nullptr};
        if(a_value < topNode->value){
            cout<<"left "<<a_value<<"    comp value-> "<<topNode->value<<endl;
            topNode->left = newNode;
            return newNode;

        }else{
            topNode->right = newNode;
            cout<<"right "<<a_value<<"    comp value-> "<<topNode->value<<endl;
            return newNode;
        }
    }
}

// Me trying to do cool recursion stuff.
// Return a pointer to the node holding the value being searched for. Returns nullptr if value not found.
TreeNode* treeSearch(int a_value, TreeNode *topNode){
    static int branchLvl = 0;
    branchLvl++;
    if (topNode->value == a_value){
        cout<<a_value<<" found at level "<<branchLvl<<endl;
        branchLvl = 0;
        return topNode;
    }else if(a_value < topNode->value && topNode->left != nullptr){
        //branchLvl++;
        treeSearch(a_value, topNode->left);
    }else if(a_value > topNode->value && topNode->right != nullptr){
        //branchLvl++;
        treeSearch(a_value, topNode->right);
    }else{
        cout<<a_value<<" not found."<<endl;
        cout<<"Searched "<<branchLvl<<" branches."<<endl;
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
    //cout<<(*treePtr->left).value<<endl;
    tree_Insert(7, treePtr);
    //cout<<(*(*treePtr->left).left).value<<endl;
    tree_Insert(11, treePtr);
    //cout<<(*(*treePtr->left).right).value<<endl;
    tree_Insert(30, treePtr);
    //cout<<(*treePtr->right).value<<endl;
    //cout<<(*treePtr->left).value<<endl;
    tree_Insert(25, treePtr);
    tree_Insert(35, treePtr);
    tree_Insert(5, treePtr);
    tree_Insert(23, treePtr);
    tree_Insert(27, treePtr);
    tree_Insert(40, treePtr);
    tree_Insert(4, treePtr);
    tree_Insert(6, treePtr);

    treeSearch(40, treePtr);
    treeSearch(11, treePtr);
    treeSearch(6, treePtr);
    

    return 0;
}

