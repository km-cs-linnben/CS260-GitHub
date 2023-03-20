//Struct for edges in graph program

#pragma once
#include "nodes.h"

struct HyperLane{
    public:
        SolarSystemNode* origin = nullptr;
        SolarSystemNode* destination = nullptr;
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