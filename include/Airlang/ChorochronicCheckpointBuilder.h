#ifndef _AIRLANG_CHOROCHRONIC_CHECKPOINT_BUILDER_H_
#define _AIRLANG_CHOROCHRONIC_CHECKPOINT_BUILDER_H_

#include "Airlang/AirportId.h"
#include "Airlang/DateBuilder.h"
#include "Airlang/Time.h"

///////////////////////////////////////////////////////////

namespace airlang {

///////////////////////////////////////////////////////////

class ChorochronicCheckpointBuilder {
	AirportId const&		airportId;
	DateBuilder const&		dateb;
	Time const*				time_p;

	void operator = (ChorochronicCheckpointBuilder const&);
public:
	ChorochronicCheckpointBuilder (AirportId const& airportId, DateBuilder const& date);
	ChorochronicCheckpointBuilder (ChorochronicCheckpointBuilder const& other);

	ChorochronicCheckpointBuilder&	operator , (Time const& time);
};

///////////////////////////////////////////////////////////

}	// airlang

///////////////////////////////////////////////////////////

#endif


