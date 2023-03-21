Ken Michna
Final Project
CS260 

ALL SCREENSHOTS/SCANS ARE IN FINAL PROJECT FOLDER IN LINKED REPO
Apologies for some slopiness, my wedding is on finals week (DOH!) so I have been very limited in time. I try to clean things up usually, but I got this out right at the last min due to spending multiple entire days trying to get it to work in between wedding stuff. Spent more time on this than any other school project I
have ever done. But success! I got it done.

(20%) Create a design before you start coding that describes or shows how a graph structure could be used to store some kinds of data and solve some kind of problem (yes, this can be a game that needs a graph to represent a map!),
	See included scans. First 2 are what I designed and thought of for tests prior to coding. 3rd is some graphs I made up that I created with the program
	to use as a reference to make sure everything was working. Wanted to do a lot more fun stuff but c++ defeated me.

(20%) Create some tests (at least two for each piece of functionality) before you start coding...
	See scans. See screenshot minspantree for some printout tests showing everything works.

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
	Complexity of Big0 n(n + 2n_1) , n = number of nodes in graph, n_1 being number of lanes in graph. This function iterates through all of the lanes in the graph twice,
	and iterates through a list of visited nodes, which would be == to total number of nodes in the graph by the time the function finishes. It does both of these things
	for every single node in the graph. 

(15%) a function for a minimum spanning tree algorithm (example min_span_tree()).
	See screenshots MinSpanTree. Got it to work at the buzzer! Spent 3 days on this with no success and then solved it in 10 mins on my last try. Typical.
	Complexity would be BigO of n(n+n_1), n being number of nodes in graph, n_1 being number of edges. The function searches through all edges in the graph, but also
	iterates through the list called visited, which will be the same as n by the time the function finishes. The function runs once for every node in the graph, so 	these things will both be done n times.

(10%) Analyze the complexity of all of your graph behaviors (effectively a part of our documentation for grading purposes),
	See above.
