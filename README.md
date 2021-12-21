# MafTool
Reverse Engineering Tool for Mass Air Flow and Manifold Absolute Pressure Sensors(Analog 0-5v).

Can be used with any Arduino, but you might have to change the pins, currently setup for nano/uno.

Pin's A0 and D4 must both be connected to the analog signal line of the Slave sensor , Pin A1 and D8 must both be connected to the Master sensor. Any sensors that do not have power supplies can be tied to the 5V rail and connected to GND on your arduino/dev board. 


Can be used to reverse engineer techical data from an unknown MAF or MAP such as: Frequency(in Hz), minimum/maximum analog voltages obtained(0-5V), and min/max duty cycle% recorded. Optionally, logged data can then be plotted against a MAF/MAP with a known set of technical data. Currently setup for a 2 bar GM map sensor, but values can be changed by simply inputing data from a different sensor into the code but replacing the X1, X2, X3,etc reference points, then you would be mapping an Unknown sensor against the sensor of your choice.  
