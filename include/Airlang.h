#ifndef _AIRLANG_H_
#define _AIRLANG_H_

#include "Airlang/RouteListBuilder.h"
#include "Airlang/PassengerBuilder.h"

#define DATE		airlang::DateBuilder() /
#define TIME(HM)	airlang::Time( (true? HM), (false? HM) )
#define ROUTE		+ airlang::RouteBuilder()
#define FROM		* airlang::FromerBuilder()
#define TO			GetFrom() / airlang::Passer<airlang::ChorochronicCheckpointBuilder>()
#define MR			airlang::PassengerBuilder().SetTitle(airlang::PassengerBuilder::Mister)
#define MS			airlang::PassengerBuilder().SetTitle(airlang::PassengerBuilder::Miss)
#define PASSENGER	airlang::Passer<airlang::PassengerBuilder>()

///////////////////////////////////////////////////////////

namespace airlang {

///////////////////////////////////////////////////////////

template <typename PassingType>
struct Passer {
	typedef PassingType	T;
	typedef Passer<T>	Self;

	T const&	operator [] (T const& o) const
					{ return o; }
};

///////////////////////////////////////////////////////////

class Fromer {
	ChorochronicCheckpointBuilder const& from;
public:
	Fromer (ChorochronicCheckpointBuilder const& from): from(from) {}

	ChorochronicCheckpointBuilder const&	GetFrom (void) const
												{ return from; }
	Fromer const*							operator -> (void) const
												{ return this; }
};


class FromerBuilder {
public:
	Fromer	operator [] (ChorochronicCheckpointBuilder const& from) const
				{ return Fromer(from); }
};

///////////////////////////////////////////////////////////

ChorochronicCheckpointBuilder operator , (AirportId const& airid, DateBuilder const& dateb) {
	return ChorochronicCheckpointBuilder(airid, dateb);
}

///////////////////////////////////////////////////////////

}	// airlang

///////////////////////////////////////////////////////////

#endif
