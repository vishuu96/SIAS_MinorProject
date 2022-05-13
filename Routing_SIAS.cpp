#include "Routing_SIAS.h"

RoutingAlgorithmsRegister Routing_SIAS::routingAlgorithmsRegister("SIAS", getInstance());

Routing_SIAS *Routing_SIAS::routing_SIAS = 0;

Routing_SIAS *Routing_SIAS::getInstance()
{
    if (routing_SIAS == 0)
        routing_SIAS = new Routing_SIAS();

    return routing_SIAS;
}

vector<int> Routing_SIAS::route(Router *router, const RouteData &routeData)
{
    Coord current = id2Coord(routeData.current_id);
    Coord destination = id2Coord(routeData.dst_id);
    vector<int> directions;

    float factor[4] = {1, 1, 1, 1};

    if (destination.x > current.x)
    {
        factor[DIRECTION_EAST] = 999;
    }
    else if (destination.x < current.x)
    {
        factor[DIRECTION_WEST] = 999;
    }
    
    if (destination.y > current.y)
    {
        factor[DIRECTION_SOUTH] = 999;
    }
    else if (destination.y < current.y)
    {
        factor[DIRECTION_NORTH] = 999;
    }

    // Inhibiting packet from returning the direction it just came from
    if (routeData.dir_in < 4)
        factor[routeData.dir_in] = 0; 

    // Inhibiting packet from forwarding to invalid nodes
    if (current.x == 0)
    {
        factor[DIRECTION_WEST] = 0;
    }
    if (current.x == (GlobalParams::mesh_dim_x - 1))
    {
        factor[DIRECTION_EAST] = 0;
    }
    if (current.y == 0)
    {
        factor[DIRECTION_NORTH] = 0;
    }
    if (current.y == (GlobalParams::mesh_dim_y - 1))
    {
        factor[DIRECTION_SOUTH] = 0;
    }

    
    for (int it = 0; it < DIRECTIONS; it++)
        {
            int multiplier = (int)(routeData.phermoneLevels[it] * 100);
            if (multiplier != 0) //phermone level cannot completely prohibit transmision
                factor[it] = factor[it] * multiplier;
        }

    const float factorSum = factor[0] + factor[1] + factor[2] + factor[3];
    const float probablity = ((float)std::rand() + 1 ) / (RAND_MAX);
    int decision;
    float divider1 = (factor[0] / factorSum);
    float divider2 = ((factor[0] + factor[1]) / factorSum);
    float divider3 = ((factor[0] + factor[1] + factor[2]) / factorSum);


    if (probablity <= divider1)
    {
        decision = DIRECTION_NORTH;
    }
    else if (probablity > divider1 && probablity <= divider2)
    {
        decision = DIRECTION_EAST;
    }
    else if (probablity > divider2 && probablity <= divider3)
    {
        decision = DIRECTION_SOUTH;
    }
    else if (probablity > divider3)
    {
        decision = DIRECTION_WEST;
    }

    directions.push_back(decision);

    // vector <int> xyd;
    // if (destination.x > current.x)
    //    xyd.push_back(DIRECTION_EAST);
    // else if (destination.x < current.x)
    //     xyd.push_back(DIRECTION_WEST);
    // else if (destination.y > current.y)
    //     xyd.push_back(DIRECTION_SOUTH);
    // else
    //     xyd.push_back(DIRECTION_NORTH);
    // std::cout << " DECISION " << decision << " XYD " << xyd.front() << endl;

    return directions;
}
