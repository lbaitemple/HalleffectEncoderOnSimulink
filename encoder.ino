
int pulses;                              //Output pulses.
int encoderA = 3;
int encoderB = 2;
int pulsesChanged = 0;

void A_CHANGE() 
{ 
  //Interrupt function to read the x2 pulses of the encoder.
  if ( digitalRead(encoderB) == 0 ) {
    if ( digitalRead(encoderA) == 0 ) {
      // A fell, B is low
      pulses--; // Moving forward
    } else {
      // A rose, B is high
      pulses++; // Moving reverse
    }
  } else {
    if ( digitalRead(encoderA) == 0 ) {


      pulses++; // Moving reverse
    } else {
      // A rose, B is low
      pulses--; // Moving forward
    }
  }
  pulsesChanged = 1;
}

void setup() {
  Serial.begin(9600);
  pinMode(encoderA, INPUT);
  pinMode(encoderB, INPUT);
  attachInterrupt(0, A_CHANGE, CHANGE);


}//setup

void loop() {
  if (pulsesChanged != 0) {
    pulsesChanged = 0;
    Serial.print("Encoder Count ");
    Serial.println(pulses);
  }


}
