#ifndef _AIRLANG_ROUTE_LIST_BUILDER_H_
#define _AIRLANG_ROUTE_LIST_BUILDER_H_

#include "Airlang/RouteBuilder.h"

#include <list>

///////////////////////////////////////////////////////////

namespace airlang {

///////////////////////////////////////////////////////////

class RouteListBuilder {
	typedef std::list<RouteBuilder const*>	BuildersPointers;
	BuildersPointers	buildersPointers;
public:
	RouteListBuilder (RouteBuilder const& b1, RouteBuilder const& b2);
	RouteListBuilder (RouteListBuilder const&);

	RouteListBuilder&	operator + (RouteBuilder const& next);
};

///////////////////////////////////////////////////////////

}	// airlang

///////////////////////////////////////////////////////////

#endif
