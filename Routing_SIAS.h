#ifndef __NOXIMROUTING_SIAS_H__
#define __NOXIMROUTING_SIAS_H__

#include "RoutingAlgorithm.h"
#include "RoutingAlgorithms.h"
#include "../Router.h"

using namespace std;

class Routing_SIAS : RoutingAlgorithm {
	public:
		vector<int> route(Router * router, const RouteData & routeData);

		static Routing_SIAS * getInstance();

	private:
		Routing_SIAS(){};
		~Routing_SIAS(){};

		static Routing_SIAS * routing_SIAS;
		static RoutingAlgorithmsRegister routingAlgorithmsRegister;
};

#endif
