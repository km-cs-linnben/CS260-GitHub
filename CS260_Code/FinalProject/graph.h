#pragma once

#include <iostream>
#include <string>

//#include "nodes.h"

using namespace std;

class Graph {
    public:
        bool addNode(string systemname, int numplanets, int fuel);
        bool addEdge(string source, string destination, int cost);
        //bool removeNode(string name);
        int nodeSearch(string sysname);
        //int edgeSearch(string sysname);
        //bool removeEdge(string source, string destination);
        void shortestPath(SolarSystemNode system); // single-source shortest path
        //string minimumSpanningTree(Graph graphName);
        void minSpanHelper(SolarSystemNode system);

        vector<SolarSystemNode> systems_in_graph;
        vector<HyperLane> lanes_in_graph;
        // Had to add a string type visited list made of the names of the systems because find() would not work with a vector of SolarSystemNodes
        vector<string> visited;
        vector<SolarSystemNode> visitedNodes;
        vector<SolarSystemNode> sysqueue;
        vector<SolarSystemNode> minSpanTree;
        vector<string> minSpanNames;
        vector<HyperLane> lanesVisistedInOrder;
};