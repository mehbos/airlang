#ifndef _AIRLANG_PASSENGER_BUILDER_H_
#define _AIRLANG_PASSENGER_BUILDER_H_

///////////////////////////////////////////////////////////

namespace airlang {

///////////////////////////////////////////////////////////

class PassengerBuilder {
public:
	enum 			Title { Mister, Miss };
	typedef char	Name[60];
	typedef char	Surname[60];
private:
	Title	title;
	Name	name;
	Surname	surname;

	PassengerBuilder (PassengerBuilder const&);
	void operator = (PassengerBuilder const&);
public:
	PassengerBuilder (void);

	PassengerBuilder&	SetTitle (Title);
	PassengerBuilder&	operator , (char const* name);
};

///////////////////////////////////////////////////////////

}	// airlang

///////////////////////////////////////////////////////////

#endif
