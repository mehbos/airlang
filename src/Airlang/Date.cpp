#include "Airlang/Date.h"

#include "Airlang/util.h"
#include <assert.h>
#include <string.h>

static const int DAY_MIN = 0;
static const int DAY_MAX = 31;
static inline bool IsDayInvalid (int const day) {
	return day < DAY_MIN || day > DAY_MAX;
}

static const int MONTH_MIN = 0;
static const int MONTH_MAX = 12;
static inline bool IsMonthInvalid (int const month) {
	return month < MONTH_MIN || month > MONTH_MAX;
}

static const int YEAR_MIN = 1970;
static const int YEAR_MAX = 2100;
static inline bool IsYearInvalid (int const year) {
	return year < YEAR_MIN || year > YEAR_MAX;
}

typedef char TmpStr[1024];

static inline void MakeInvalidityDescription (TmpStr& buf, char const* const what, int const min, int const max) {
	int const retval = x::sprintf_s(buf, "%s not in [%d, %d]", what, min, max);
	assert(retval >= 0									);
	assert(static_cast<size_t>(retval) < sizeof(buf)	);
}

static inline char const* MakeDayInvalidityDescription (TmpStr& buf) {
	MakeInvalidityDescription(buf, "Day", DAY_MIN, DAY_MAX);
	return &buf[0];
}

static inline char const* MakeMonthInvalidityDescription (TmpStr& buf) {
	MakeInvalidityDescription(buf, "Month", MONTH_MIN, MONTH_MAX);
	return &buf[0];
}

static inline char const* MakeYearInvalidityDescription (TmpStr& buf) {
	MakeInvalidityDescription(buf, "Year", YEAR_MIN, YEAR_MAX);
	return &buf[0];
}

///////////////////////////////////////////////////////////

namespace airlang {

///////////////////////////////////////////////////////////

Date::Date (int const day, int const month, int const year):
	Validatable	(		),
	day			(day	),
	month		(month	),
	year		(year	) {

	CheckAndSetInvalidity(day, month, year);
}

Date::Date (Date const& other):
	Validatable	(other			),
	day			(other.day		),
	month		(other.month	),
	year		(other.year		) {

	assert(!IsValid() || (!IsDayInvalid(day) && !IsMonthInvalid(month) && !IsYearInvalid(year)));
	assert(IsValid() || IsDayInvalid(day) || IsMonthInvalid(month) || IsYearInvalid(year));
}

Date::Date (void):
	Validatable	(),
	day			(),
	month		(),
	year		() {

	SetInvalid("Uninitialised");
}

///////////////////////////////////////////////////////////

unsigned char Date::GetDay (void) const {
	assert(IsValid());
	return day;
}

unsigned char Date::GetMonth (void) const {
	assert(IsValid());
	return month;
}

unsigned short int Date::GetYear (void) const {
	assert(IsValid());
	return year;
}

///////////////////////////////////////////////////////////

void Date::CheckAndSetInvalidity (int const day, int const month, int const year) {
	char buf[1024];

	if (IsDayInvalid(day))
		SetInvalid(MakeDayInvalidityDescription(buf));
	else
	if (IsMonthInvalid(month))
		SetInvalid(MakeMonthInvalidityDescription(buf));
	else
	if (IsYearInvalid(year))
		SetInvalid(MakeYearInvalidityDescription(buf));
}

///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& o, Date const& date) {
	char buf[15] = "(invalid date)";

	if (date.IsValid()) {
		int const retval = x::sprintf_s(buf, "%2u/%2u/%4u", date.GetDay(), date.GetMonth(), date.GetYear());
		assert(retval >= 0);								// no error
		assert(static_cast<size_t>(retval) < sizeof(buf));	// no overflow
	}

	return o << buf;
}

///////////////////////////////////////////////////////////

}	// airlang

///////////////////////////////////////////////////////////
