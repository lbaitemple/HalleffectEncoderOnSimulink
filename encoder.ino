  int encoderA = 3;
  int encoderB = 2;
  int pulsesChanged = 0;
int pulses;    //output counter
int counter=0; //output counter – need to be reset each time when RPM is calculated
int passedtime;
double rpm;

  

  void A_CHANGE() 
  { 
    //Interrupt function to read the x2 pulses of the encoder.
    if ( digitalRead(encoderB) == 0 ) {
      if ( digitalRead(encoderA) == 0 ) {
        // A fell, B is low
        pulses--; // Moving forward
      counter--;
      } else {
        // A rose, B is high
        pulses++; // Moving reverse
      counter++;
      }
    } else {
      if ( digitalRead(encoderA) == 0 ) {
  

  
        pulses++; // Moving reverse
      counter++;
      } else {
        // A rose, B is low
        pulses--; // Moving forward
      counter--;
      }
    }
    pulsesChanged = 1;
  }
  

  void setup() {
    Serial.begin(9600);
    pinMode(encoderA, INPUT);
    pinMode(encoderB, INPUT);
  counter=0;
  passedtime=0;
    attachInterrupt(0, A_CHANGE, CHANGE);
  

  

  }//setup
  

  void loop() {
  delay(1000); //update RPM every second 
  detachInterrupt(0);
  rpm = 60.0*1000/(millis()-passedtime)*counter/816;
  passedtime= millis();
  counter =0; //reset counter
  attachInterrupt(0, A_CHANGE, CHANGE);
    if (pulsesChanged != 0) {
      pulsesChanged = 0;
      Serial.print("Encoder Count: ");
  Serial.print(pulses);
Serial.print("RPM Reading: ");
Serial.println(rpm);

    }
  

  

  }

