// Functions for assignment 6

#include <iostream>
#include "a6_strucs.h"

using namespace std;

TreeNode *tree_Insert(int a_value, TreeNode *topNode){

    if(a_value <= topNode->value && topNode->left != nullptr){
        //cout<<"left loop "<<a_value<<"    comp value-> "<<topNode->value<<endl;
        tree_Insert(a_value, topNode->left);

    }else if(a_value > topNode->value && topNode->right != nullptr){
        //cout<<"right loop "<<a_value<<"    comp value-> "<<topNode->value<<endl;
        tree_Insert(a_value, topNode->right);

    }else{    //Doesnt create a new node until final left/right decision
        TreeNode *newNode = new TreeNode{a_value, nullptr, nullptr};
        if(a_value < topNode->value){
            //cout<<"left "<<a_value<<"    comp value-> "<<topNode->value<<endl;
            topNode->left = newNode;
            return newNode;

        }else{
            topNode->right = newNode;
            //cout<<"right "<<a_value<<"    comp value-> "<<topNode->value<<endl;
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
        treeSearch(a_value, topNode->left);
    }else if(a_value > topNode->value && topNode->right != nullptr){
        treeSearch(a_value, topNode->right);
    }else{
        cout<<a_value<<" not found."<<endl;
        cout<<"Searched "<<branchLvl<<" branches."<<endl;
        branchLvl = 0;
        return nullptr;
    }

}

//Josephs in-Order Traversal Code.
void inOrderTraversal(TreeNode *topNode) {
    //inOrderTraversal of left child, if it exists
    if(topNode->left != nullptr) {
        inOrderTraversal(topNode->left);
    }
    //print value of self
    cout << topNode->value << ", ";
    //inOrderTraversal of right child, if it exists
    if(topNode->right != nullptr) {
        inOrderTraversal(topNode->right);
    }
}

// Post Order Traversal
void postOrderTraversal(TreeNode *topNode){
    if(topNode->left != nullptr){
        postOrderTraversal(topNode->left);
    }else if(topNode->right == nullptr){
        cout << topNode->value << ", ";
    }
    if(topNode->right != nullptr){
        postOrderTraversal(topNode->right);
    }
    if(topNode->left != nullptr || topNode->right != nullptr){
        cout<<topNode->value<<", ";
    }    
}

// Returns the prior node for use in other functions. Super convoluted and messy
// but it works.
TreeNode *getPriorNode(int a_value, TreeNode *topNode){
    if(topNode->right == nullptr || topNode->left == nullptr){
        // Had to add this extra if/else branch because program broke if a_value was compared to a null
        // pointer in any way whatsoever.
        //cout<<"null"<<endl;
        if(topNode->left == nullptr){
            if((*topNode->right).value == a_value){
                cout<<"Prior Node of "<<a_value<<": "<<topNode->value<<endl;
                return topNode;
            //cout<<"null- going right"<<endl;
            getPriorNode(a_value, topNode->right);
            }
        }else if (topNode->right == nullptr){
            if((*topNode->left).value == a_value){
                cout<<"Prior Node of "<<a_value<<": "<<topNode->value<<endl;
                return topNode;
            }
            //cout<<"null- going left"<<(*topNode->left).value<<endl;
            getPriorNode(a_value, topNode->left);
        }else{
            cout<<topNode->value<<" Not found"<<endl;
        }

    }else if(a_value == (*topNode->left).value || a_value == (*topNode->right).value){
        cout<<"Prior Node of "<<a_value<<": "<<topNode->value<<endl;
        return topNode;
    }else if(a_value > topNode->value){
        //cout<<"goin right"<<endl;
        getPriorNode(a_value, topNode->right);
    }else if(a_value < topNode->value){
        //cout<<"goin left"<<endl;
        getPriorNode(a_value, topNode->left);
    }else{
        cout<<topNode->value<<" Not found"<<endl;
        return nullptr;
    }
}

void removeValue(int a_value, TreeNode *topNode){
    // Get a pointer to the Node holding the value.
    TreeNode *nodeHoldingValuePtr = treeSearch(a_value, topNode);

    //First IF statement handles right branch adjustments. 2nd handles Left branch.
    if(nodeHoldingValuePtr != nullptr && nodeHoldingValuePtr->value > topNode->value){
        //cout<<"remove right"<<endl;
        // Get a ptr to the Node before it
        TreeNode *rPriorNode = getPriorNode(a_value, topNode);
        if(nodeHoldingValuePtr->right == nullptr && nodeHoldingValuePtr->left == nullptr){
            rPriorNode->right = nullptr;
            rPriorNode->left = nullptr;
            cout<<a_value<<" removed from tree"<<endl;
        }else if(nodeHoldingValuePtr->left == nullptr && nodeHoldingValuePtr->right != nullptr){
            rPriorNode->left = nullptr;
            rPriorNode->right = nodeHoldingValuePtr->right;
            cout<<a_value<<" removed from tree"<<endl;
        }else if(nodeHoldingValuePtr->right == nullptr && nodeHoldingValuePtr->left != nullptr){
            rPriorNode->right = nullptr;
            rPriorNode->left = nodeHoldingValuePtr->left;
            cout<<a_value<<" removed from tree"<<endl;
        }else{
            // Right branch moves up to removed node's place. Point the node above the removed node to where removed node USED to point.
            rPriorNode->right = nodeHoldingValuePtr->right;
            // Transfer pointers from removed node to the node that moved up to replace it.
            (*nodeHoldingValuePtr->right).left = nodeHoldingValuePtr->left;
            cout<<a_value<<" removed from tree"<<endl;
        }
        delete nodeHoldingValuePtr; // <--------Ask Joseph about this. Want to delete node itself not just its ptr*********************

    //Left branch adjustments
    }else if(nodeHoldingValuePtr != nullptr && nodeHoldingValuePtr->value < topNode->value){
        //cout<<"remove left"<<endl;
        TreeNode *lPriorNode = getPriorNode(a_value, topNode);
        if(nodeHoldingValuePtr->right == nullptr && nodeHoldingValuePtr->left == nullptr){
            lPriorNode->left = nullptr;
            lPriorNode->right = nullptr;
            cout<<a_value<<" removed from tree"<<endl;
        }else if(nodeHoldingValuePtr->left == nullptr && nodeHoldingValuePtr->right != nullptr){
            lPriorNode->left = nullptr;
            lPriorNode->right = nodeHoldingValuePtr->right;
            cout<<a_value<<" removed from tree"<<endl;
        }else if(nodeHoldingValuePtr->right == nullptr && nodeHoldingValuePtr->left != nullptr){
            lPriorNode->right = nullptr;
            lPriorNode->left = nodeHoldingValuePtr->left;
            cout<<a_value<<" removed from tree"<<endl;
        }else{
            (*nodeHoldingValuePtr->right).left = nodeHoldingValuePtr->left;
            lPriorNode->left = nodeHoldingValuePtr->right;
            cout<<a_value<<" removed from tree"<<endl;
        }
        delete nodeHoldingValuePtr;
    }else{
        cout<<"Value not found in tree"<<endl;
    }

}