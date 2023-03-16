/*
Ken Michna
CS260 Final Project

Graph of different solar systems with hyperlanes between. Solar system nodes contain
a number of planets and the systems fuel production capabilities. Edges contain origin, 
destination, and distance in lightyears.

*/
#include "nodes.h"
#include "f_edges.h"
#include "graph.h"
#include "graph_funcs.h"

using namespace std;

main(){
    Graph Spacegraph;
    Spacegraph.addNode("Sol", 8, 100);
    Spacegraph.addNode("Zeta Reticuli", 0, 0);
    Spacegraph.addNode("Mandalore", 3, 200);

    for(int i = 0; i < Spacegraph.systems_in_graph.capacity(); ++i){
        cout<<Spacegraph.systems_in_graph[i].name<<endl;
    };

    Spacegraph.addEdge("Sol", "Zeta Reticuli", 100);
    // HyperLane testlane = HyperLane(&Spacegraph.systems_in_graph[1], &Spacegraph.systems_in_graph[2]);
    // HyperLane testlane2;
    // testlane2.origin = &Spacegraph.systems_in_graph[0];
    // testlane2.destination = &Spacegraph.systems_in_graph[1];

    // cout<<(*testlane.origin).name<<endl;
    // cout<<(*testlane.destination).name<<endl;

    cout<<endl<<(*Spacegraph.lanes_in_graph[0].origin).name<<endl;
    cout<<endl<<(*Spacegraph.lanes_in_graph[0].destination).name<<endl;
    cout<<endl<<Spacegraph.lanes_in_graph[0].lightyears<<endl;
};