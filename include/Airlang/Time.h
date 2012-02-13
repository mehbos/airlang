#ifndef _AIRLANG_TIME_H
#define _AIRLANG_TIME_H

#include "Airlang/Validatable.h"

#include <ostream>

///////////////////////////////////////////////////////////

namespace airlang {

///////////////////////////////////////////////////////////

class Time: public Validatable {
public:
	typedef unsigned char	timeflow_t;
private:
	timeflow_t const	hour;
	timeflow_t const	minute;

public:
	Time (void);
	Time (Time const& other);
	Time (int const hour, int const minute);

	timeflow_t	GetHour (void) const;
	timeflow_t	GetMinute (void) const;
};

extern
std::ostream&	operator << (std::ostream& o, Time const& time);

///////////////////////////////////////////////////////////

}	// airlang

///////////////////////////////////////////////////////////

#endif
