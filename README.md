# MafTool V1.0
Reverse Engineering Tool for Mass Air Flow and Manifold Absolute Pressure Sensors(Analog 0-5v).

Originally written in C/C++ for FPGA architecture, recently ported to ArduinoC. MafTool is the main MAF/MAP tool for the Mirageforum.com piggybackECU project known as Apparition-3A92.

Can be used with any Arduino, but you might have to change the pins, currently setup for nano/uno.

Pin's A0 and D4 must both be connected to the analog signal line of the Slave sensor , Pin A1 and D8 must both be connected to the Master sensor. sensors with over 50ma load rating should not be grounded to the arduino board, and should be grounded to chassis ground instead. Unknown sensors should never be powered directly from the Arduino/Atmel board, and should be provided an external power AND ground supply. 

Program runs for 5mins(60 seconds for dyno version), and logs the following data for BOTH sensors:

  -Signal Frequency(in Hz)
  
  -Min/Max duty cycles obtained during run.(0-100%)
  
  -Min/Max true analog values obtained(0-5V)
  
  -Slope translation values used to translate between chosen sensors.
  
Ideally, this is done on a dyno, but if you can't afford the dynotime.....then you would have to have a laptop in your vehicle that can read the serial data(ex: with ArduinoIDE via USB cable) and somebody else to hold said laptop.

1)Start with a fully warmed up engine, and begin from a dead stop on the side of the road(in a safe manner), best results are found if MafTool can log data at full throttle and up to redline. 

2)StartMaf tool by powering on your arduino/atmel.

3)After 5 seconds, accelerate at full throttle until you reach at minimum 100km/hr. The more gears you can log through a greater RPM range will ensure perfectly translated co-ordinates for replacing your OEM MAP/MAF with your Master sensor. program runs for 5 mins to allow you to compensate for vehicles/people/police you may encounter along the way lol. should be started approximately 20 seconds before you begin testing(to obtain a good idle mapping). Once you are satisfied your logs will be accurate you may sit in idle or continue drivng until program finishes. 

if using dyno version: start program approximately 5 seconds before dyno pull begins, complete dyno pull, and allow engine to idle while program finishes. once complete, a diagnostic log is printed in the serial monitor with your Maf/MAP translation slope points, as well as other technical data. 

Use information obatined in your datalogs to program the MAF/MAP settings of your Apparition3A piggyback ECU, or any other useful purpose it may serve.

If you found this code useful, please consider a small donation to the Mirageforum.com community. If you made this code better and want to contribute, make a pull request.
