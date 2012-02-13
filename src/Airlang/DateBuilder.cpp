#include "Airlang/DateBuilder.h"

#include <assert.h>

///////////////////////////////////////////////////////////

namespace airlang {

///////////////////////////////////////////////////////////

DateBuilder::DateBuilder (void):
	next	(DAY),
	points	(	) {
}

///////////////////////////////////////////////////////////

Date DateBuilder::MakeDate (void) const {
	return Date(
		points[static_cast<size_t>(DAY	)],
		points[static_cast<size_t>(MONTH)],
		points[static_cast<size_t>(YEAR	)]);
}

///////////////////////////////////////////////////////////

DateBuilder& DateBuilder::operator / (int const point) {
	assert(InvariantsHold());
	assert(!IsFinished());

	// set next
	points[static_cast<size_t>(next)] = point;

	// advance next
	next = static_cast<PointType>(static_cast<size_t>(next) + 1);

	assert(InvariantsHold());
	return *this;
}

///////////////////////////////////////////////////////////

bool DateBuilder::InvariantsHold (void) const {
	return static_cast<size_t>(next) <= static_cast<size_t>(YEAR) || IsFinished();
}

bool DateBuilder::IsFinished (void) const {
	return static_cast<size_t>(next) == static_cast<size_t>(YEAR) + 1;
}

///////////////////////////////////////////////////////////

}	// airlang

///////////////////////////////////////////////////////////

