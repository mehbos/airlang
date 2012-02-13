#include "Airlang/AirportId.h"

///////////////////////////////////////////////////////////

namespace airlang {

///////////////////////////////////////////////////////////

AirportId::AirportId (char const* const id) {
	const size_t idlen = strlen(id);
	if (idlen != 3)
		SetInvalid("Id is not exactly three characters long");
	for (const char* idc = id; *idc != '\0' && IsValid(); ++idc)
		if (!(*idc >= 'A' && *idc <= 'Z'))
			SetInvalid("Id does not consist of capital latin letters only");
	x::strcpy_s(AirportId::id, id);
}

AirportId::AirportId (void) {
	SetInvalid("uninitialised");
}

AirportId::AirportId (AirportId const& other) {
	assert(other.IsValid());
	x::strcpy_s(id, other.id);
}

x::const_of<AirportId::IdString_t>::T const& AirportId::GetId (void) const {
	return id;
}


std::ostream& operator << (std::ostream& o, AirportId const& airid) {
	return o << airid.GetId();
}

///////////////////////////////////////////////////////////

}	// airlang

///////////////////////////////////////////////////////////
