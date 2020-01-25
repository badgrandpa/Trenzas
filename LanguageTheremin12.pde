

// Serial Communication
import processing.serial.*;
Serial port;
/*
String arduinoInput;
 String[] splitArduinoInput;
 float[] newArduinoInput;
 */

// Minim Library
import ddf.minim.*;
import ddf.minim.ugens.*;
Minim minim;
Gain gain;
AudioOutput out;
AudioPlayer track01, track02, track03, track04, track05, track06;

//sensor01, volume01
float  volume01;
float value01;

//sensor02, volume02
float  volume02;
float value02;

//sensor03, volume03
float  volume03;
float value03;

//sensor04, volume04
float  volume04;
float value04;

//sensor05, volume05
float  volume05;
float value05;

//sensor06, volume06
float  volume06;
float value06;




void setup() {

  size(255, 255);

  // Serial Communication Setup
  String portName = "/dev/tty.usbmodem14101";
  port = new Serial(this, portName, 9600);
  port.bufferUntil('\n');
  port.write('x');

  // Minim Setup Sensor01 - long hair  - pink
  minim = new Minim(this); // importing minim to be able to use is
  track01 = minim.loadFile("Testimonio01_English.mp3");
  track01.play();
  track01.loop();
  // start the Gain at 0 dB, which means no change in amplitude
  track01.setGain(-80);

  // Minim Setup Sensor02 - short hair  - light blue
  track02 = minim.loadFile("Testimonio02_Spanish.mp3");
  track02.play();
  track02.loop();
  // start the Gain at 0 dB, which means no change in amplitude
  track02.setGain(-80);

  // Minim Setup Sensor03 - long hair  - purple
  track03 = minim.loadFile("Testimonio01_Quechua.mp3");
  track03.play();
  track03.loop();
  // start the Gain at 0 dB, which means no change in amplitude
  track03.setGain(-80);

  // Minim Setup Sensor04 short hair  - blue
  track04 = minim.loadFile("Testimonio02_English.mp3");
  track04.play();
  track04.loop();
  // start the Gain at 0 dB, which means no change in amplitude
  track04.setGain(-80);

  // Minim Setup Sensor06 - long hair   - green
  track05 = minim.loadFile("Testimonio01_Spanish.mp3");
  track05.play();
  track05.loop();
  // start the Gain at 0 dB, which means no change in amplitude
  track05.setGain(-80);
  
    // Minim Setup Sensor05 short hair - yellow
  track06 = minim.loadFile("Testimonio02_Quechua.mp3");
  println("track05: ");
  println(track05);
  track06.play();
  track06.loop();
  // start the Gain at 0 dB, which means no change in amplitude
  track06.setGain(-80);


  println("setup is ready");
}

void draw() {
  background(0);

  //Sensor Ellipse01 - pink
  fill(255, 100, 150);
  track01.setGain(volume01);
  ellipse(volume01, 100, 20, 20);

  //Sensor Ellipse02 - light blue
  fill(0, 200, 200);
  track02.setGain(volume02);
  ellipse(volume02, 120, 20, 20);

  //Sensor Ellipse03 - purple 
  fill(100, 50, 255);
  track03.setGain(volume03);
  ellipse(volume03, 140, 20, 20);

  //Sensor Ellipse04 -blue
  fill(100, 140, 250);
  track04.setGain(volume04);
  ellipse(volume04, 160, 20, 20);

  //Sensor Ellipse05 - yellow
  fill(255, 250, 80);
  track05.setGain(volume05);
  ellipse(volume05, 180, 20, 20);

  //Sensor Ellipse06 - green
  fill(0, 250, 80);
  track06.setGain(volume06);
  ellipse(volume06, 200, 20, 20);
}


void serialEvent(Serial port) {

  String arduinoInput = port.readString(); //converting to strings and then back to float
  String[] splitArduinoInput = split(arduinoInput, ',');

  //  println(splitArduinoInput.length);

  value01 = Float.parseFloat(splitArduinoInput[0]); //separating string values into 6, for each capacitive sensor
  value02 = Float.parseFloat(splitArduinoInput[1]);
  value03 = Float.parseFloat(splitArduinoInput[2]);
  value04 = Float.parseFloat(splitArduinoInput[3]);
  value05 = Float.parseFloat(splitArduinoInput[4]);
  value06 = Float.parseFloat(splitArduinoInput[5]);
  print(splitArduinoInput[0]);

  println(arduinoInput);
  println("value01: ");
  println(value01);
  println("value02: ");
  println(value02);
  println("value03: ");
  println(value03);
  println("value04: ");
  println(value04);
  println("value05: ");
  println(value05);
  println("value06: ");
  println(value06);

  if (value01 >=20) { // - pink
    volume01 = 60 ;
  } else {
    volume01 = -80;
  }

  if (value02 >= 40) { // - light blue
    volume02 = 60 ;
  } else {
    volume02 = -80;
  }

  if (value03 >= 100) { // - purple
    volume03 = 60 ;
  } else {
    volume03 = -80;
  }

  if (value04 >= 80) { // - blue
    volume04 = 60 ;
  } else {
    volume04 = -80;
  }

  if (value05 >= 40) { // - yellow
    volume05 = 60 ;
  } else {
    volume05 = -80;
  }

  if (value06 >= 20) { // - green
    volume06 = 60 ;
  } else {
    volume06 = -80;
  }

  port.write('x');
}
