////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///	This file is part of the ESP 8266 project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///	@file 						ESP8266/Application.cpp
///	@author 					Lucas Bremond <lucas@axelspace.com>
///	@date 						9 Oct 2016

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <ESP8266/Application.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace esp8266
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

								Application::Application					( )
								:	wifiEnabled_(true),
									wifiActive_(false),
									statusTimerEnabled_(false)
{

}

								Application::~Application					( )
{
	this->stop() ;
}

bool							Application::isActive						( ) const
{
	return wifiManager_.isActive() ;
}

void							Application::start							( )
{

	// Application storage setup

	applicationStorage_.load() ;

	// Serial setup

	Serial.begin(SERIAL_BAUD_RATE) ;
	Serial.systemDebugOutput(true) ;

	// set timezone hourly difference to UTC
	// SystemClock.setTimeZone(2);

	// Status timer setup

	// if (statusTimerEnabled_)
	// {

	// 	statusTimer_.initializeMs(1000, Delegate<void()>(&Application::onPrintStatus, this)) ; // TBM param

	// 	statusTimer_.start() ;

	// }

	// WiFi client setup

	if (!wifiManager_.isActive())
	{

		wifiManager_.associateApplicationStorage(applicationStorage_) ;

		wifiManager_.setConnectionSuccessHandler(Delegate<void()>(&Application::onWifiConnectionSuccess, this)) ;
		wifiManager_.setConnectionFailureHandler(Delegate<void()>(&Application::onWifiConnectionFailure, this)) ;

		wifiManager_.setMode(WiFiManager::Mode::Station) ;
		// wifiManager_.setMode(WiFiManager::Mode::AccessPoint) ;

		wifiManager_.start() ;

	}

}

void							Application::stop							( )
{

	// WiFi client stop

	if (wifiManager_.isActive())
	{
		wifiManager_.stop() ;
	}

}

void							Application::onPrintStatus					( )
{

	if (!statusTimerEnabled_)
	{
		return ;
	}

}

void							Application::onWifiConnectionSuccess		( )
{

}

void							Application::onWifiConnectionFailure		( )
{

}

void							Application::onClockSet						( )
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

esp8266::Application application ;

void							init										( )
{

	// System.setCpuFrequency(eCF_80MHz) ;

	// File system setup

	spiffs_mount() ;

	// Starting application

	application.start() ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
