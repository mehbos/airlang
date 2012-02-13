#include "Airlang/Time.h"

#include "Airlang/util.h"
#include <assert.h>

///////////////////////////////////////////////////////////

namespace airlang {

///////////////////////////////////////////////////////////

Time::Time (int const hour, int const minute):
	hour	(hour	),
	minute	(minute	) {
	if (hour < 0 || hour > 23)
		SetInvalid("Hour not in [0, 23]");
	else
	if (minute < 0 || minute > 59)
		SetInvalid("Minute not in [0, 59]");
}

Time::Time (void):
	hour	(),
	minute	() {
	SetInvalid("uninitialised");
}

Time::Time (Time const& other):
	hour	(other.hour		),
	minute	(other.minute	) {
	assert(other.IsValid());
}

///////////////////////////////////////////////////////////

Time::timeflow_t Time::GetHour (void) const {
	return hour;
}

Time::timeflow_t Time::GetMinute (void) const {
	return minute;
}

///////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& o, Time const& time) {
	char buf[6];
	int const retval = x::sprintf_s(buf, "%2u:%2u", time.GetHour(), time.GetMinute());
	assert(retval >= 0									);	// no error
	assert(static_cast<size_t>(retval) < sizeof(buf)	);	// no overflow
	return o << buf;
}

///////////////////////////////////////////////////////////

}	// airlang

///////////////////////////////////////////////////////////
