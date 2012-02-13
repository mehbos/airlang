#ifndef _AIRLANG_AIRPORT_ID_H_
#define _AIRLANG_AIRPORT_ID_H_

#include "Airlang/Validatable.h"
#include "util.h"

#include <ostream>

///////////////////////////////////////////////////////////

namespace airlang {

///////////////////////////////////////////////////////////

class AirportId: public Validatable {
	typedef	char	IdString_t[4];

	IdString_t		id;
public:
	AirportId (void);
	AirportId (AirportId const& other);
	AirportId (char const* const id);

	x::const_of<IdString_t>::T const&	GetId (void) const;
};

extern
std::ostream&	operator << (std::ostream& o, AirportId const& airid);

///////////////////////////////////////////////////////////

}	// airlang

///////////////////////////////////////////////////////////

#endif

