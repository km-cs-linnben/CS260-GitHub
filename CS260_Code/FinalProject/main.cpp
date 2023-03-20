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
    Spacegraph.addNode("Gliese", 4, 150);
    Spacegraph.addNode("Miezer", 0, 0);

    for(int i = 0; i < Spacegraph.systems_in_graph.capacity(); ++i){
        cout<<Spacegraph.systems_in_graph[i].name<<endl;
    };

    Spacegraph.addEdge("Sol", "Zeta Reticuli", 100);
    Spacegraph.addEdge("Sol", "Mandalore", 50);
    Spacegraph.addEdge("Mandalore", "Gliese", 200);
    Spacegraph.addEdge("Gliese", "Miezer", 75);
    Spacegraph.addEdge("Mandalore", "Miezer", 100);
    // HyperLane testlane = HyperLane(&Spacegraph.systems_in_graph[1], &Spacegraph.systems_in_graph[2]);
    // HyperLane testlane2;
    // testlane2.origin = &Spacegraph.systems_in_graph[0];
    // testlane2.destination = &Spacegraph.systems_in_graph[1];

    // cout<<(*testlane.origin).name<<endl;
    // cout<<(*testlane.destination).name<<endl;

    // cout<<endl<<(*Spacegraph.lanes_in_graph[0].origin).name<<endl;
    // cout<<endl<<(*Spacegraph.lanes_in_graph[0].destination).name<<endl;
    // cout<<endl<<Spacegraph.lanes_in_graph[0].lightyears<<endl;

    cout<<Spacegraph.lanes_in_graph.size()<<endl;
    cout<<endl<<"List of Edges: "<<endl;
    for(int i = 0; i < Spacegraph.lanes_in_graph.size(); ++i){
        cout<<"Origin: "<<(*Spacegraph.lanes_in_graph[i].origin).name<<endl;
        cout<<"Dest: "<<(*Spacegraph.lanes_in_graph[i].destination).name<<endl;
        cout<<"Distance: "<<Spacegraph.lanes_in_graph[i].lightyears<<endl;
    };

    //Spacegraph.minSpanHelper(Spacegraph.systems_in_graph[0]);

    // for(int i = 0; i < Spacegraph.minSpanTree.capacity(); ++i){
    //     cout<<Spacegraph.minSpanTree[i].name;
    // }

    cout<<endl<<"Sol connected systems: ";
    for(int i = 0; i < Spacegraph.systems_in_graph[0].connectedLanes.capacity(); ++i){
        cout<<Spacegraph.systems_in_graph[0].connectedLanes[i].destination->name<<endl;
    }

    Spacegraph.shortestPath(Spacegraph.systems_in_graph[0]);

    cout<<endl<<"Visited: "<<endl;
    for(int i = 0; i < Spacegraph.visited.capacity(); ++i){
        cout<<Spacegraph.visited[i]<<endl;
    }
};