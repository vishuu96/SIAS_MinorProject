/* This code is for creating and testing logic for ACO algorithm based routing
* logic to be perfected here
*
*/

#include <iostream>
using namespace std;

enum {
    DIRECTION_NORTH,
    DIRECTION_EAST,
    DIRECTION_SOUTH,
    DIRECTION_WEST
};

struct Packet {
    int dir; // direction of arrival
    pair <int, int> Scoord;
    pair <int, int> Dcoord;
    float phermone;
};

struct Phermone_Levels {
    float phermone_north;    
    float phermone_east;
    float phermone_south;
    float phermone_west;    
} PL;



float generate_random_phermone(void);   //generate a random value x: 0.0 > x <= 1.0

Packet generate_random_packet(void);    //generate a random packet,
                                        //simulate this packet arriving at our routing node in main

int main()
{

    while(true)
    {
        /* 
        TODO: 
        *   get a random packet generated
        *   update the phermone level for node
        *   make the routing decision for the node (most important logic)  
        *   print output for this in STDOUT
        */
    }

    return 0;
}


/*
*   Notes for actual implementation
*   Routing logic to go in RoutingAlgoritms/Routing_xxxx
*   Other potential sites for changes:
*   *   routing.cpp (logic to calculate new phermone levels, to read/update phermone data from packet/flit)
*   *   Data Structure to store phermone levels per node
*   *   Other unidentified required changes
*   Post implementation data collection and analysis
*   Preparation of report and ppt
*/