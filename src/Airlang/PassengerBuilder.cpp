#include "Airlang/PassengerBuilder.h"

#include "Airlang/util.h"

///////////////////////////////////////////////////////////

namespace airlang {

///////////////////////////////////////////////////////////

PassengerBuilder::PassengerBuilder (void):
	title	(static_cast<Title>(-1)	),
	name	(						),
	surname	(						) {

	x::memset0(name);
	x::memset0(surname);
}

///////////////////////////////////////////////////////////

PassengerBuilder& PassengerBuilder::SetTitle (Title const title) {
	PassengerBuilder::title = title;
	return *this;
}

PassengerBuilder& PassengerBuilder::operator , (char const* const name) {
	if (name[0] == '\0')
		x::strcpy_s(PassengerBuilder::name, name);
	else
	if (surname[0] == '\0')
		x::strcpy_s(surname, name);

	return *this;
}

///////////////////////////////////////////////////////////

}	// airlang

///////////////////////////////////////////////////////////
