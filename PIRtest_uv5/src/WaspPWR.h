/*! \file WaspPWR.h
    \brief Library for managing Waspmote Power & Energy Modes
    
    Copyright (C) 2009 Libelium Comunicaciones Distribuidas S.L.
    http://www.libelium.com
 
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 2.1 of the License, or
    (at your option) any later version.
   
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.
  
    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
  
    Version:		0.8

    Design:		David Gasc�n

    Implementation:	Alberto Bielsa, David Cuartielles

*/

 /*! \def WaspPWR_h
    \brief The library flag
    
  */
#ifndef WaspPWR_h
#define WaspPWR_h


/******************************************************************************
 * Includes
 ******************************************************************************/
 
#include <inttypes.h>
#include "wasprtc.h"


#define	SENS_3V3	0x01
#define	SENS1_5V	0x02
#define	SENS2_5V	0x04
#define	SENS3_5V	0x08

#define	SENS_ON		1
#define	SENS_OFF	0


/******************************************************************************
 * Definitions & Declarations
 ******************************************************************************/

/*! \def WTD_ON
    \brief Watchdog possible states. ON in this case
 */
#define	WTD_ON	1

/*! \def WTD_OFF
    \brief Watchdog possible states. OFF in this case
 */
#define	WTD_OFF	2


/*! \def WTD_16MS
    \brief Watchdog possible timers. 16 miliseconds in this case
 */
#define	WTD_16MS	0

/*! \def WTD_32MS
    \brief Watchdog possible timers. 32 miliseconds in this case
 */
#define	WTD_32MS	1

/*! \def WTD_64MS
    \brief Watchdog possible timers. 64 miliseconds in this case
 */
#define	WTD_64MS	2

/*! \def WTD_128MS
    \brief Watchdog possible timers. 128 miliseconds in this case
 */
#define	WTD_128MS	3

/*! \def WTD_250MS
    \brief Watchdog possible timers. 250 miliseconds in this case
 */
#define	WTD_250MS	4

/*! \def WTD_500MS
    \brief Watchdog possible timers. 500 miliseconds in this case
 */
#define	WTD_500MS	5

/*! \def WTD_1S
    \brief Watchdog possible timers. 1 second in this case
 */
#define	WTD_1S		6

/*! \def WTD_2S
    \brief Watchdog possible timers. 2 seconds in this case
 */
#define	WTD_2S		7

/*! \def WTD_4S
    \brief Watchdog possible timers. 4 seconds in this case
 */
#define	WTD_4S		8

/*! \def WTD_8S
    \brief Watchdog possible timers. 8 seconds in this case
 */
#define	WTD_8S		9



/*! \def BAT_MIN
    \brief Battery level. Minimum value pre-defined
 */
#define	BAT_MIN	512 // 3.3V / 2

/*! \def BAT_MAX
    \brief Battery level. Maximum value pre-defined
 */
#define	BAT_MAX	651 // 4.2V / 2

/*! \def ALL_OFF
    \brief Sleep Options. All the modules and switches OFF
 */
#define	ALL_OFF		SENS_OFF | UART0_OFF | UART1_OFF | BAT_OFF | RTC_OFF | SD_OFF | XBEE_OFF | MUX_OFF

/*! \def SENS_OFF
    \brief Sleep Options. Set sensor switches OFF
 */
#define	SENS_OFF	0

/*! \def UART0_OFF
    \brief Sleep Options. UART0 closed and switch related with XBee is set OFF
 */
#define	UART0_OFF	2

/*! \def UART1_OFF
    \brief Sleep Options. UART1 closed
 */
#define	UART1_OFF	4

/*! \def BAT_OFF
    \brief Sleep Options. Battery level switch is set OFF
 */
#define	BAT_OFF		8

#define	SD_OFF		9

#define	XBEE_OFF	10

#define	MUX_OFF	11

/*! \def RTC_OFF
    \brief Sleep Options. RTC switch is set OFF
 */
#define	RTC_OFF		2


/*! \def HIB_ADDR
    \brief EEPROM Address for hibernating
 */
#define	HIB_ADDR	0

/*! \def HIB_VALUE
    \brief EEPROM Value for hibernating
 */
#define	HIB_VALUE	10


extern volatile uint16_t intFlag;


/******************************************************************************
 * Class
 ******************************************************************************/
 
//! WaspPWR Class
/*!
	WaspPWR Class defines all the variables and functions used for managing Waspmote Energy and Power Modes
 */
class WaspPWR
{
  private:
	  
	//! It sets a certain internal peripheral on 
    	/*!
	  \param uint8_t peripheral : the peripheral to set on
	  \return void
	  \sa resetIPF(uint8_t peripheral), getIPF()
	 */ 
//	void setIPF(uint8_t peripheral);
	
	//! It sets a certain internal peripheral off 
    	/*!
	\param uint8_t peripheral : the peripheral to set off
	\return void
	\sa setIPF(uint8_t peripheral), getIPF()
	 */ 
//	void resetIPF(uint8_t peripheral);
	
	//! It gets the whole IPR 
    	/*!
	\param void
	\return the IPRA flag
	\sa setIPF(uint8_t peripheral), resetIPF(uint8_t peripheral)
	 */
//	uint8_t getIPF();

  public:
	// VARIABLES
    	uint8_t IPRA; //20090224 -- moved to wiring.c
    	uint8_t IPRB;
	
