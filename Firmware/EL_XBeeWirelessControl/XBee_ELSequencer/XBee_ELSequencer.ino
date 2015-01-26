/*
Wireless EL Sequencer w/ XBee Series 1
Ho Yun Bobby Chan @ SparkFun Electronics
June 20, 2014

Description:
This is a basic test of the EL Sequencer with a wireless controller.
The wireless controller consists of an Arduino Uno, XBee Explorer,
XBee Series 1 transceiver, and LED Push Button. The EL Sequencer
uses an EL component, EL inverter, XBee female sockets soldered,
battery, and a XBee Series 1 transceiver.  An XBee Series 2
can be used but the throughput of the Series 1 is much higher. To
reduce latency, I recommend using the XBee Series 1. The basic
configuration of the XBee module with point-to-point configuratin is
based on Digi's Example tutorial 
=> http://examples.digi.com/get-started/basic-xbee-802-15-4-chat/ .
Page 5 of the tutorial shows you how to broadcast with
point-to-multipoint configuration so that multiple EL Sequencers
can be controlled.

By pushing the button, a character is sent from a remote microcontroller. 
The corresponding EL Sequencer will receive the character and control
the EL component on a channel that is associated with that character.

EL Sequencer uses the hardware UART of the Atmega328 for communication:
     pin 0 = Rx
     pin 1 = Tx
     
Note: Make sure to remove the XBee Series 1 on the EL Sequencer when 
uploading a new sketch file otherwise it will brick the XBee. You can
always use the next generation XCTU software to unbrick and recover
the transceiver.

 */

char val;

void setup(){
  Serial.begin(9600); //for debugging
  pinMode(13, OUTPUT); //Status LED to test
  val = 'A';// button pressed, therefore sending  letter A

  Serial.println("EL Sequencer's XBee is Ready to Receive Characters");
  digitalWrite(13,LOW); //set Status LED OFF
  delay(1000);
}

void loop(){

  //if xbee is receiving data from other XBee
  if(Serial.available()){
    val = Serial.read();
    
    //check to see if character sent is letter A
    if(val == 'A'){
        digitalWrite(13,HIGH); //turn ON Status LED
        delay(50);
      Serial.println("Character Received");
    }
    
    else{
      digitalWrite(13,LOW); //turn OFF Status LED
    }
  }
}





