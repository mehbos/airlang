#ifndef _AIRLANG_DATE_H_
#define _AIRLANG_DATE_H_

#include "Airlang/Validatable.h"

#include <ostream>

///////////////////////////////////////////////////////////

namespace airlang {

///////////////////////////////////////////////////////////

class Date: public Validatable {
public:
	typedef unsigned short int dayflow_t;
private:
	unsigned char const			day;
	unsigned char const			month;
	unsigned short int const	year;

	void operator = (Date const&);
public:
	Date (void);
	Date (Date const& other);
	Date (int day, int month, int year);

	unsigned char		GetDay (void) const;
	unsigned char		GetMonth (void) const;
	unsigned short int	GetYear (void) const;
private:
	void	CheckAndSetInvalidity (int, int, int);
};

extern
std::ostream&	operator << (std::ostream& o, Date const& date);

///////////////////////////////////////////////////////////

}	// airlang

///////////////////////////////////////////////////////////

#endif

