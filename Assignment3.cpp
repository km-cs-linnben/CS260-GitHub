#include <iostream>
#include <stdlib>

using namespace std;


class Node{
    public:
    int value;
    Node *next;

    Node (){}
    Node  (int newvalue, Node *nextnode){
        this->value = newvalue;
        this->next = nextnode;
    }
};

//Node is created with desired value and a pointer to the tail. Returns a pointer to this new node.
Node *enqueue(Node *node_in_fronts_ptr, int newvalue, Node *tail){
    Node *new_node_ptr = new Node(newvalue, tail);
    node_in_front_ptr.next = new_node_ptr;

    return new_node_ptr;
}

//First node in queue removed from front of queue, head ptr then points to where the removed node WAS pointing
Node deQ(Node node_removed, Node *head){
    head = node_removed.next;
    int popped_value = node_removed.value;
    delete node_removed;

    return popped_value;
}

int main(){
    //***WHAT IS THIS DOING SPECIFICALLY? Creating a new node? or purely a pointer?
    Node *head = nullptr;
    Node *tail = nullptr;

    //node2 is now a pointer to a node with value 113 whos ptr points to the tail of the linked list.
    Node node2 = enqueue(head, 113, tail);

    //node1 is a pointer to a node with value 42 whose ptr points to node2.
    Node node1 = enqueue(node2, 42, tail);

    cout << "Hello World" << endl;

    //Node *ptr = new Node();
    //ptr->value = 113;
    //ptr->next = nullptr;
    //head = ptr;


    return 0;
}
