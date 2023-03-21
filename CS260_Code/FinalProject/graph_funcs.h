// Functions for Graph class.
#pragma once

//#include "graph.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Graph::addNode(string sysname, int numplanets, int fuel){
    SolarSystemNode newNode(sysname, numplanets, fuel);
    systems_in_graph.push_back(newNode);
    return true;
}


bool Graph::addEdge(string source, string destination, int cost){
    int sIndex = nodeSearch(source);
    int dIndex = nodeSearch(destination);

    // If desired source and destination nodes do exist in the graph...
    // Creates new edge, sets origin ptr to address where source was found, does the same for dest ptr.
    // Adds newly created edge to the graph's list of edges.
    if(sIndex != 42 && dIndex != 42){
        cout<<"CHECK"<<endl;
        HyperLane newEdge;
        newEdge.origin = &systems_in_graph[sIndex];
        newEdge.destination = &systems_in_graph[dIndex];
        newEdge.lightyears = cost;
        lanes_in_graph.push_back(newEdge);
        //Make sure systems know they are connected to eachother
        systems_in_graph[sIndex].connectedSystems.push_back(systems_in_graph[dIndex]);
        systems_in_graph[dIndex].connectedSystems.push_back(systems_in_graph[sIndex]);
        systems_in_graph[sIndex].connectedLanes.push_back(newEdge);
        //systems_in_graph[dIndex].connectedLanes.push_back(newEdge);
        cout<<"LANE ADDED"<<endl;
        return true;
        }
    cout<<sIndex<<"  "<<dIndex<<endl;
    cout<<"FAIL "<<endl;
    return false;
}

// Fills in Min Spanning Tree Vector
void Graph::minSpanningTree(SolarSystemNode system){
    SolarSystemNode current;

    current = system;

    //This is just to add the first node to visited and not have current added to visited more than once
    if(&current == &systems_in_graph[0]){
        cout<<endl<<"Q Empty, current added to beginning";
        visited.push_back(current.name);
    }

    //Delete first position in queue if its not empty
    if(sysqueue.size() > 0){
        cout<<endl<<"First in Q deleted";
        // Printout test to check queue
        for(auto element: sysqueue){
            cout<<element.name<<" "<<endl;
        }
        sysqueue.erase(sysqueue.begin());
        // Another printout test
        cout<<"Q 0: "<<sysqueue[0].name<<endl;
    }

    // Add current to min span tree
    cout<<endl<<current.name<<" Pushed back of Tree";
    minSpanTree.push_back(current.name);

    // Go through all of current system's connected lanes and add their destination to the queue and to visited if not already there
    for(int i = 0; i < system.connectedLanes.size(); ++i){
        bool found = false;
        cout<<endl<<"Looking at "<<(*system.connectedLanes[i].origin).name<<" to "<<(*system.connectedLanes[i].destination).name<<endl;
        // Go through list of visited systems, if lane's destination matches anything in visited, do nothing and skip to next loop.
        if(find(visited.begin(), visited.end(), (*system.connectedLanes[i].destination).name) != visited.end()){continue;}
        // If lane's destination was NOT found, assign that destination system to list of visited systems and into queue
        visited.push_back((*system.connectedLanes[i].destination).name);
        sysqueue.push_back((*system.connectedLanes[i].destination));
    }

    //If queue is not empty, rerun func on next system in queue which should be at position 0 of queue
    if(!sysqueue.empty()){
        minSpanningTree(sysqueue[0]);
    }
    //If queue is empty, return and exit func
    return;
}


int Graph::nodeSearch(string sysname){

    for(int i =0; i <= systems_in_graph.capacity(); ++i){
        if(systems_in_graph[i].name == sysname){
            cout<<"FOUND "<<i<<endl;
            return i;
        }
    }
    cout<<sysname<<" Not Found"<<endl;
    return 42;
}


