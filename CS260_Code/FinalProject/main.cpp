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

    Spacegraph.addEdge("Sol", "Zeta Reticuli", 110);
    Spacegraph.addEdge("Sol", "Mandalore", 50);
    Spacegraph.addEdge("Mandalore", "Gliese", 200);
    Spacegraph.addEdge("Gliese", "Miezer", 75);
    Spacegraph.addEdge("Mandalore", "Miezer", 100);


    cout<<Spacegraph.lanes_in_graph.size()<<endl;
    cout<<endl<<"List of Edges: "<<endl;
    for(int i = 0; i < Spacegraph.lanes_in_graph.size(); ++i){
        cout<<"Origin: "<<(*Spacegraph.lanes_in_graph[i].origin).name<<endl;
        cout<<"Dest: "<<(*Spacegraph.lanes_in_graph[i].destination).name<<endl;
        cout<<"Distance: "<<Spacegraph.lanes_in_graph[i].lightyears<<endl;
    };


    Spacegraph.shortestPath(Spacegraph.systems_in_graph[0]);

    cout<<endl<<"Shortest Path Function Visited Systems In Order Visited: "<<endl;
    for(int i = 0; i < Spacegraph.visited.size(); ++i){
        cout<<Spacegraph.visited[i]<<endl;
    }

    cout<<endl<<"Shortest Path Tree: "<<endl;
    for(int i = 0; i < Spacegraph.lanesVisistedInOrder.size(); ++i){
        cout<<(*Spacegraph.lanesVisistedInOrder[i].origin).name<<" to "<<(*Spacegraph.lanesVisistedInOrder[i].destination).name<<" -- Lightyears: "<<Spacegraph.lanesVisistedInOrder[i].lightyears<<endl;
    }
};