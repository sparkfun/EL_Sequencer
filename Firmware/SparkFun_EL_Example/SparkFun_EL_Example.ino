/***************************************************************************
SparkFun_EL_Example
Mike Grusin @ SparkFun Electronics 2012
Updated by Toni Klopfenstein@ SparkFun Electronics April 2015
https://github.com/sparkfun/EL_Sequencer

Test sketch for the EL Escudo Dos and EL Sequencer. 
It turns each EL channel (A-H) on in sequence and repeats said loop. 

Development environment specifics:
Arduino 1.6.3

This code is beerware; if you see me (or any other SparkFun employee) at the local, and you've found our code helpful, please buy us a round!
Distributed as-is; no warranty is given.
****************************************************************************/

/*******************Setup Loop***************************/
void setup() {                
  // The EL channels are on pins 2 through 9 on the ATMega328
  // Initialize the pins as outputs
  pinMode(2, OUTPUT);  // channel A  
  pinMode(3, OUTPUT);  // channel B   
  pinMode(4, OUTPUT);  // channel C
  pinMode(5, OUTPUT);  // channel D    
  pinMode(6, OUTPUT);  // channel E
  pinMode(7, OUTPUT);  // channel F
  pinMode(8, OUTPUT);  // channel G
  pinMode(9, OUTPUT);  // channel H

//Uncomment the following line if using this on the EL Escudo Dos. 
// Pin 10 is a status LED on the EL Escudo.  
//  pinMode(10, OUTPUT);

//Pin 13 is the status LED on both the EL Sequencer and Arduino for use with the EL Escudo Dos. 
   pinMode(13, OUTPUT);    
}


/*******************Main Loop***************************/
void loop() 
{
  int x,status;
  
  //Step through all eight EL channels (pins 2 through 9)
  for (x=2; x<=9; x++)
  {
    digitalWrite(x, HIGH);   // turn the EL channel on
    delay(100);              // wait for 1/10 second
    digitalWrite(x, LOW);    // turn the EL channel off

    //digitalWrite(10, status);   //Uncomment this line if using the EL Escudo Dos
    digitalWrite(13, status);	// blink status LEDs
    status = !status; 
  }
}
