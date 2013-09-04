// Test sketch for El Escudo Dos
// Turn each EL channel (A-H) on in sequence and repeat
// Mike Grusin, SparkFun Electronics

void setup() {                
  // The EL channels are on pins 2 through 9
  // Initialize the pins as outputs
  pinMode(2, OUTPUT);  // channel A  
  pinMode(3, OUTPUT);  // channel B   
  pinMode(4, OUTPUT);  // channel C
  pinMode(5, OUTPUT);  // channel D    
  pinMode(6, OUTPUT);  // channel E
  pinMode(7, OUTPUT);  // channel F
  pinMode(8, OUTPUT);  // channel G
  pinMode(9, OUTPUT);  // channel H
  // We also have two status LEDs, pin 10 on the Escudo, 
  // and pin 13 on the Arduino itself
  pinMode(10, OUTPUT);     
  pinMode(13, OUTPUT);    
}

void loop() 
{
  int x,status;
  
  // Step through all eight EL channels (pins 2 through 9)
  for (x=2; x<=9; x++)
  {
    digitalWrite(x, HIGH);   // turn the EL channel on
    delay(100);              // wait for 1/10 second
    digitalWrite(x, LOW);    // turn the EL channel off

    digitalWrite(10, status);   // blink both status LEDs
    digitalWrite(13, status);
    status = !status; 
  }
}
