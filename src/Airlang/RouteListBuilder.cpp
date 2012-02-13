#include "Airlang/RouteListBuilder.h"

///////////////////////////////////////////////////////////

namespace airlang {

///////////////////////////////////////////////////////////

RouteListBuilder::RouteListBuilder (RouteBuilder const& b1, RouteBuilder const& b2):
	buildersPointers	() {

	buildersPointers.push_back(&b1);
	buildersPointers.push_back(&b2);
}

RouteListBuilder::RouteListBuilder (RouteListBuilder const& other):
	buildersPointers	(other.buildersPointers	) {
}

///////////////////////////////////////////////////////////

RouteListBuilder& RouteListBuilder::operator + (RouteBuilder const& next) {
	buildersPointers.push_back(&next);
	return *this;
}

///////////////////////////////////////////////////////////

}	// airlang

///////////////////////////////////////////////////////////
