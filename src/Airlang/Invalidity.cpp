#include "Airlang/Invalidity.h"

#include "Airlang/util.h"
#include <assert.h>

///////////////////////////////////////////////////////////

namespace airlang {

///////////////////////////////////////////////////////////

bool Invalidity::Holds (void) const {
	return holds;
}

void Invalidity::SetInvalid (char const* const reason) {
	assert(!Holds());
	holds = true;
	x::strcpy_s(Invalidity::reason, reason);
}

Invalidity::Invalidity (void):
	holds	(false	),
	reason	(		)
	{}

///////////////////////////////////////////////////////////

}	// airlang

///////////////////////////////////////////////////////////
