#ifndef _AIRLANG_DATE_BUILDER_H_
#define _AIRLANG_DATE_BUILDER_H_

#include "Airlang/Date.h"

///////////////////////////////////////////////////////////

namespace airlang {

///////////////////////////////////////////////////////////

class DateBuilder {
	enum PointType {
		DAY = 0u,
		MONTH = 1u,
		YEAR = 2u
	};
	typedef	int	Points[3];

	PointType	next;
	Points		points;

	DateBuilder (DateBuilder const& other);
	void operator = (DateBuilder const&);
public:
	DateBuilder (void);

	DateBuilder&	operator / (int point);
	Date			MakeDate (void) const;
private:
	bool	InvariantsHold (void) const;
	bool	IsFinished (void) const;
};

///////////////////////////////////////////////////////////

}	// airlang

///////////////////////////////////////////////////////////

#endif
