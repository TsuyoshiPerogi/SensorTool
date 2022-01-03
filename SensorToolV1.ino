
#include <mcp_can.h>
#include <SPI.h>
#define standard 1  //standard is 11 bits
#define txID 0x7DF  //0x7E9
#include <EEPROM.h>


unsigned long rxId;
byte len;
byte rxBuf[8];
unsigned int MAP = 0;
unsigned char txData[8] = {0x02, 0x01, 0x11, 0x55, 0x55, 0x55, 0x55, 0x55};

float maxVoltVal1 = 0; // init with absurdly low value
float minVoltVal1 = 5; // init with absurdly high value


int sensorValue1 = analogRead(A0);// Raw analog voltage reading from OEM MAF/MAP
float voltage1= sensorValue1 * (5.0 / 1023.0);//Calculations to convert sensor values into valtage


const int XPulseIN = 7;      // pulse counter pin
float XONCycle;              //oncycle variable 
float XOFFCycle;             // offcycle variable got microsecond
float XT;                    // tota l time to one cycle ONCycle + OFFcycle
int XF; // Frequency = 1/T
float XDutyCycle;
int OutPin = 9;
bool pointX1 = false;
bool pointX2 = false;
bool pointX3 = false;
bool pointX4 = false;
bool pointX5 = false;
bool pointX6 = false;
bool pointX7 = false;
bool pointX8 = false;
bool pointX9 = false;
bool pointX10 = false;

float idleValue;
//-------------------------------------------------------------------------------------------------------


const float X0 = 0;
float X1;
float X2;
float X3;
float X4;
float X5;
float X6;
float X7;
float X8;
float X9;
float X10;

float FmultiMap(float val, float * _in, float * _out, uint8_t size)
{
  
  // val = constrain(val, _in[0], _in[size-1]);
  if (val <= _in[0]) return _out[0];
  if (val >= _in[size-1]) return _out[size-1];

  // search right interval
  uint8_t pos = 1;  // _in[0] allready tested
  while(val > _in[pos]) pos++;

  // this will handle all exact "points" in the _in array
  if (val == _in[pos]) return _out[pos];

  // interpolate in the right segment for the rest
  return (val - _in[pos-1]) * (_out[pos] - _out[pos-1]) / (_in[pos] - _in[pos-1]) + _out[pos-1];
}
  
  
float out[] = {X0,X1,X2,X3,X4,X5,X6,X7,X8,X9,X10};
float in[]  = {00,20,30,40,50,60,70,80,90,100,110};
float val = MAP;
float SignalOut = FmultiMap(val, in, out, 11);
float Value = (SignalOut * 51);
//-------------------------------------------------------------------------------------------------------


int ticky = 0 ;

int freshStart;

long previousMillis = 0;
long previousMillis2 = 0;
long interval = 100;


void finishUp() {
  freshStart = 1;
  EEPROM.put(11, freshStart);
  Serial.print("Finished Run, Preparing Report:");
  Serial.print("/n");
  if(X10 > 0) {
    Serial.print("WARNING: Maximum values reached for master sensor, translation only accurate to 200kPa ");
    Serial.print("/n");
  }
  Serial.print("Slave Sensor Frequency = ");
  Serial.print(XF);
  Serial.print(" Hz");
  Serial.print("\n");
  Serial.print("Max Slave Sensor Voltage = ");
  Serial.println(maxVoltVal1);
  Serial.print(" V");
  Serial.print("\n");
  Serial.print("Min Slave Sensor Voltage = ");
  Serial.println(minVoltVal1);
  Serial.print(" V");
  Serial.print("\n");
  
  

  Serial.print("Co-ordinate Points As Mapped Against Master Sensor(Current Sensor: GM 2 bar)");
  Serial.print("\n");
  
  Serial.print("X1(20kPa) = ");
  Serial.print(X1);
  Serial.print("\n");
  Serial.print("X2(30kPa) = ");
  Serial.print(X2);
  Serial.print("\n");
  Serial.print("X3(40kPa) = ");
  Serial.print(X3);
  Serial.print("\n");
  Serial.print("X4(50kPa) = ");
  Serial.print(X4);
  Serial.print("\n");
  Serial.print("X5(60kPa) = ");
  Serial.print(X5);
  Serial.print("\n");
  Serial.print("X6(70kPa) = ");
  Serial.print(X6);
  Serial.print("\n");
  Serial.print("X7(80kPa) = ");
  Serial.print(X7);
  Serial.print("\n");
  Serial.print("X8(90kPa) = ");
  Serial.print(X8);
  Serial.print("\n");
  Serial.print("X9(100kPa) = ");
  Serial.print(X9);
  Serial.print("\n");
  Serial.print("X10(200kPa) = ");
  Serial.print(X10);
  Serial.print("\n");
  Serial.print("Analysis Complete!!!");
  Serial.print("\n");
  Serial.print("Any X co-ordinate values received that = 0 indicates target value was never reached during run");
  Serial.print("\n");
  Serial.print("Please COPY/PASTE your diagnostic report to a .txt or notepad file for later use.");
  Serial.print("\n");
  Serial.print("MafTool v1.0 Created by TsuYoshi Perogi. hasherbasher@protonmail.com");
  Serial.print("\n");
  
  }





