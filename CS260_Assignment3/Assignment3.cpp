/* 
Ken Michna
Assignment 3

Queuing now works!
DeQ works

Could make DeQ better if I rewrote entire program, but this took long enough.
Making progress...

*/

#include <iostream>
#include <cstdlib>

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
Node *enqueue(Node *node_N_front, int newvalue, Node *tail){
    Node *new_node_ptr = new Node(newvalue, tail);
    node_N_front->next = new_node_ptr;

    return new_node_ptr;
}

//First node's next ptr is saved to a ptr called next node in q. First nodes pointer is then deleted.
// returns pointer to next node in queue.
Node *deQ(Node *head_ptr, Node *next_node){
    //create new pointer aiming at the removed nodes next node in line.
    head_ptr = next_node;
    
    return head_ptr;
}

int peek(Node *last_node){
    if (last_node->next != 0){
        cout << "You can only peek at the end value" <<endl;
    }
    else{
        int tail_value = last_node->value;
        return tail_value;
    }

}


int main(){
    //***WHAT IS THIS DOING SPECIFICALLY? Creating a new node? or purely a pointer?
    Node *tail_ptr = nullptr;

    //create an intial node to make my functions work right.
    Node initial_node(80, tail_ptr);
    Node *head = &initial_node;
    cout << "Initial Node's value address: " << &initial_node.value <<endl;
    cout << "Initial Node's next address: " << &initial_node.next <<endl;
    cout << "Initial Node's next value: " << initial_node.next <<endl;
    cout << "Head pointing to: " << head <<endl; 
    cout << "Head pointing to value: " << head->value <<endl;

    //test1 is a node with value 113 entered into end of line
    Node *test1 = enqueue(&initial_node, 113, tail_ptr);

    //this prints the node's value that test1 is pointing to and then where that node is pointing to (should be the tail)
    cout << "test1 value: " << test1->value << endl;
    cout << "test1 next: " << test1->next << endl;

    //test2 is a node of value 42 placed end of line
    Node *test2 = enqueue(test1, 42, tail_ptr);
    cout << "test2 value: " << test2->value << endl;
    cout << "test2 next ptr: " << test2->next << endl;

    cout << "whats behind test1 in line after adding test2: " << test1->next << endl;
    cout << "test2 address: " << &test2->value << endl;

    Node *test3 = enqueue(test2, 134, tail_ptr);
    cout << "test3 value: " << test3->value << endl;
    cout << "test3 next ptr: " << test3->next << endl;

    cout << "whats behind test2 in line after adding test3: " << test2->next << endl;
    cout << "test3 address: " << &test3->value << endl;

    //deQ points head to next node in list.
    head = deQ(head,test1);
    cout << "head pointing to: " << head << endl;
    cout << "test1 address: " << test1 <<endl;

    int peek_test = peek(test2);
    cout << "peek_test: " << peek_test << endl;

    int peek_test2 = peek(test3);
    cout << "peek_test2: " << peek_test2 << endl;


    //Node *ptr = new Node();
    //ptr->value = 113;
    //ptr->next = nullptr;
    //head = ptr;
    

    return 0;
}