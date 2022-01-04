# SensorTool V1.0
Arduino-based Reverse engineering tool for ploting the analog voltage map of a 0-5V analog sensor with unknown values against a analog sensor with known values.

Currently configured for Mass Air Flow(MAF) and Manifold Absolute Pressure(MAP) Sensors, but with tweaking could be used for any analog sensor translation.

DOES PROVIDE A TRANSLATION FUNCTION ONCE CALIBRATED.

Removed all notation as only professionals who know what they are doing should be using this. 

Overview:

-Slave Sensor is the sensor you wish to map/clone/translate. Analog signal from this sensor must be connected to both one analog and one digital pin.

-Current iteration is for mapping against th eGM 1,2,3 bar MAP sensor, but a sensor with known data values can be used instead(MAF/MAP equipped vehicles) 


Program runs for 5mins(60 seconds for dyno version), and logs the following data:

  -Slave Sensor Signal Frequency(in Hz)
  
  -Min/Max analog voltage values obtained during run(0-5V)
  
  -Slope translation points of slave sensor.

Use:

Ideally, this is done on a dyno, but if you can't afford the dynotime.....then you should be able to afford the speeding ticket

