#include <Arduino.h>

// Function prototypes
void flow();
void seq0();
void seq1();
void seq2();
void seq3();

// flowSensor-related variables
int flowSensor = 2;
volatile int frequency = 0;

int sequence = 0;
int LEDS[4] = {3,4,5,6};

// Define an array of function pointers?
// http://www.cplusplus.com/forum/beginner/4639/
// typedef void (*FunctionDataType);
// FunctionDataType sequences[3] = {seq1, seq2, seq3};


void setup() {
  // Loop through the LED-array and 
  for (int i=0; i<4; i++){
    pinMode(LEDS[i], OUTPUT);
  }
  
  pinMode(flowSensor, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(flowSensor),flow,RISING);
}


void loop() {
  if(frequency>0){
    // sequences[sequence];

    seq1();
    delay(650);
    seq0();
    delay(2000);
    seq2();
    delay(650);
    seq0();
    delay(2000);
    seq3();
    delay(650);
    seq0();
    delay(2000);
    
    // Reset the counter (frequency)
    frequency=0;

  }else{
    seq0();
  }
}


void flow(){
  frequency++;
}


void seq0(){
  for (int i=0; i<4; i++){
      digitalWrite(LEDS[i], LOW);
    }
}


void seq1(){
  for (int i=0; i<4; i++){
      digitalWrite(LEDS[i], HIGH);
      delay(500);
    }
}


void seq2(){
  for (int i=0; i<4; i++){
      digitalWrite(LEDS[i], HIGH);
      delay(500);
      digitalWrite(LEDS[i], LOW);
      delay(500);
    }
}


void seq3(){
    digitalWrite(LEDS[0], HIGH);
    digitalWrite(LEDS[1], HIGH);
    digitalWrite(LEDS[2], HIGH);
    digitalWrite(LEDS[3], HIGH);
    delay(800);
    digitalWrite(LEDS[0], LOW);
    digitalWrite(LEDS[1], LOW);
    digitalWrite(LEDS[2], LOW);
    digitalWrite(LEDS[3], LOW);
    delay(800);
    digitalWrite(LEDS[0], HIGH);
    digitalWrite(LEDS[1], HIGH);
    digitalWrite(LEDS[2], HIGH);
    digitalWrite(LEDS[3], HIGH);
    delay(800);
    digitalWrite(LEDS[0], LOW);
    digitalWrite(LEDS[1], LOW);
    digitalWrite(LEDS[2], LOW);
    digitalWrite(LEDS[3], LOW);
    delay(800);
    digitalWrite(LEDS[0], HIGH);
    digitalWrite(LEDS[1], HIGH);
    digitalWrite(LEDS[2], HIGH);
    digitalWrite(LEDS[3], HIGH);
    delay(800);
    digitalWrite(LEDS[0], LOW);
    digitalWrite(LEDS[1], LOW);
    digitalWrite(LEDS[2], LOW);
    digitalWrite(LEDS[3], LOW);
    delay(800);
}