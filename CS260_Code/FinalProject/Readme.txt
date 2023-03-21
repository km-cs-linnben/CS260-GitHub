Ken Michna
Final Project
CS260 

ALL SCREENSHOTS/SCANS ARE IN FINAL PROJECT FOLDER IN LINKED REPO

(20%) Create a design before you start coding that describes or shows how a graph structure could be used to store some kinds of data and solve some kind of problem (yes, this can be a game that needs a graph to represent a map!),
	See included scans. First 2 are what I designed and thought of for tests prior to coding. 3rd is some graphs I made up that I created with the program
	to use as a reference to make sure everything was working. Wanted to do a lot more fun stuff but c++ defeated me.

(20%) Create some tests (at least two for each piece of functionality) before you start coding...
	See scans.

(40%) Implement a graph class with at least (this category effectively combines implementation and specification, partly to emphasize getting the algorithms working!):
	See graph.h

(5%) a function to add a new vertex to the graph (perhaps add_vertex(vertex_name)),
	See screenshot AddNode&AddEdge.
	Complexity BigO of 1. There is no searching or iterating being done, just 1 simple node creation and pushback into a list.

(5%) a function to add a new edge between two vertices of the graph (perhaps add_edge(source, destination) or source.add_edge(destination)),
	See screenshot AddNode&AddEdge.
	Complexity of Big0 2n. For the AddEdge function my node search function is used twice, of which iterates through every node in the graph to search for the inputted node. NodeSearch
	does break off when the node is found, but in a worst case scenario every node would be touched twice. I have read that constants should be eliminated when doing BigO
	analysis but I feel that if my graph was huge, doubling it is a significant increase, so that is why I say 2n instead of just n. The remainder of the AddEdge function
	simply adds to a couple lists, which does not significantly add to complexity.

(15%) a function for a shortest path algorithm (perhaps shortest_path(source, destination)),
	See screenshot ShortestPath1 and 2.
	Complexity of Big0 n(n + 2n_1) . n = number of nodes in graph, n_1 being number of lanes in graph. This function iterates through all of the lanes in the graph twice,
	and iterates through a list of visited nodes, which would be == to total number of nodes in the graph by the time the function finishes. It does both of these things
	for every single node in the graph. 

(15%) a function for a minimum spanning tree algorithm (example min_span_tree()).
	See screenshot MinSpanTree. Functions does not work. Tried for several days and gave up, so turning it in as is. I know the theory fine and what needs
	to be done to make it work but I can't figure out the syntax I need for this function to work. I've laid it all out in a way that I feel like should work,
	but it doesn't. Tried a million things, but nothing worked. More C++ experience would have been helpful. Also ran out of time due to my own wedding being 
	finals week =X doh!

(10%) Analyze the complexity of all of your graph behaviors (effectively a part of our documentation for grading purposes),
	See above.