MCP_CAN CAN0(10); // CAN0 interface usins CS on digital pin 10


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(A0, INPUT);
  pinMode(11, OUTPUT);
  if(CAN0.begin(MCP_STDEXT, CAN_500KBPS, MCP_8MHZ) == CAN_OK)
    Serial.println("Initialized Successfully!");
  else
    Serial.println("**Error Initializing**");
  
  CAN0.setMode(MCP_NORMAL);                          // Set operation mode to normal so the MCP2515 sends acks to received data.
  
}

void loop() {
  
  if (freshStart = 1) {
     unsigned long currentMillis2 = millis();
     if (currentMillis2 - previousMillis2 > interval) {
     analogWrite(OutPin, Value);  
  } else { 
  
 unsigned long currentMillis = millis();

 if(currentMillis - previousMillis > interval)   {
    CAN0.sendMsgBuf(txID, 8, txData); //request data from ECU

    for(byte i=0;i<20;++i){       //get 20 times unless reply arrived from the ECU 
    CAN0.readMsgBuf(&rxId, &len, rxBuf);     // Get CAN data - 03 41 0C 3D 0F
     if(rxId == 0x7E8){
        Serial.print(rxId, HEX);  //0x7E8 
        Serial.print("\t");
        for(byte i = 0; i<len; i++)    // print the data
        {
            Serial.print(rxBuf[i], HEX);
            Serial.print("\t");            
        }
        Serial.println();
        if (sensorValue1 > maxVoltVal1) { maxVoltVal1 = sensorValue1; } // record new max value
        if (sensorValue1 < minVoltVal1) { minVoltVal1 = sensorValue1; } // record new min value

        MAP = rxBuf[3];  //calculate the rpm
        Serial.println(MAP);
        XONCycle = pulseIn(XPulseIN, HIGH);
        XOFFCycle = pulseIn(XPulseIN, LOW);
        //Serial.println(XONCycle);
        //Serial.println(XOFFCycle);
        XT = XONCycle + XOFFCycle;
        XDutyCycle = (XONCycle / XT) * 100;
        XF = 1000000 / XT;
        Serial.println(XF);
        ticky++;
        currentMillis = 0;        
        }
    }
 }
    while(1){
      
    // Mapping points for slave sensor, change these to match your Master Sensor's techincal data values
      if (MAP >= 20 && pointX1 == false) {// 0.273 corresponds to technical data on GM 2 bar map sensor @ 20kPa pressure reading
        X1 = voltage1;
        EEPROM.put(1, X1);
        pointX1 = true;
        Serial.print(" X1 slope point acquired, waiting for X2");
        Serial.print("\n");
      }
      if (MAP >= 30 && pointX2 == false){ //@ 30kPa
        X2 = voltage1;
        EEPROM.put(2, X2);
        pointX2 = true;
        Serial.print(" X2 slope point acquired, waiting for X3");
        Serial.print("\n");
      }
      if (MAP >= 40 && pointX3 == false) { // @ 40kPa
        X3 = voltage1;
        EEPROM.put(3, X3);
        pointX3 = true;
        Serial.print(" X3 slope point acquired, waiting for X4");
        Serial.print("\n");
      }
      if (MAP >= 50 && pointX4 == false) {// @ 50 kPa
        X4 = voltage1;
        EEPROM.put(4, X4);
        pointX4 = true;
        Serial.print(" X4 slope point acquired, waiting for X5");
        Serial.print("\n");
      }
      if (MAP >= 60 && pointX5 == false) {//@ 60kPa
        X5 = voltage1;
        EEPROM.put(5, X5);
        pointX5 = true;
        Serial.print(" X5 slope point acquired, waiting for X6");
        Serial.print("\n");
      }
      if (MAP >= 70 && pointX6 == false) { // @70kPa
        X6 = voltage1;
        EEPROM.put(6, X6);
        pointX6 = true;
        Serial.print(" X6 slope point acquired, waiting for X7");
        Serial.print("\n");
      }
      if (MAP >= 80 && pointX7 == false) { // @ 80kPa
        X7 = voltage1;
        EEPROM.put(7, X7);
        pointX7 = true;
        Serial.print(" X7 slope point acquired, waiting for X8");
        Serial.print("\n");
      }
      if (MAP >= 90 && pointX8 == false) { //@ 90kPa
        X8 = voltage1;
        EEPROM.put(8, X8);
        pointX8 = true;
        Serial.print(" X8 slope point acquired, waiting for X9");
        Serial.print("\n");
      }
      if (MAP >= 100 && pointX9 == false) {//@ 100kPa
        X9 = voltage1;
        EEPROM.put(9, X9);
        pointX9 = true;
        Serial.print(" X9 slope point acquired, waiting for X10");
        Serial.print("\n");
      }
      if (MAP >= 110 && pointX10 == false) {// @ 110kPa
        X10 = voltage1;
        EEPROM.put(10, X10);
        pointX10 = true;
        Serial.print(" X10 slope point acquired");
        Serial.print("\n");
      }      
      if (ticky >= 60000){
        finishUp();
      }
     
    }
 
}
}
}
