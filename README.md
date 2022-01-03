# SensorTool V1.0
Arduino-based Reverse engineering tool for ploting the analog voltage map of a 0-5V analog sensor with unknown values against a analog sensor with known values.

Currently configured for Mass Air Flow(MAF) and Manifold Absolute Pressure(MAP) Sensors, but with tweaking could be used for any analog sensor translation.

MAFTOOL DOES NOT PROVIDE A TRANSLATION FUNCTION, IT SIMPLY MAPS THE DATA REQUIRED TO PERFORM A MAF/MAP TRANSLATION with MAFGod or DIY MAF translator.


Overview:

-Slave Sensor is the sensor you wish to map/clone/translate. Analog signal from this sensor must be connected to both one analog and one digital pin.

-Current iteration is for mapping against theGM 1,2,3 bar MAP sensor, but a sensor with known data values can be used to map the salve sensor  


Program runs for 5mins(60 seconds for dyno version), and logs the following data:

  -Slave Sensor Signal Frequency(in Hz)
  
  -Min/Max analog voltage values obtained during run(0-5V)
  
  -Slope translation points of slave sensor. (used by ModBox/your app to perform the actual translation funtion)

Use:

Ideally, this is done on a dyno, but if you can't afford the dynotime.....then you would need to have a laptop in your vehicle that can read the serial data(ex: with ArduinoIDE via USB cable) and somebody else to hold said laptop.

1)Start with a fully warmed up engine, and begin from a dead stop on the side of the road(in a safe manner), best results are found if MafTool can log data at full throttle and up to redline. 

2)StartMaf tool by powering on your arduino/atmel.

3)Follow directions shown in your serial monitor. Again, The more gears you can log through a greater RPM range will ensure perfectly translated co-ordinates for replacing your OEM MAP/MAF with your Master sensor. program runs for 5 mins to allow you to compensate for vehicles/people/police you may encounter along the way lol. should be started approximately 20 seconds before you begin testing(to obtain a good idle mapping). Once you are satisfied your logs will be accurate you may sit in idle or continue drivng until program finishes. 

if using dyno version: start program approximately 5 seconds before dyno pull begins, complete dyno pull, and allow engine to idle while program finishes. once complete, a diagnostic log is printed in the serial monitor with your Maf/MAP translation slope points, as well as other technical data. 

Use information obatined in your datalogs to program the MAF/MAP settings of your Apparition3A piggyback ECU, or any other useful purpose it may serve.

If you made this code better and want to contribute, make a pull request.
