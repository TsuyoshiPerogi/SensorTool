# MafTool
Reverse Engineering Tool for Mass Air Flow and Manifold Absolute Pressure Sensors(Analog 0-5v).

Can be used with any Arduino, but you might have to change the pins, currently setup for nano/uno.

Pin's A0 and D4 must both be connected to the analog signal line of the Slave sensor , Pin A1 and D8 must both be connected to the Master sensor. Any sensors that do not have power supplies can be tied to the 5V rail and connected to GND on your arduino/dev board. 

Program runs for 5mins, and logs the following data for BOTH sensors:

  -Signal Frequency(in Hz)
  
  -Min/Max duty cycles obtained during run.(0-100%)
  
  -Min/Max true analog values obtained(0-5V)
  
Ideally, this is done on a dyno, but if you can't afford the dynotime.....then you would have to have a laptop in your vehicle that can read the serial data(ex: with ArduinoIDE via USB cable) and somebody else to hold said laptop.

1)Start with a fully warmed up engine, and begin from a dead stop on the side of the road(in a safe manner), best results are found if MafTool can log data at full throttle and up to redline. 

2)StartMaf tool by powering on your arduino/atmel.

3)After 5 seconds, accelerate at full throttle until you reach at minimum 100km/hr. The more gears you can log through a greater RPM range will ensure a perfectly translated co-ordinates for replacing your OEM MAP/MAF. program runs for 5 mins to allow you to compensate for vehicles/people/police you may encounter along the way lol.

Can be used to reverse engineer techical data from an unknown MAF or MAP such as: Frequency(in Hz), minimum/maximum analog voltages obtained(0-5V), and min/max duty cycle% recorded. Optionally, logged data can then be plotted against a MAF/MAP with a known set of technical data. Currently setup for a 2 bar GM map sensor, but values can be changed by simply inputing data from a different sensor into the code but replacing the X1, X2, X3,etc reference points, then you would be mapping an Unknown sensor against the sensor of your choice.  
