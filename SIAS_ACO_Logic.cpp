/* This code is for creating and testing logic for ACO algorithm based routing
* logic to be perfected here
*
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum DIRECTIONS{
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

float PL[] = {0.0, 0.0, 0.0, 0.0};

float generate_random_phermone(void);   //generate a random value x: 0.0 > x <= 1.0

Packet generate_random_packet(void);    //generate a random packet,
                                        //simulate this packet arriving at our routing node in main

int main()
{
    srand(time(0)); //set seed for all rand() operations

    int packet_id = 0;  
    while(packet_id < 100)
    {
        /* 
        TODO: 
        *   get a random packet generated (done)
        *   update the phermone level for node
        *   make the routing decision for the node (most important logic)  
        *   print output for this in STDOUT
        */
        packet_id++;
        Packet packet = generate_random_packet();

        //logic to update phermone levels goes here

        //-----------------------------------------

        //logic to take routing decision goes here

        //----------------------------------------

        cout << packet_id << "," << packet.dir << "," << packet.phermone << "," << PL[0] << "," << PL[1] << "," << PL[3] << "," << PL[3]<< "," << packet.Dcoord.first << "," << packet.Dcoord.second << ","/* add decision*/ << endl; //can pipe this output in a csv file from terminal at execution.
    }

    return 0;
}

float generate_random_phermone(void)
{
    return 1.0 / (rand() % 10);
}

Packet generate_random_packet(void)
{
    Packet new_packet;
    new_packet.dir = (rand() % 4);
    new_packet.Scoord = {rand() % 8, rand() % 8};
    new_packet.Dcoord = {rand() % 8, rand() % 8};
    new_packet.phermone = generate_random_phermone();

    return new_packet;
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