# CS260
Assignment #1
Bag of Marbles

1.) Some way of representing marbles (what makes up a marble in this program?)
I am thinking in amatuer Python for all of these questions. First I would create a class called Marble.
I would initialize various properties such as diameter, color, weight, etc. Perhaps a menu to let users select these attributes.

Lines 14-31.

2.) A way to add new marbles into the bag (how do we interact with marbles and add them into the bag?
I would create a list called bag_O_Marbles. Maybe another list called free_Marbles. I would have a menu/function that lets users create various marbles using the Marble class and assigning each created Marble a different variable name (ex: red_1inch_marble, blue_halfinch_marble).

Lines 21-41  Menu on Lines 53-121.

3.) A way to remove a marble out of the bag (perhaps a random marble taken out of the bag?
I would have another function to add the created marble to the list bag_O_Marbles, and another to delete them from the list. Once deleted they would be added to the list free_marbles. I could import the random module and use that in a seperate function that would choose a random index in the bag_O_marbles list to be deleted.

Lines 43-51, Did not end up doing random stuff because time.

4.) A few ways that we could use to show that our implementation should be working correctly (tests)
(full admission, I thought of these AFTER I wrote the program) I wrote a couple tests to make sure the create, add, and remove functions of my main program work. For the creation test I made a marble using the create function and added it to the free marbles list twice. I then checked if the length of the free marbles was 2. For the add marble function I created a marble and then ran the add_marble function on that marble. Then I checked that the number of marbles in the bag equaled one. I did the same for the remove function, instead checking that the number of marbels in the bag now equaled 0.

See test_bagofmarbles.py
