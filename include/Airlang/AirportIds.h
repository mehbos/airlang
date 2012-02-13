#ifndef _AIRLANG_AIRPORT_IDS_H_
#define _AIRLANG_AIRPORT_IDS_H_

#include "Airlang.h"

#define AIRPORT_ID_GENERATOR(ID)																	\
	static struct { 																				\
		operator airlang::AirportId const (void) const												\
			{ return airlang::AirportId(#ID); }														\
		airlang::AirportId const operator () (void) const											\
			{ return static_cast<airlang::AirportId const>(*this); }								\
		airlang::AirportId const airid (void) const													\
			{ return (*this)(); }																	\
		airlang::ChorochronicCheckpointBuilder operator , (airlang::DateBuilder const& dateb) const	\
			{ return (airid(), dateb); }															\
	} ID;																							\

AIRPORT_ID_GENERATOR(SKG)
AIRPORT_ID_GENERATOR(HER)
AIRPORT_ID_GENERATOR(LON)
AIRPORT_ID_GENERATOR(ATH)


///////////////////////////////////////////////////////////

namespace airlang {

///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////

}	// airlang

///////////////////////////////////////////////////////////

#endif

