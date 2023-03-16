// Struct for nodes in graph program.
#pragma once
#include <vector>
#include <string>

using namespace std;

struct HyperLane;

class SolarSystemNode{
    public:
        string name;
        int planetCount;
        int fuelAvailable;
        SolarSystemNode(){};
        SolarSystemNode(string systemname, int numplanets, int fuel){
            name = systemname;
            planetCount = numplanets;
            fuelAvailable = fuel;
        };
        vector<SolarSystemNode> connectedSystems;
        vector<HyperLane> connectedLanes;
    private:
};

// struct HyperLane{
//     public:
//         SolarSystemNode* origin;
//         SolarSystemNode* destination;
//         int lightyears;
//         bool oneWay;

//         HyperLane(){};
//         HyperLane(SolarSystemNode* o, SolarSystemNode* d){
//             origin = o;
//             destination = d;
//             lightyears = 0;
//             oneWay = false;
//         };
// };