	// CONSTRUCTOR
	//! class constructor
    	/*!
		It does nothing
	\param void
	\return void
	 */ 
    	WaspPWR();
    void 	initPower(uint32_t choose);
	void 	initAllPower(void);

	
	//! It sets ON/OFF 3V3 or 5V switches
    	/*!
	\param uint8_t type : SENS_3V3 or SENS_5V
	\param uint8_t mode : SENS_ON or SENS_OFF
	\return void
	 */ 
	void 	setSensorPower(uint32_t type, uint8_t mode);
	
	//! It enables or disables watchdog interruption
    	/*!
	\param uint8_t mode : WTD_ON or WTD_OFF
	\param uint8_t timer : WTD_16MS, WTD_32MS, WTD_64MS, WTD_128MS, WTD_250MS, WTD_500MS, WTD_1S, WTD_2S, WTD_4S or WTD_8S
	\return void
	 */ 
	void 	setWatchdog(uint8_t mode, uint8_t timer);
	
	//! It switches off the specified Waspmote switches
    	/*!
	\param uint8_t option : ALL_OFF, SENS_OFF, UART0_OFF, UART1_OFF, BAT_OFF or RTC_OFF
	\return void
	\sa switchesON(uint8_t option)
	 */ 
	void	switchesOFF(uint32_t option);
	
	//! It switches on the specified Waspmote switches
    	/*!
	\param uint8_t option : ALL_OFF, SENS_OFF, UART0_OFF, UART1_OFF, BAT_OFF or RTC_OFF
	\return void
	\sa switchesOFF(uint8_t option)
	 */
	void	switchesON(uint16_t option);
	
	void initBattery(void);



	//! It clears all the captured interrupts to allow new interrupts on that modules
    	/*!
	\return void
	 */
	void 	clearInts();
	
	//! It sets the microcontroller to the lowest consumption sleep mode
    	/*!
	\param uint8_t option : ALL_OFF, SENS_OFF, UART0_OFF, UART1_OFF, BAT_OFF or RTC_OFF
	\return void
	\sa sleep(uint8_t timer, uint8_t option), deepSleep(const char* time2wake, uint8_t offset, uint8_t mode, uint8_t option), hibernate(const char* time2wake, uint8_t offset, uint8_t mode)
	 */
//	void	sleep(uint8_t option);
	
	//! It sets the microcontroller to the lowest consumption sleep mode enabling the watchdog
    	/*!
	\param uint8_t timer : WTD_16MS, WTD_32MS, WTD_64MS, WTD_128MS, WTD_250MS, WTD_500MS, WTD_1S, WTD_2S, WTD_4S or WTD_8S
	\param uint8_t option : ALL_OFF, SENS_OFF, UART0_OFF, UART1_OFF, BAT_OFF or RTC_OFF
	\return void
	\sa sleep(uint8_t option), deepSleep(const char* time2wake, uint8_t offset, uint8_t mode, uint8_t option), hibernate(const char* time2wake, uint8_t offset, uint8_t mode)
	 */
//	void	sleep(uint8_t timer, uint8_t option);
	
	//! It sets the microcontroller to the lowest consumption sleep mode enabling RTC interruption
    	/*!
	\param const char* time2wake : string that indicates the time to wake up. It looks like "dd:hh:mm:ss"
	\param uint8_t offset : RTC_OFFSET or RTC_ABSOLUTE
	\param uint8_t mode : RTC_ALM1_MODE1, RTC_ALM1_MODE2, RTC_ALM1_MODE3, RTC_ALM1_MODE4 or RTC_ALM1_MODE5
	\param uint8_t option : ALL_OFF, SENS_OFF, UART0_OFF, UART1_OFF, BAT_OFF or RTC_OFF
	\return void
	\sa sleep(uint8_t option), sleep(uint8_t timer, uint8_t option), hibernate(const char* time2wake, uint8_t offset, uint8_t mode)
	 */
	void	deepSleep(const char* time2wake, uint8_t offset, uint8_t mode, uint8_t option);
		
	void activeDS2745();
	
  void sleepDS2745();
	
	
	
	//! It switches off the general switch enabling RTC interruption
    	/*!
	\param const char* time2wake : string that indicates the time to wake up. It looks like "dd:hh:mm:ss"
	\param uint8_t offset : RTC_OFFSET or RTC_ABSOLUTE
	\param uint8_t mode : RTC_ALM1_MODE1, RTC_ALM1_MODE2, RTC_ALM1_MODE3, RTC_ALM1_MODE4 or RTC_ALM1_MODE5
	\return void
	\sa sleep(uint8_t option), sleep(uint8_t timer, uint8_t option), deepSleep(const char* time2wake, uint8_t offset, uint8_t mode, uint8_t option)
	 */
//	void 	hibernate(const char* time2wake, uint8_t offset, uint8_t mode); 
	
	//! It gets the remaining battery %
    	/*!
	\return the remaining battery %
	 */
//	uint8_t	getBatteryLevel(); 
	
	//! It gets the remaining battery in volts
    	/*!
	\return the remaining battery in volts %
	 */
  int16_t  getBatteryVolts();
	
	int16_t  getBatterytemperature();
	
	int16_t  getBatteryCurrent(); 
	
	uint16_t  addBatteryCurrent(); 
	
	//! It closes I2C bus
    	/*!
	\return void
	 */
	void 	closeI2C();
	
	//! It inits the value of the digipot used in the battery detector
    	/*!
	\param float threshold : threshold to init the battery detector (from 3V to 3.4V)
	\return void
	 */
//	void	setLowBatteryThreshold(float threshold);
	
	//! It checks if Hibernate has generated the reset
    	/*!
	\return void
	 */
//	void	ifHibernate();
        
        //! It restarts Waspmote
    	/*!
        \return void
         */
        void	reboot();
};

extern WaspPWR PWR2745;

#endif
