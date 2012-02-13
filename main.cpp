#include "Airlang.h"
#include "Airlang/AirportIds.h"

#include <iostream>

int main (int const, char const**) {

//	NEW_FLIGHT(A3714):
//		ROUTE	FROM	[SKG, DATE 14/ 2/2012, TIME( 1:30)]
//				TO		[HER, DATE 15/ 2/2013, TIME(13:40)]
//		ROUTE	FROM	[HER, DATE 16/ 2/2013, TIME( 2:20)]
//				TO		[LON, DATE 17/ 2/2013, TIME(14:30)]
//		PASSENGER 		[MR "MARTHA"		| "LOLOTA"		]
//		PASSENGER 		[MS "LILIPOUTIA"	| "MONOPOLY"	]
//	PRICE 12 EUROS;

//	std::cout <<
//		(	ROUTE	FROM	[SKG, DATE 14/ 2/2012, TIME( 1:30)] ->
//					TO		[HER, DATE 15/ 2/2013, TIME(13:40)]
//			ROUTE	FROM	[HER, DATE 15/ 2/2013, TIME(15: 7)] ->
//					TO		[LON, DATE 22/ 6/2070, TIME( 0: 0)]
//			ROUTE	FROM	[LON, DATE 22/ 6/2070, TIME( 0: 1)] ->
//					TO		[ATH, DATE 22/16/2070, TIME( 0: 2)]
//		)
//	<< std::endl;

			ROUTE	FROM	[SKG, DATE 14/ 2/2012, TIME( 1:30)] ->
					TO		[HER, DATE 15/ 2/2013, TIME(13:40)]
			ROUTE	FROM	[HER, DATE 15/ 2/2013, TIME(15: 7)] ->
					TO		[LON, DATE 22/ 6/2070, TIME( 0: 0)]
			ROUTE	FROM	[LON, DATE 22/ 6/2070, TIME( 0: 1)] ->
					TO		[ATH, DATE 22/16/2070, TIME( 0: 2)]
	;

			PASSENGER 		[MR, "MARTHA", "LOLOTA"	]
	;
}

