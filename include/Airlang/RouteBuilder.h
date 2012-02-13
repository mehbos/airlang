#ifndef _AIRLANG_ROUTE_BUILDER_H_
#define _AIRLANG_ROUTE_BUILDER_H_

#include "Airlang/ChorochronicCheckpointBuilder.h"

///////////////////////////////////////////////////////////

namespace airlang {

///////////////////////////////////////////////////////////

class RouteListBuilder;

class RouteBuilder {
	ChorochronicCheckpointBuilder const*	beginning_p;
	ChorochronicCheckpointBuilder const*	end_p;

	RouteBuilder (RouteBuilder const&);
	void operator = (RouteBuilder const&);
public:
	RouteBuilder (void);

	RouteBuilder&		operator * (ChorochronicCheckpointBuilder const& cp);
	RouteBuilder&		operator / (ChorochronicCheckpointBuilder const& cp);

	RouteBuilder&		operator + (void);
	RouteListBuilder	operator + (RouteBuilder const& other) const;
};

///////////////////////////////////////////////////////////

}	// airlang

///////////////////////////////////////////////////////////

#endif
