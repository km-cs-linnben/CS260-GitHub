#pragma once

#include <iostream>
#include <string>

//#include "nodes.h"

using namespace std;

class Graph {
    public:
        bool addNode(string systemname, int numplanets, int fuel);
        bool addEdge(string source, string destination, int cost);
        // bool removeNode(string name);
        // bool removeEdge(string source, string destination);

        // bool nodeExists(string name);
        // bool edgeExists(string source, string destination);
        // string shortestPath(string name); // single-source shortest path
        // string minimumSpanningTree();

        vector<SolarSystemNode> systems_in_graph;
        vector<HyperLane> lanes_in_graph;
};