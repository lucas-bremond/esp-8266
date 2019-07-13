////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///	This file is part of the ESP 8266 project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///	@file 						ESP8266/Version.hpp
///	@author 					Lucas Bremond <lucas@axelspace.com>
///	@date 						9 Oct 2016

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __ESP8266_Version__
#define __ESP8266_Version__

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <SmingCore/SmingCore.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace esp8266
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Version
{

	public:

		uint					getMajor									( ) const ;
		uint					getMinor									( ) const ;
		uint					getPatch									( ) const ;

		String					getString									( ) const ;

		static Version 			Current										( ) ;

	private:

		uint					major_ ;
		uint					minor_ ;
		uint					patch_ ;

								Version										(   const   uint                        aMajorNumber,
                                                                                const   uint                        aMinorNumber,
                                                                                const   uint                        aPatchNumber                                ) ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
