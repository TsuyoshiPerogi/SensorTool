# SensorTool V1.0
Arduino-based Reverse engineering tool for ploting the analog voltage map of a 0-5V analog sensor with unknown values against a analog sensor with known values.

Currently used to provide MAF tranlation for any automobile that uses a 0-5V air flow device. Soon to include tuning functionality. 

DOES PROVIDE A TRANSLATION FUNCTION ONCE CALIBRATED.

V1.0 is for vehicles with both MAF/MAP based ECU's(most 2012+ 3-4 cylinder non-turbo that use T-MAF part# 1525A031, which is OEM on many mitsu's). However, for complete removal, you need to figure out what you are doing with your IAT sensor. MAF/MAP MITSU'S HAVE A SUPER COOL TRICK AROUND DEFEATING THE IAT SENSOR, because there is actually 2 of them on-board, only 1 gets used, but i have so much open-source stuff to release you'll have to wait for a tutorial. 

V1.1 is for people who wish to replace only their MAF/MAP sensor with a GM 2 or 3 bar map sensor, and it only suitable for vehicles with a single Air Flow Device. 

V1.2 will allow fuel injector control and a programable fuel map(+/-1% adjustments to fuel every 500rpm up to 10,000rpm), will provide identical functionality as the Apex'i S-AFC piggyback computer. Only for vehicles with V1.1 installed. WILL INCLUDE EASY TO READ NOTATION FOR USERS TO MAKE ADJUSTMENTS AND CUSTOMIZATIONS THEMSELVES.

V1.3 will include schematics for your own injector driver(or you can buy one from me and ill build it for you), and will include Staged throttle body injection maps for Traditonal and electric supercharger/turbocharger(HKS, etc) applications, allowing fine tuning of high boost application without require ECU reflashing or expensive standalone management system. INJECTORS DRIVERS CAN BE USED FOR MICRO/MEGASQUIRT,MOTEC, STANDLONE APPLICATIONS AS EXTERNAL DRIVERS and have the appropriate timing functions for use as primary injector drivers. 


SO MANY MORE THING PLANNED LIKE RACELOGIC STYLE TRACTION CONTROL, FLATSHIFT/NO-LIFT SHIFT, LAUNCH CONTROL, CONTROL NITROUS SYSTEM THAT APPLY APPROPRIATE TIMING/FUEL ADJUSTMENTS WHILE NITROUS ENGAGED, AND MUCH MORE. I'M HAPPY TO LISTEN TO SUGGESTIONS FROM MY USERS ON WHAT FEATURE THEY WANT TO SEE, AS I ONLY BUILD/ADD FEATURES THAT I USE CURRENTLY. EMAIL HASHERBASHER@PROTONMAIL.COM WITH YOUR SUGGESTIONS, COMMENTS, OR HATE MAIL, IM HAPPY TO READ ALL OF IT ;)

Removed all notation as only professionals who know what they are doing should be using this. Contact me if you want a custom Maf translator made for you, i'm always looking to add more vehicles to the list.

Overview:

-Slave Sensor is the sensor you wish to map/clone/translate. Analog signal from this sensor must be connected to both one analog and one digital pin.

-Current iteration is for mapping against th eGM 1,2,3 bar MAP sensor, but a sensor with known data values can be used instead(MAF/MAP equipped vehicles) 


Program runs for 5mins(60 seconds for dyno version), and logs the following data:

  -Slave Sensor Signal Frequency(in Hz)
  
  -Min/Max analog voltage values obtained during run(0-5V)
  
  -Slope translation points of slave sensor.(saved as text to on-board SDcard)
  
  -Once calibrated, program will begin running translation program. To remove calibration or change vehicle, just reflash firmware to return to factory settings and recalibrate.

Use:

Ideally, this is done on a dyno, but if you can't afford the dynotime.....then you should be able to afford the speeding ticket

