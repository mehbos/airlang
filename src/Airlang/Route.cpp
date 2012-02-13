#include "Airlang/Route.h"

///////////////////////////////////////////////////////////

namespace airlang {

///////////////////////////////////////////////////////////

Route::Route (ChorochronicCheckpoint const& beginning, ChorochronicCheckpoint const& end):
	beginning	(beginning	),
	end			(end		)
	{}

///////////////////////////////////////////////////////////

ChorochronicCheckpoint const& Route::GetFrom (void) const {
	return beginning;
}

ChorochronicCheckpoint const& Route::GetTo (void) const {
	return end;
}

///////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& o, Route const& r) {
	return o <<
		"ROUTE   FROM    " << r.GetFrom() << " ->" << std::endl <<
		"        TO      " << r.GetTo();
}

///////////////////////////////////////////////////////////

}	// airlang

///////////////////////////////////////////////////////////
