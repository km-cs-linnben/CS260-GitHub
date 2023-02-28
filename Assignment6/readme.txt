Ken Michna
Assignment 6 
CS260

BigO Complexity:
For my insert function I believe the BigO would be a worst case of n/2 because at its worst the function would only go through and touch each node on only one half of the tree.

The remove function I believe would be similar, but n/2+2 (is that allowed?) because at worst it would also touch each node on one half of the tree and the 2 other if it needs
to rearrange the tree after removal.The remove function itself really only touches 1-3 nodes but my getPriorNode function that the remove function uses would still touch half
the tree in a worst case.

I can't add screenshots anymore. I don't know why. It worked the first time I did it and now it does nothing.
1.)Nodes to store values,

See a6_strucs.h

2.)An add function that adds a new value in the appropriate location based on our ordering rules,

Line 6-29 in main.cpp

3.)A remove function that finds and removes a value and then picks an appropriate replacement node

Line 122-178 in main.cpp

4.) 1 bonus Postorder Traversal

Line 67-80
