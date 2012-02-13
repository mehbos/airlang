#include "Airlang/ChorochronicCheckpoint.h"

///////////////////////////////////////////////////////////

namespace airlang {

///////////////////////////////////////////////////////////

ChorochronicCheckpoint::ChorochronicCheckpoint (AirportId const& airportId, Date const& date, Time const& time):
	date		(date		),
	time		(time		),
	airportId	(airportId	)
	{}
ChorochronicCheckpoint::ChorochronicCheckpoint (ChorochronicCheckpoint const& other):
	date		(other.date			),
	time		(other.time			),
	airportId	(other.airportId	)
	{}

///////////////////////////////////////////////////////////

AirportId const& ChorochronicCheckpoint::GetAirportId (void) const {
	return airportId;
}

Date const& ChorochronicCheckpoint::GetDate (void) const {
	return date;
}

Time const& ChorochronicCheckpoint::GetTime (void) const {
	return time;
}

///////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& o, ChorochronicCheckpoint const& cp) {
	return o << '[' << cp.GetAirportId() << ", " << cp.GetDate() << ", " << cp.GetTime() << ']';
}

///////////////////////////////////////////////////////////

}	// airlang

///////////////////////////////////////////////////////////



