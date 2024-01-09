//Cynthia Wang and Melody Zhong
//June 21, 2022
//This program will display compliments on an LCD screen and play music from a speaker when a button is pressed

#include <LiquidCrystal.h> //Includes the LCD library
#include "pitches.h" //Includes the pitches library for the speaker

//Variables
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //The respective LCD pins connect to their respective Arduino pins
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //LiquidCrystal variable is created with the variables from the previous line

int complimentButton = 6; //The compliment push button will connect to pin 6
int speaker = 13; //The speaker will connect to pin 13

const char compliments[10][16] = {"You're special!", "You're great!", "You're awesome!", "You're amazing!", "You can do it!", "I love you!", "Nice hair!", "Nice fit!", "You're cool!", "You're hot!"}; //Creates an array of 10 compliments

int song1notes[] = {NOTE_C5, NOTE_AS4, NOTE_GS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_DS4, NOTE_C4, NOTE_CS4, NOTE_DS4, NOTE_F4, NOTE_DS4, NOTE_C4, NOTE_DS4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_GS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_DS4, NOTE_C4, NOTE_CS4, NOTE_DS4, NOTE_F4, NOTE_DS4, NOTE_C4, NOTE_DS4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_DS5, NOTE_F5, NOTE_DS5, NOTE_C5, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_GS4}; //Creates an array of the notes for the first song
int song1durations[] = {8, 8, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 4, 8, 8, 4, 4, 8, 8, 8, 8, 4, 4, 4, 8, 8, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 4, 8, 8, 8, 4, 8, 8, 8, 8, 8, 4, 4, 4}; //Creates an array of durations for the first song
int song2notes[] = {NOTE_C5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_D5, NOTE_F5, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_D5, NOTE_F5, NOTE_F5, NOTE_C6, NOTE_A5, NOTE_A5, NOTE_C5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_D5, NOTE_F5, NOTE_D5, NOTE_C5, NOTE_C6, NOTE_A5, NOTE_C6, NOTE_AS5, NOTE_G5, NOTE_A5, NOTE_F5}; //Creates an array of notes for the second song
int song2durations[] = {8, 4, 8, 4, 4, 8, 4, 8, 2, 8, 4, 8, 4, 4, 4, 4, 2, 8, 4, 8, 4, 4, 8, 4, 8, 2, 4, 8, 4, 4, 8, 4, 2}; //Creates an array of durations for the second song
int song3notes[] = {NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_B4, 0, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_D5, NOTE_A4, 0, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_D5, NOTE_B4, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_B4, 0, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_D5, NOTE_A4, 0, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_B4, NOTE_D5, NOTE_G5, NOTE_B5, NOTE_D6, NOTE_G6}; //Creates an array of notes for the third song
int song3durations[] = {8, 8, 4, 4, 8, 8, 8, 8, 4, 4, 8, 8, 8, 8, 4, 4, 8, 8, 8, 8, 4, 4, 8, 8, 4, 4, 8, 8, 8, 8, 4, 4, 8, 8, 8, 8, 4, 4, 8, 8, 8, 8, 8, 16, 16, 16, 16, 16, 16, 16}; //Creates an array of durations for the third song
int songSize; //Creates a variable for the song size

//Setup code
void setup() {
  lcd.begin(16, 2); //Determines that the LCD is 16 by 2
  Serial.begin(9600); //Sets the data rate of the Serial Monitor
}

void loop() {
  int song = random(3); //The song variable is a random number between 0 to 2
  if(digitalRead(complimentButton) == HIGH) {
    displayCompliment(); //Displays a compliment on the LCD screen when a button is pressed
    if(song == 0) {
      songSize = sizeof(song1durations) / sizeof(song1durations[0]); //Gets the length of the first song durations array    
      for (int i = 0; i < songSize; i++) { //Loops the number of times as the size of the first song durations array
        int noteDuration = 1000 / song1durations[i]; //Sets the duration of the note
        tone(speaker, song1notes[i], noteDuration); //Plays the note on the speaker for the appropriate duration
    
        int pauseBetweenNotes = noteDuration * 1.30; //Sets the duration of the pause between notes
        delay(pauseBetweenNotes); //Delays by the amount of the pause between notes
    
        noTone(speaker); //Turns the speaker off
      }
    }
    else if(song == 1) {
      songSize = sizeof(song2durations) / sizeof(song2durations[0]); //Gets the length of the second song durations array    
      for (int i = 0; i < songSize; i++) { //Loops the number of times as the size of the second song durations array
        int noteDuration = 1000 / song2durations[i]; //Sets the duration of the note
        tone(speaker, song2notes[i], noteDuration); //Plays the note on the speaker for the appropriate duration
    
        int pauseBetweenNotes = noteDuration * 1.30; //Sets the duration of the pause between notes
        delay(pauseBetweenNotes); //Delays by the amount of the pause between notes
    
        noTone(speaker); //Turns the speaker off
      }
    }
    else {
      songSize = sizeof(song3durations) / sizeof(song3durations[0]); //Gets the length of the third song durations array    
      for (int i = 0; i < songSize; i++) { //Loops the number of times as the size of the third song durations array
        int noteDuration = 1000 / song3durations[i]; //Sets the duration of the note
        tone(speaker, song3notes[i], noteDuration); //Plays the note on the speaker for the appropriate duration
    
        int pauseBetweenNotes = noteDuration * 1.30; //Sets the duration of the pause between notes
        delay(pauseBetweenNotes); //Delays by the amount of the pause between notes
    
        noTone(speaker); //Turns the speaker off
      }
    }
    lcd.clear(); //Clears the LCD screen
  }
  delay(500); //Delays 500 milliseconds
}

//Code to display a compliment on the LCD screen
void displayCompliment() {
  int complimentNumber = random(10); //The complimentNumber variable is a random number between 0 to 9
  lcd.setCursor(0,0); //The text on the LCD will start at the top left
  lcd.print(compliments[complimentNumber]); //Prints the compliment to the LCD screen
}
