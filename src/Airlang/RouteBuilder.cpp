#include "Airlang/RouteBuilder.h"
#include "Airlang/RouteListBuilder.h"

///////////////////////////////////////////////////////////

namespace airlang {

///////////////////////////////////////////////////////////

RouteBuilder::RouteBuilder (void):
	beginning_p	(NULL	),
	end_p		(NULL	)
	{}

///////////////////////////////////////////////////////////

RouteBuilder& RouteBuilder::operator * (ChorochronicCheckpointBuilder const& cp) {
	beginning_p = &cp;
	return *this;
}

RouteBuilder& RouteBuilder::operator / (ChorochronicCheckpointBuilder const& cp) {
	end_p = &cp;
	return *this;
}

RouteBuilder& RouteBuilder::operator + (void) {
	return *this;
}

RouteListBuilder RouteBuilder::operator + (RouteBuilder const& other) const {
	return RouteListBuilder(*this, other);
}

///////////////////////////////////////////////////////////

}	// airlang

///////////////////////////////////////////////////////////

