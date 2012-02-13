#include "Airlang/ChorochronicCheckpointBuilder.h"

///////////////////////////////////////////////////////////

namespace airlang {

///////////////////////////////////////////////////////////

ChorochronicCheckpointBuilder::ChorochronicCheckpointBuilder (AirportId const& airportId, DateBuilder const& dateb):
	airportId	(airportId	),
	dateb		(dateb		),
	time_p		(NULL		)
	{}
ChorochronicCheckpointBuilder::ChorochronicCheckpointBuilder (ChorochronicCheckpointBuilder const& other):
	airportId	(other.airportId	),
	dateb		(other.dateb		),
	time_p		(other.time_p		)
	{}

///////////////////////////////////////////////////////////

ChorochronicCheckpointBuilder& ChorochronicCheckpointBuilder::operator , (Time const& time) {
	time_p = &time;
	return *this;
}

///////////////////////////////////////////////////////////

}	// airlang

///////////////////////////////////////////////////////////
