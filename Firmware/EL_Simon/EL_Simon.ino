/*
EL SimÃ³n
N.Poole 2011
SparkFun Electronics

I wrote this code just to show off some EL Panel. It originally ran on an EL Sequencer 
Board which had the Arduino Bootloader on it, but feel free to modify it for whatever
hardware you want! The hardware setup is pretty straight-forward: 4 EL Panels are connected
to the A,B,C and D outputs on the Sequencer and 4 Force Sensitive Resistors are mounted 
below them, attached to Analog pins A3-6. Finally, a buzzer or small speaker is connected
between A2 and ground. 

I could have just modified the Simon Game code from our small Simon games but I had always
wanted to write Simon as a programming exercise so this was my quick attempt. I hope you
find it helpful, and enjoy!


*/

int A = 0; //button A status
int B = 0; //button B status
int C = 0; //button C status
int D = 0; //button D status

int steps = 1; // # of steps

char Str1[20]; // This is where the correct answers will go

void setup() {
  
  Serial.begin(9600);
  
  Serial.println("Setup");
  
  pinMode(2, OUTPUT); // EL Panels
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
  pinMode(A6, INPUT); // FSRs
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  
  pinMode(A2, OUTPUT); // Buzzer
  
  randomSeed(analogRead(A7)); // floating analog pin
  
  for(int r = 0; r < 20; r++){ // fill our answer sheet with random steps
    Str1[r] = random(1,5);}

}

void loop() {
  
  Serial.println("Main Loop");
  
  if(steps > 19){winner();} // FTW
  
  simon(); //play (steps) number of steps
  
  player(); //get and check (steps) number of steps
  
  steps++; //add another step
    
}

void player(){
  
  Serial.println("Player LooP");
  
  int answer = 0; //guess for each step
  
  int input = 0; // # of steps you've made it through
  
  int poscheck = 0; //position of array to check
  
  int correct = 1; //correct guess flag
  
  while(input < steps && correct == 1){ //do until you're out of steps or until you get one wrong
    
  A = analogRead(A4);
  B = analogRead(A3);
  C = analogRead(A5);
  D = analogRead(A6);
  
  answer = 5; //decoy: if this changes, a button has been pressed
  
  if(A > 300){
  digitalWrite(2, HIGH);
  tone(A2, 440);
  input++;
  answer = 1;
  delay(1000);
  digitalWrite(2, LOW);
  noTone(A2);}

  if(B > 300){
  digitalWrite(3, HIGH);
  tone(A2, 500);
  input++;
  answer = 2;
  delay(1000);
  digitalWrite(3, LOW);
  noTone(A2);}

  if(C > 300){
  digitalWrite(4, HIGH);
  tone(A2, 540);
  input++;
  answer = 3;
  delay(1000);
  digitalWrite(4, LOW);
  noTone(A2);}

  if(D > 300){
  digitalWrite(5, HIGH);
  tone(A2, 600);
  input++;
  answer = 4;
  delay(1000);
  digitalWrite(5, LOW);
  noTone(A2);}
  
  if(answer != 5){ //if a button was pressed
  
  poscheck = input - 1; //check position of array equal to # of inputs - 1 because arrays start at 0
  
  if(answer != Str1[poscheck]){correct = 0;} //if it's wrong, mark it wrong
  }

if(correct == 0){loser();} //if you were booted from the loop for a wrong answer, end the game

} } 

void simon(){
  
  Serial.println("simon loop");
  
    for(int s = 0; s < steps; s++){ //play each step for the player
    
    int currentstep = Str1[s];
    
    if(currentstep == 1){
  digitalWrite(2, HIGH);
  tone(A2, 440);
  delay(1000);
  digitalWrite(2, LOW);
  noTone(A2);}
              
    if(currentstep == 2){
  digitalWrite(3, HIGH);
  tone(A2, 500);
  delay(1000);
  digitalWrite(3, LOW);
  noTone(A2);}
      
        
    if(currentstep == 3){
  digitalWrite(4, HIGH);
  tone(A2, 540);
  delay(1000);
  digitalWrite(4, LOW);
  noTone(A2);}
        
    if(currentstep == 4){
  digitalWrite(5, HIGH);
  tone(A2, 600);
  delay(1000);
  digitalWrite(5, LOW);
  noTone(A2);}
    }
    
}

void loser(){ //if you're here... you lost.

Serial.println("loser loop");
  
  for(int b = 0;b < 5;b++){ //flash and beep alot, make them hate themselves for losing
  
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  tone(A2, 200);
  
  delay(500);
  
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  noTone(A2);
  
  delay(500);}

steps = 1; //reset global variable

setup(); //start all over

}

void winner(){ //congrats!
  
  Serial.print("sheen loop");
  
  for(int l = 0; l < 10; l++){ //cycle lights, celebrate
      digitalWrite(2, HIGH);
      delay(100);
      digitalWrite(2,LOW);
      digitalWrite(3, HIGH);
      delay(100);
      digitalWrite(3,LOW);
      digitalWrite(4, HIGH);
      delay(100);
      digitalWrite(4,LOW);
      digitalWrite(5, HIGH);
      delay(100);
      digitalWrite(5,LOW);}
      
   for(int n = 0; n < 20; n++){tone(A2, (300+(n*2)));} //play 'em up
   for(int n = 20; n > 0; n--){tone(A2, (300+(n*2)));} //play 'em down
   noTone(A2);
   
  steps = 1; //reset global variable

  setup(); //start all over
 
}
   
  

