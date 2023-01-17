"""
Ken Michna
CS260 Assignment 1
Bag of Marbles

I've typed marble so many times that the word sounds weird now.
"""

import random

bag_O_Marbles = []
free_Marbles = []

class Marble:

    def __init__(self, color = "clear", diameter = "13", weight = "4"):
        self.color = color
        self.diameter = diameter
        self.weight = weight

def create_marble(default = False):

    if default == True:
        marble = Marble()
        return marble
    else:
        color_list = ["blue", "green", "red", "clear"]
        diameter_list = [12, 13, 14, 15]
        weight_list = [3, 4, 5, 6]

        print(color_list)
        color = input("Choose a color from the list: ")
        print(diameter_list)
        diameter = str(input("Choose a diameter(mm) from the list: "))
        print(weight_list)
        weight = str(input("Choose a weight from the list: "))
        
        #marble_name = f"{color}_{diameter}mm_{weight}g"
        marble = Marble(color, diameter, weight)

        return marble

def add_marble(marble):
    """Adds the marble to bag of marbles."""
    free_Marbles.remove(marble)
    bag_O_Marbles.append(marble)

def remove_marble(marble):
    """Removes marble from bag and lets it free."""
    bag_O_Marbles.remove(marble)
    free_Marbles.append(marble)

def user_menu():

    loop = True
    while loop == True:
        print("Marble Menu: \n\
            1. Create Marble\n\
            2. Add a marble to the bag\n\
            3. Remove marble from bag\n\
            4. Print bag contents\n\
            5. Exit\n ")

        valid = True
        while valid == True:
            selection = input("What would you like to do? ")
            valid_selection_list = ["1","2","3","4","5"]
            #Do not pass if invalid entry
            if selection in valid_selection_list:
                #Calls functions depening on user selection

                if selection == "1":
                    free_Marbles.append(create_marble())
                    break

                elif selection == "2":
                    index = 1
                    for i in free_Marbles:
                        print(f"Marble {index}: {i.color}-{i.diameter}-{i.weight}")
                        index += 1
                    print("These are your marbles\n")
                    added_Marble = int(input("Which would you like to put in the bag?\n"))
                    added_Marble -= 1
                    print(len(free_Marbles))
                    if added_Marble >= 0 and added_Marble <= len(free_Marbles):
                        add_marble(free_Marbles[added_Marble])
                        print(f"Marble {added_Marble +1} added to bag.\n")
                    else:
                        print("That marble does not exist.\n")
                    break

                elif selection == "3":
                    index = 1
                    for i in bag_O_Marbles:
                        print(f"Marble {index}: {i.color}-{i.diameter}-{i.weight}")
                        index += 1
                    print("These are the marbles currently in the bag.\n")
                    removed_Marble = int(input("Which marble would you like to remove?\n"))
                    removed_Marble -= 1
                    if removed_Marble >= 0 and removed_Marble <= len(bag_O_Marbles):
                        remove_marble(bag_O_Marbles[removed_Marble])
                    break

                elif selection == "4":
                    if len(bag_O_Marbles) > 0:
                        for i in bag_O_Marbles:
                            print(f"{i.color}-{i.diameter}-{i.weight}")
                    else:
                        print("There are no marbles in your bag.")
                    break

                elif selection == "5":
                    loop = False
                    break
                
                else:
                    continue

            else:
                print("Inavlid Selection")
                valid = False
            
if __name__ == "__main__":

    user_menu()
