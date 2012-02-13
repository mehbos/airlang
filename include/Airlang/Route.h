#ifndef _AIRLANG_ROUTE_H_
#define _AIRLANG_ROUTE_H_

#include "Airlang/ChorochronicCheckpoint.h"

#include <list>

///////////////////////////////////////////////////////////

namespace airlang {

///////////////////////////////////////////////////////////

class Route {
	ChorochronicCheckpoint const	beginning;
	ChorochronicCheckpoint const	end;

	Route (Route const& other);
	void operator = (Route const&);
public:
	Route (ChorochronicCheckpoint const& beginning, ChorochronicCheckpoint const& end);

	ChorochronicCheckpoint const&	GetFrom (void) const;
	ChorochronicCheckpoint const&	GetTo (void) const;
};

extern
std::ostream&	operator << (std::ostream& o, Route const& r);

///////////////////////////////////////////////////////////

}	// airlang

///////////////////////////////////////////////////////////

#endif

