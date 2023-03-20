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
        cout<< &systems_in_graph[sIndex]<<endl;
        newEdge.destination = &systems_in_graph[dIndex];
        cout<<&systems_in_graph[dIndex]<<endl;
        newEdge.lightyears = cost;
        lanes_in_graph.push_back(newEdge);
        //Make sure systems know they are connected to eachother
        systems_in_graph[sIndex].connectedSystems.push_back(systems_in_graph[dIndex]);
        systems_in_graph[dIndex].connectedSystems.push_back(systems_in_graph[sIndex]);
        systems_in_graph[sIndex].connectedLanes.push_back(newEdge);
        systems_in_graph[dIndex].connectedLanes.push_back(newEdge);
        cout<<"LANE ADDED"<<endl;
        return true;
        }
    cout<<sIndex<<"  "<<dIndex<<endl;
    cout<<"FAIL "<<endl;
    return false;
}

// Fills in Min Spanning Tree Vector
void Graph::minSpanHelper(SolarSystemNode system){
    SolarSystemNode current;

    current = system;

    //This is just to add the first node to visited and not have current added to visited more than once
    if(&current == &systems_in_graph[0]){
        cout<<endl<<"Q Empty, current added to beginning";
        visited.push_back(current.name);
    }

    //Delete first position in queue if its not empty
    if(sysqueue.capacity() > 0){
        cout<<endl<<"First in Q deleted";
        for(auto element: sysqueue){
            cout<<element.name<<" "<<endl;
        }
        sysqueue.erase(sysqueue.begin());
        cout<<"Q 0: "<<sysqueue[0].name<<endl;
    }

    // Add current to min span tree
    cout<<endl<<current.name<<" Pushed back of Tree";
    minSpanTree.push_back(current);

    // Go through all of current system's connected lanes and add their destination to the queue and to visited if not already there
    for(int i = 0; i < system.connectedLanes.capacity(); ++i){
        bool found = false;
        cout<<endl<<"Looking at "<<(*system.connectedLanes[i].origin).name<<" to "<<(*system.connectedLanes[i].destination).name<<endl;
        // Go through list of visited systems, if lane's destination matches anything in visited, break out of visited and move on to check next lane
        for(int j = 0; j < visited.capacity(); ++j){
            if(visited[j] != (*system.connectedLanes[i].destination).name){
                continue;
            }
            found = true;
            break;
        }
        // If lane's destination was found, do nothing and force loop to move on to next lane
        if(found == true){continue;}
        // If lane's destination was NOT found, assign that destination system to list of visited systems and into queue
        visited.push_back((*system.connectedLanes[i].destination).name);
        sysqueue.push_back((*system.connectedLanes[i].destination));
    }

    //If queue is not empty, rerun func on next system in queue which should be at position 0 of queue
    if(!sysqueue.empty()){
        minSpanHelper(sysqueue[0]);
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

void Graph::shortestPath(SolarSystemNode system){
    //Start with first node in graph as source
    systems_in_graph[0].distFromSource = 0;
    static SolarSystemNode closestNode;
    cout<<endl<<"Close Node: "<<closestNode.name<<endl;
    static int defaultDist = 1000;
    cout<<endl<<"DEFAULT DIST: "<<defaultDist<<endl;

    //For first loop only
    if(defaultDist == 1000){
        cout<<endl<<"D loop"<<endl;
        for(int i = 0; i < systems_in_graph[0].connectedLanes.capacity(); ++i){
            //Update distance from source variable for each system adjacent to source only.
            systems_in_graph[0].connectedLanes[i].destination->distFromSource = systems_in_graph[0].connectedLanes[i].lightyears;
            cout<<systems_in_graph[0].connectedLanes[i].destination->name<<" Distance from source: "<<systems_in_graph[0].connectedLanes[i].destination->distFromSource<<endl;
            // If destination system distance is less than 1000 make it the new default distance and make it the closest node.
            if(systems_in_graph[0].connectedLanes[i].destination->distFromSource < defaultDist){
                closestNode = (*systems_in_graph[0].connectedLanes[i].destination);
                cout<<"New closest: "<<closestNode.name<<endl;
                defaultDist = closestNode.distFromSource;
            }
        }
    }

    // Look through list of systems in enitre graph and find system with shortest distance from current node
    for(int i = 1; i < systems_in_graph.size(); ++i){
        if(systems_in_graph[i].distFromSource < defaultDist && find(visited.begin(), visited.end(), systems_in_graph[i].name) == visited.end()){
            closestNode = systems_in_graph[i];
            defaultDist = closestNode.distFromSource;
        }
    }
    cout<<"Closest after graph search: "<<closestNode.name<<endl;
    cout<<"Closest Node distance from Source: "<<closestNode.distFromSource<<endl;
    //Mark the current cloest node as visited
    visited.push_back(closestNode.name);

    // Go through each connected hyperlane of the newly found closest node, update each lane's destination system with its distance from the source.
    // Default distance is 1000 instead of infinity for this program. Updated distance is the distance in lightyears of the hyperlane plus the closest
    // node's distance from source.
    for(int i = 0; i < closestNode.connectedLanes.capacity(); ++i){
        closestNode.connectedLanes[i].destination->distFromSource = closestNode.connectedLanes[i].lightyears + closestNode.distFromSource;
    }
    //Rerun func until all nodes have been visited
    if(systems_in_graph.capacity() != visited.capacity()){
        defaultDist = 500;
        shortestPath(closestNode);
    }
    return;
}

//TODO LIST

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


// bool Graph::nodeExists(string name){}


// bool Graph::edgeExists(string source, string destination){}




// string Graph::minimumSpanningTree(){}

// SOLAR SYSTEM STUFF

