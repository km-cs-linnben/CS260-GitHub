Ken Michna
Assignment 7


Create a hashtable that resolves collisions by simply overwriting the old value with the new value, including at least:

https://github.com/km-cs-linnben/CS260-GitHub/blob/master/CS260_Code/Assignment7/a7hash.png

1.)Describe the way that you decide on hashing a value
(this can be simple or complex based on how interesting you find the topic)

https://github.com/km-cs-linnben/CS260-GitHub/blob/master/CS260_Code/Assignment7/a7hashfunc.png

2.)An insert function that places the value at the appropriate location based on its hash value

https://github.com/km-cs-linnben/CS260-GitHub/blob/master/CS260_Code/Assignment7/a7insert.png

3.)A contains function that returns whether the value is already in the hashtable

https://github.com/km-cs-linnben/CS260-GitHub/blob/master/CS260_Code/Assignment7/a7search.png

4.)(optional) A delete function that removes a value based on its hash and then returns that value…

https://github.com/km-cs-linnben/CS260-GitHub/blob/master/CS260_Code/Assignment7/a7remove.png

Then create a smarter hashtable (double hashing or chaining) including at least the same functions as the simple hashtable

See lines 86 and below in a7_funcs.h

Compare some information relating to collisions (frequency) and their effect on complexity (of insert and contains methods)

The simple hash table complexity would be 1 because collisions are simply written over, so looking up values would still be simple.

The chained hash table would be more complex depending on how many collisions we have. If all the data ended up on one line it would be
a bigO of n (n for number of items in the original list) for worst case, but if collisions were minimal it should still average out to bigO of 1.
My hash gives lots of collisions at the moment so my chain table would be worse than bigO of 1.
