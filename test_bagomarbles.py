"""
Ken Michna
CS260

Test file for bag of marbles assignment
"""
from Bag_of_Marbles import *

def test_create_marble():
    """Test for create marble function. Using True creates a default marble and bypasses menu."""
    test_marble = create_marble(True)
    free_Marbles.append(test_marble)
    free_Marbles.append(test_marble)
    #print(free_Marbles)
    assert len(free_Marbles) == 2

def test_add_marble():
    """Test for add marble function."""
    test_marble = create_marble(True)
    free_Marbles.append(test_marble)
    add_marble(test_marble)
    #print(len(bag_O_Marbles))
    assert len(bag_O_Marbles) == 1
    bag_O_Marbles.remove(test_marble)

def test_remove_marble():
    """Test for remove marble function."""
    test_marble = create_marble(True)
    bag_O_Marbles.append(test_marble)
    remove_marble(test_marble)
    #print(len(bag_O_Marbles))
    assert len(bag_O_Marbles) == 0

# test_add_marble()
#test_remove_marble()
# test_create_marble()