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
    bool sourceExists = false;
    bool destExists = false;
    int sIndex;
    int dIndex;
    cout<<systems_in_graph.capacity()<<endl;
    cout<<"GRAPH 0 "<<systems_in_graph[0].name<<endl;
    for(int i =0; i <= systems_in_graph.capacity(); ++i){
        cout<<"BEGIN FOR"<<endl;
        if(systems_in_graph[i].name == source){
            sIndex = i;
            sourceExists = true;
            cout<<"source found"<<endl;
        }else if(systems_in_graph[i].name == destination){
            dIndex = i;
            destExists = true;
            cout<<"dest found"<<endl;
        }else if(sourceExists == true && destExists == true){
            cout<<"both found"<<endl;
            break;
        }else{
            cout<<"else"<<endl;
            continue;
        }
    }
    if(sourceExists == true && destExists == true){
        HyperLane newEdge;
        newEdge.origin = &systems_in_graph[sIndex];
        cout<< &systems_in_graph[sIndex]<<endl;
        newEdge.destination = &systems_in_graph[dIndex];
        cout<<&systems_in_graph[dIndex]<<endl;
        newEdge.lightyears = cost;
        lanes_in_graph.push_back(newEdge);
        cout<<"LANE ADDED"<<endl;
        return true;
        }

    return false;
}



// bool Graph::removeNode(string name){}


// bool Graph::removeEdge(string source, string destination){}


// bool Graph::nodeExists(string name){}


// bool Graph::edgeExists(string source, string destination){}


// string Graph::shortestPath(string name){}


// string Graph::minimumSpanningTree(){}

// SOLAR SYSTEM STUFF

