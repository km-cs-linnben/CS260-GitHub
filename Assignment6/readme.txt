Ken Michna
Assignment 6 
CS260

BigO Complexity:
For my insert function I believe the BigO would be a worst case of n/2 because at its worst the function would only go through and touch each node on only one half of the tree.

The remove function I believe would be similar, but n/2+2 (is that allowed?) because at worst it would also touch each node on one half of the tree and the 2 other if it needs
to rearrange the tree after removal.The remove function itself really only touches 1-3 nodes but my getPriorNode function that the remove function uses would still touch half
the tree in a worst case.

1.)Nodes to store values,


2.)An add function that adds a new value in the appropriate location based on our ordering rules,
(I likely used less than or equal to going to the left and greater than values going to the right)

3.)A remove function that finds and removes a value and then picks an appropriate replacement node