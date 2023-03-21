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
        int distFromSource = 1000;
        SolarSystemNode(){};
        SolarSystemNode(string systemname, int numplanets, int fuel){
            name = systemname;
            planetCount = numplanets;
            fuelAvailable = fuel;
            distFromSource = 1000;
        };
        vector<SolarSystemNode> connectedSystems;
        vector<HyperLane> connectedLanes;

        int getDistance(){return distFromSource;}
        
    private:
};