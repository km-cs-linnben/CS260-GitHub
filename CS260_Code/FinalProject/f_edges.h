//Struct for edges in graph program

#pragma once
#include "nodes.h"

struct HyperLane{
    public:
        SolarSystemNode* origin;
        SolarSystemNode* destination;
        int lightyears;
        bool oneWay;

        HyperLane(){};
        HyperLane(SolarSystemNode* o, SolarSystemNode* d){
            origin = o;
            destination = d;
            lightyears = 0;
            oneWay = false;
        };
};