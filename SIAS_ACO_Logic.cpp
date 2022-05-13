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

float PL[] = {0.5, 0.5, 0.5, 0.5};

float generate_random_phermone(void);   //generate a random value x: 0.0 > x <= 1.0

Packet generate_random_packet(void);    //generate a random packet,
                                        //simulate this packet arriving at our routing node in main

int main()
{
    srand(time(0)); //set seed for all rand() operations

    int packet_id = 0;  
    while(packet_id < 100000)
    {
        /**
         * TODO: todo
         * * get a random packet generated (done)
         * ? update the phermone level for node
         * ? make the routing decision for the node (most important logic)  
         * * print output for this in STDOUT (done)
         */

        packet_id++;
        Packet packet = generate_random_packet();

        //logic to update phermone levels goes here

        PL[packet.dir] = (PL[packet.dir] + (packet.phermone)) / 2;

        //-----------------------------------------

        //logic to take routing decision goes here
        pair <int,int> Ccoord = {4, 4};
        int factor[] = {1, 1, 1, 1};

        if (packet.Dcoord.first > Ccoord.first){
            factor[DIRECTION_EAST] = 4;
        }
        else if (packet.Dcoord.first < Ccoord.first) {
            factor[DIRECTION_WEST] = 4;
        }

        if (packet.Dcoord.second > Ccoord.second) {
            factor[DIRECTION_SOUTH] = 4;
        }
        else if (packet.Dcoord.second < Ccoord.second) {
            factor[DIRECTION_NORTH] = 4;
        } 

        factor[packet.dir] = 0; //Inhibiting packet from returning the direction it just came

        // Inhibiting packet from forwarding to invalid nodes
        if (Ccoord.first == 0) factor[DIRECTION_WEST] = 0;
        if (Ccoord.first == 7) factor[DIRECTION_EAST] = 0;
        if (Ccoord.second == 0) factor[DIRECTION_NORTH] = 0;
        if (Ccoord.second == 7) factor[DIRECTION_SOUTH] = 0;

        for (int it = 0; it < 4; it++)
        {
            factor[it] = factor[it] * (int)(PL[it] * 100);
        }

        float factorSum = factor[0] + factor[1] + factor[2] + factor[3];

        float probablity = (float)(rand()) / (RAND_MAX);

        int decision = -1;

        if (probablity > 0.0 && probablity < factor[0]/factorSum)
            decision = 0;
        else if (probablity > factor[0]/factorSum && probablity < (factor[0] + factor[1])/factorSum)
            decision = 1;
        else if (probablity > (factor[0] + factor[1])/factorSum && probablity < (factor[0] + factor[1] + factor[2])/factorSum)
            decision = 2;
        else if (probablity > (factor[0] + factor[1] + factor[2])/factorSum && probablity < (factor[0] + factor[1] + factor[2] + factor[3] /factorSum))
            decision = 3;
        
 
        //----------------------------------------

        cout << packet_id << "," << packet.dir << "," << packet.phermone << "," << PL[0] << "," << PL[1] << "," << PL[2] << "," << PL[3]<< "," << packet.Dcoord.first << "," << packet.Dcoord.second << "," << decision << "," << probablity << "," << factor[0] << "," << factor[1] << "," << factor[2] << "," << factor[3] << endl; //can pipe this output in a csv file from terminal at execution.
    }

    return 0;
}

float generate_random_phermone(void)
{
    return 1.0 / (rand() % 9 + 1);
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

/**
*   Notes for actual implementation
*   Routing logic to go in RoutingAlgoritms/Routing_xxxx
*   Other potential sites for changes:
*      routing.cpp (logic to calculate new phermone levels, to read/update phermone data from packet/flit)
*      Data Structure to store phermone levels per node
*      Other unidentified required changes
*   Post implementation data collection and analysis
*   Preparation of report and ppt
*/