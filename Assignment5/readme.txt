Create an array-based list or a linked-list (and a bonus for attempting both) that:

1.)Automatically inserts values in the correct position based on some order of sorting (perhaps ascending integers or lexicographical sorting of words)

Lines 13-23

2.)Efficiently searches for elements (likely binary search for the array list, but what about the linked-list?)

Lines 33-91 For all my different search functions. There is a lot, sorry. I was trying stuff out.
Lines 63-91 for more efficient binary search.

All search functions have a way to count steps for Big O counts, which I print out.
For all of my search functions besides binary, the Big O is just N for worst case. If the value searched for is at the very end of the array that would be worst case.
Otherwise Big O will be better than n depending on the values location in the list.

For Binary search, Big O would be log(n). For an array of 20, worst case would be 5. The worst case only increases after the array size is increased to 50.
It takes an exponential increase in array size before the Big O's worst case increases by 1. I added a statement to my binary search that checks the end and middle
values as well as the middle. I believe that would make it faster but not sure. Would like your feedback on that.
