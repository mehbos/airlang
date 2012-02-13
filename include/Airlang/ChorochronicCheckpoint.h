#ifndef _AIRLANG_CHOROCHRONIC_CHECKPOINT_H_
#define _AIRLANG_CHOROCHRONIC_CHECKPOINT_H_

#include "Airlang/AirportId.h"
#include "Airlang/Date.h"
#include "Airlang/Time.h"

#include <ostream>

///////////////////////////////////////////////////////////

namespace airlang {

///////////////////////////////////////////////////////////

class ChorochronicCheckpoint {
	const Date		date;
	const Time		time;
	const AirportId	airportId;

	bool	AllValid (void) const;

public:
	ChorochronicCheckpoint (ChorochronicCheckpoint const& other);
	ChorochronicCheckpoint (AirportId const& airportId, Date const& date, Time const& time);

	AirportId const&	GetAirportId (void) const;
	Date const&			GetDate (void) const;
	Time const&			GetTime (void) const;
};

extern
std::ostream&	operator << (std::ostream& o, ChorochronicCheckpoint const& cp);

///////////////////////////////////////////////////////////

}	// airlang

///////////////////////////////////////////////////////////

#endif

