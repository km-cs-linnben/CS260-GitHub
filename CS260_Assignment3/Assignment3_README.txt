Ken Michna
Assignment 3 Readme

This took me many MANY hours. Can we go back to python? (just kidding)(kind of)...

From my understanding of Big O notation, none of my functions would go past Big 0 of 1.

Lines 19-29 create a node class and constructer.

Lines 32-37 are my enqueue function. It takes in 3 arguments, the node that we are placing the new node behind,
	the desired value of the new node, and a pointer which will always be the tail pointer. It returns the
	pointer aiming at the newly created node.

Lines 41-46 are my dequeue function. It takes in 2 arguments, the head pointer and the pointer aiming at the
	next node in the list behind the one being dequeued. This part I could have done better (I think) if I
	rewrote a lot of my program to use variables assigned to nodes instead of pointers assigned to nodes.

Lines 48-57 are my peek function. It looks at the LAST node in the list and returns its value. If you attempt
	to peek at any other node it will not work.

Lines 68-106 are what I used for testing. Just lots of printouts to make sure everything was working as it should.

Could use lots of input verification and other things, but since this is my first exposure to c++ I am happy
to have gotten this far.
