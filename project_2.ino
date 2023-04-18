#include "pitches.h"

#define POT A6
#define SPEAKER 3 //[pin #]
#define LED1 5
#define LED2 4

int NOTE_DUR = 137;

void play(int note, int dur) {
  tone(SPEAKER, note);
  delay(dur * NOTE_DUR);
  noTone(SPEAKER);
  delay(dur * NOTE_DUR / 3);
}

void song1() {
  NOTE_DUR = 58;  // Set tempo to be faster
    play(NOTE_D4, 1);
    play(NOTE_FS4, 1);
    play(NOTE_B4, 1);
    play(NOTE_D5, 1);
    play(NOTE_CS5, 1);
    play(NOTE_B4, 1);
    play(NOTE_AS4, 1);
    play(NOTE_B4, 16); //m2
    delay(NOTE_DUR*6);
    play(NOTE_B4, 6);
    play(NOTE_CS5, 6);
    play(NOTE_D5, 6);
    play(NOTE_E5, 6); //m3
    play(NOTE_FS5, 7);
    play(NOTE_D5, 7);
    play(NOTE_FS5, 8);
    play(NOTE_D5, 8);
    play(NOTE_FS5, 22);
    delay(NOTE_DUR*4);
    play(NOTE_FS4, 2); //m4
    play(NOTE_D5, 6);
    play(NOTE_E4, 2);
    play(NOTE_CS5, 6);
    play(NOTE_D4, 2);
    play(NOTE_B4, 4); //m5
    play(NOTE_D4, 2);
    play(NOTE_FS4, 4);
    play(NOTE_B4, 2);
    play(NOTE_D4, 4);
    play(NOTE_B4, 4);
    play(NOTE_D4, 2);
    play(NOTE_FS4, 2);
    play(NOTE_D5, 2);
    play(NOTE_CS5, 2);
    play(NOTE_B4, 2);
    play(NOTE_A4, 2);
    play(NOTE_B4, 4); //m6
    play(NOTE_D4, 2);
    play(NOTE_G4, 4);
    play(NOTE_B4, 2);
    play(NOTE_D4, 4);
    play(NOTE_B4, 4);
    play(NOTE_D4, 2);
    play(NOTE_G4, 2);
    play(NOTE_D5, 2);
    play(NOTE_CS5, 2);
    play(NOTE_B4, 2);
    play(NOTE_A4, 2);
    play(NOTE_D5, 4); //m7
    play(NOTE_FS4, 2);
    play(NOTE_A4, 4);
    play(NOTE_D5, 2);
    play(NOTE_FS4, 4);
    play(NOTE_D5, 4);
    play(NOTE_FS4, 2);
    play(NOTE_A4, 2);
    play(NOTE_D5, 2);
    play(NOTE_CS5, 2);
    play(NOTE_B4, 2);
    play(NOTE_A4, 2);
    play(NOTE_E5, 12); //m8
    delay(NOTE_DUR*2);
    play(NOTE_FS4, 2);
    play(NOTE_D5, 6);
    play(NOTE_E4, 2);
    play(NOTE_CS5, 6);
    play(NOTE_D4, 2);
    play(NOTE_B4, 10); //m9
}

void song2() {
  NOTE_DUR = 144;
    play(NOTE_E5, 4);
    play(NOTE_B4, 8);
    play(NOTE_C5, 8);
    play(NOTE_D5, 4);
    play(NOTE_C5, 8);
    play(NOTE_B4, 8);
    play(NOTE_A4, 4);
    play(NOTE_A4, 8);
    play(NOTE_C5, 8);
    play(NOTE_E5, 4);
    play(NOTE_D5, 8);
}

void song3() {
  NOTE_DUR = 100;
    play(NOTE_B0, 8);
    play(NOTE_C1, 8);
    play(NOTE_CS1, 8);
    play(NOTE_D1, 8);
    play(NOTE_DS1, 8);
    play(NOTE_E1, 8); 
    delay(NOTE_DUR*2);
    play(NOTE_F1, 8);
    play(NOTE_FS1, 8);
    play(NOTE_G1, 8);
    play(NOTE_GS1, 8);
    play(NOTE_A1, 8);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SPEAKER, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(POT, INPUT);
  
  analogRead(POT);
  
  if(analogRead(POT) <= 341) {
    analogWrite(POT, (0, 85)); //0-85
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    song1();
  } 
  if(341 < analogRead(POT) <= 682) {
    analogWrite(POT, (86, 170)); //86-170
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    song2();
  } 
  if(682 < analogRead(POT) <= 1023) { //(682 < analogRead(A6) <= 1023)
    analogWrite(POT, (171, 255)); // 171-255
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    song3();
  }  
}

void loop() {
  // put your main code here, to run repeatedly:
  //if(analogRead(POT) <= 341); {
  //  analogWrite(POT, (0, 85)); //0-85
  //  digitalWrite(LED_1, HIGH);
  //  digitalWrite(LED_2, LOW);
  //  song_1();
  //} 
  //if(341 < analogRead(POT) <= 682) {
    //analogWrite(POT, (86, 170)); //86-170
    //digitalWrite(LED_1,LOW);
    //digitalWrite(LED_2, HIGH);
    //song_2();
  //} 
  //if (682 < analogRead(POT) <= 1023) { //(682 < analogRead(A6) <= 1023)
    //analogWrite(POT, (171, 255)); // 171-255
    //digitalWrite(LED_1, HIGH);
    //digitalWrite(LED_2, LOW);
    //song_3();
  //}
}