// Good luck reading this
// Finds shortest path that touches all nodes
void Graph::shortestPath(SolarSystemNode system){
    //Start with first node in graph as source
    systems_in_graph[0].distFromSource = 0;
    static SolarSystemNode closestNode;    //Static keeps variable from resetting every loop
    cout<<endl<<"Beg Func Closest Node: "<<closestNode.name<<endl;
    static int defaultDist = 1000;
    cout<<endl<<"DEFAULT DIST: "<<defaultDist<<endl;
    HyperLane lane2Closest;

    //For first loop only, gave up on elegant solutions. I'm so tired...
    if(defaultDist == 1000){
        visited.push_back(systems_in_graph[0].name);
        visitedNodes.push_back(systems_in_graph[0]);
        cout<<endl<<"D loop"<<endl;

        // Go through source's connected lanes
        for(int i = 0; i < systems_in_graph[0].connectedLanes.capacity(); ++i){
            //Update distance from source for only the systems that are adjacent to source.
            systems_in_graph[0].connectedLanes[i].destination->distFromSource = systems_in_graph[0].connectedLanes[i].lightyears;
            cout<<systems_in_graph[0].connectedLanes[i].destination->name<<" Distance from source: "<<systems_in_graph[0].connectedLanes[i].destination->distFromSource<<endl;

            // If destination system distance is less than default distance value, make it the new default distance and make it the closest node.
            if(systems_in_graph[0].connectedLanes[i].destination->distFromSource < defaultDist){
                closestNode = (*systems_in_graph[0].connectedLanes[i].destination);
                cout<<"New closest: "<<closestNode.name<<endl;
                defaultDist = closestNode.distFromSource;
                lane2Closest = systems_in_graph[0].connectedLanes[i];
            }
        }
        lanesVisistedInOrder.push_back(lane2Closest);
    }

    // Look through list of systems in entire graph and find system with shortest distance from current node
    // Do not save that system if it has been visited, move on to next closest instead.
    for(int i = 0; i < lanes_in_graph.size(); ++i){
        if(lanes_in_graph[i].lightyears < defaultDist && find(visited.begin(), visited.end(), (*lanes_in_graph[i].destination).name) == visited.end()){
            if(find(visited.begin(), visited.end(), (*lanes_in_graph[i].origin).name) != visited.end()){
                closestNode = (*lanes_in_graph[i].destination);
                defaultDist = lanes_in_graph[i].lightyears;
                lane2Closest = lanes_in_graph[i];
            }
        }
    }

    cout<<endl<<"Closest after graph search: "<<closestNode.name<<endl;
    cout<<"Closest Node distance from Source: "<<closestNode.distFromSource<<endl;

    //Mark the current cloest node as visited
    visited.push_back(closestNode.name);
    visitedNodes.push_back(closestNode);
    lanesVisistedInOrder.push_back(lane2Closest);

    // Go through each connected hyperlane of the newly found closest node, update each lane's destination system with its distance from the source.
    // Default distance is 1000 instead of infinity for this program. Updated distance is the distance in lightyears of the hyperlane plus the closest
    // node's distance from source.
    for(int i = 0; i < closestNode.connectedLanes.size(); ++i){
        closestNode.connectedLanes[i].destination->distFromSource = closestNode.connectedLanes[i].lightyears + closestNode.distFromSource;
        cout<<closestNode.connectedLanes[i].destination->name<<" Dist from source: "<<closestNode.connectedLanes[i].destination->distFromSource<<endl;
    }

    //Rerun func until all nodes have been visited
    if(systems_in_graph.capacity() != visited.capacity()){
        defaultDist = 500;
        shortestPath(closestNode);
    }
    return;
}

//TODO LIST
// string Graph::minimumSpanningTree(){} that works


// NOT REQUIRED BUT HELPFUL

// bool Graph::removeNode(string name){
//     int index = nodeSearch(name);
//     if(index != 42){
//         if(systems_in_graph[index])
//     }
//     cout<<"That system does not exist"<<endl;
// }
// int Graph::edgeSearch(string sysname){
//     for(int i = 0; i <= lanes_in_graph.capacity(); ++i){
//         if((*lanes_in_graph[i].origin).name == sysname || (*lanes_in_graph[i].destination).name == sysname){
//             return i;
//         }
//     }
// }

// bool Graph::removeEdge(string source, string destination){}


