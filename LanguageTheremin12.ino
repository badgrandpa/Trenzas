#include <CapacitiveSensor.h>


CapacitiveSensor   cs_1_0 = CapacitiveSensor(1, 0); // 1 is recieving 0 is sensing (has the copper wire)
CapacitiveSensor   cs_3_2 = CapacitiveSensor(3, 2); // " is recieving " is sensing (has the copper wire)
CapacitiveSensor   cs_5_4 = CapacitiveSensor(5, 4); // " is recieving " is sensing (has the copper wire)
CapacitiveSensor   cs_7_6 = CapacitiveSensor(7, 6); // " is recieving " is sensing (has the copper wire)
CapacitiveSensor   cs_9_8 = CapacitiveSensor(9, 8); // " is recieving " is sensing (has the copper wire)
CapacitiveSensor   cs_11_10 = CapacitiveSensor(11, 10); // " is recieving " is sensing (has the copper wire)

// variables01:
long val01; // the sensor value
long sensorMin01 = 1023; // minimum sensor value
long sensorMax01 = 0; // maximum sensor value

// variables02:
long val02; // the sensor value
long sensorMin02 = 1023; // minimum sensor value
long sensorMax02 = 0; // maximum sensor value

// variables03:
long val03; // the sensor value
long sensorMin03 = 1023; // minimum sensor value
long sensorMax03 = 0; // maximum sensor value

// variables04:
long val04; // the sensor value
long sensorMin04 = 1023; // minimum sensor value
long sensorMax04 = 0; // maximum sensor value

// variables05:
long val05; // the sensor value
long sensorMin05 = 1023; // minimum sensor value
long sensorMax05 = 0; // maximum sensor value

// variables06:
long val06; // the sensor value
long sensorMin06 = 1023; // minimum sensor value
long sensorMax06 = 0; // maximum sensor value



int led01 = 13; //LEDs for callibrating
int led02 = 12;


void setup()
{

  Serial.begin(9600);

  // --------------------------Setup for Sensor01 ---------------------------\\  
  cs_1_0.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example

  pinMode(led01, OUTPUT); //leds are great to test

  digitalWrite(led01, HIGH);
  //calibrate during the first seven seconds when board is turned on or reset
  while (millis() < 10000) {
    val01 = cs_1_0.capacitiveSensor(80); //sensor resolution (sensitivity)

    //records maximum sensor value
    if (val01 > sensorMax01) {
      sensorMax01 = val01;
    }
    // does the same for minimum value
    if (val01 < sensorMin01) {
      sensorMin01 = val01;
    }

  }
  digitalWrite(led01, LOW); //LEDs are so helpfull


  // ------------------------Setup for Sensor02 ------------------------------------\\  


  cs_3_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example

  pinMode(led02, OUTPUT); //leds are great to test

  digitalWrite(led02, HIGH);
  //calibrate during the first seven seconds when board is turned on or reset
  while (millis() < 20000) {
    val02 = cs_3_2.capacitiveSensor(80); //sensor resolution (sensitivity)

    //records maximum sensor value
    if (val02 > sensorMax02) {
      sensorMax02 = val02;
    }
    // does the same for minimum value
    if (val02 < sensorMin02) {
      sensorMin02 = val02;
    }

  }
  digitalWrite(led02, LOW); //LEDs are so helpfull                // tab character for debug windown spacing

  // --------------------------Setup for Sensor03 ---------------------------\\  
  cs_5_4.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example

  pinMode(led01, OUTPUT); //leds are great to test

  digitalWrite(led01, HIGH);
  //calibrate during the first seven seconds when board is turned on or reset
  while (millis() < 30000) {
    val03 = cs_5_4.capacitiveSensor(80); //sensor resolution (sensitivity)

    //records maximum sensor value
    if (val03 > sensorMax03) {
      sensorMax03 = val03;
    }
    // does the same for minimum value
    if (val03 < sensorMin03) {
      sensorMin03 = val03;
    }


  }
  digitalWrite(led01, LOW); //LEDs are so helpfull


  // --------------------------Setup for Sensor04 ---------------------------\\  
  cs_7_6.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example

  pinMode(led02, OUTPUT); //leds are great to test

  digitalWrite(led02, HIGH);
  //calibrate during the first seven seconds when board is turned on or reset
  while (millis() < 40000) {
    val04 = cs_7_6.capacitiveSensor(80); //sensor resolution (sensitivity)

    //records maximum sensor value
    if (val04 > sensorMax04) {
      sensorMax04 = val04;
    }
    // does the same for minimum value
    if (val04 < sensorMin04) {
      sensorMin04 = val04;
    }

  }
  digitalWrite(led02, LOW); //LEDs are so helpfull


  // --------------------------Setup for Sensor05 ---------------------------\\  
  cs_9_8.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example

  pinMode(led01, OUTPUT); //leds are great to test

  digitalWrite(led01, HIGH);
  //calibrate during the first seven seconds when board is turned on or reset
  while (millis() < 50000) {
    val05 = cs_9_8.capacitiveSensor(80); //sensor resolution (sensitivity)

    //records maximum sensor value
    if (val05 > sensorMax05) {
      sensorMax05 = val05;
    }
    // does the same for minimum value
    if (val05 < sensorMin05) {
      sensorMin05 = val05;
    }

  }
  digitalWrite(led01, LOW); //LEDs are so helpfull

  // ------------------------Setup for Sensor06 ------------------------------------\\  


  cs_11_10.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example

  pinMode(led02, OUTPUT); //leds are great to test

  digitalWrite(led02, HIGH);
  //calibrate during the first seven seconds when board is turned on or reset
  while (millis() < 60000) {
    val06 = cs_11_10.capacitiveSensor(80); //sensor resolution (sensitivity)

    //records maximum sensor value
    if (val06 > sensorMax06) {
      sensorMax06 = val06;
    }
    // does the same for minimum value
    if (val06 < sensorMin06) {
      sensorMin06 = val06;
    }

  }
  digitalWrite(led02, LOW); //LEDs are so helpfull

}

void loop()
{
  long start = millis();

 if (Serial.available() > 0) { // arduino waits to hear form processing

  char input = Serial.read();

  val01 = cs_1_0.capacitiveSensor(80);
  long touch01 = map(val01, sensorMin01, sensorMax01, 0, 255); //mapping
  Serial.print(touch01);
  Serial.print(",");
  delay(1);

  val02 = cs_3_2.capacitiveSensor(80);
  long touch02 = map(val02, sensorMin02, sensorMax02, 0, 255); //mapping
  Serial.print(touch02);
  Serial.print(",");
  delay(1);

  val03 = cs_5_4.capacitiveSensor(80);
  long touch03 = map(val03, sensorMin03, sensorMax03, 0, 255); //mapping
  Serial.print(touch03);
  Serial.print(",");
  delay(1);

  val04 = cs_7_6.capacitiveSensor(80);
  long touch04 = map(val04, sensorMin04, sensorMax04, 0, 255); //mapping
  Serial.print(touch04);
  Serial.print(",");
  delay(1);

  val05 = cs_9_8.capacitiveSensor(80);
  long touch05 = map(val05, sensorMin05, sensorMax05, 0, 255); //mapping
  Serial.print(touch05);
  Serial.print(",");
  delay(1);

  val06 = cs_11_10.capacitiveSensor(80);
  long touch06 = map(val06, sensorMin06, sensorMax06, 0, 255); //mapping
  Serial.println(touch06);


   }

}
