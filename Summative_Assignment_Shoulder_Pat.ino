//Cynthia Wang and Melody Zhong
//June 21, 2022
//This program will have light up 2 LEDs and initiate an arm pat when the user pushes a button

#include <Servo.h>

//Variables
int patButton = 4; //The button for shoulder pats will connect to pin 4
int led1 = 7; //The first LED will connect to pin 7
int led2 = 8; //The second LED will connect to pin 8

Servo myservo; //Creates a variable for the Servo motor

//Setup code
void setup() {
  pinMode(led1, OUTPUT); //Sets the first LED to output
  pinMode(led2, OUTPUT); //Sets the second LED to output

  pinMode(patButton, INPUT); //Set the button to input

  myservo.attach(3); //Sets the Servo motor to pin 3
}

void loop() {
  digitalWrite(led1, HIGH); //Lights up the first LED
  digitalWrite(led2, HIGH); //Lights up the second LED

  if(digitalRead(patButton) == HIGH) {
    pat(); //If the button is pressed, initiate the shoulder pat
  }

  delay(50); //Delays for 50 milliseconds
}

//Function for the shoulder pat
void pat() {
  int pos = 90; //Creates a variable for the motor position equal to 0
  
  for(int i = 0; i < 3; i++) { //The arm will deliver 3 pats
    for(pos = 90; pos >= 0; pos--) { //Decreases the position of the motor by 1 each loop until it reaches 90
      myservo.write(pos); //Sets the motor position according to the position variable
      delay(15); //Delays 15 milliseconds
    }
    for(pos = 0; pos <= 90; pos++) { //Increases the position of the motor by 1 each loop until it reaches 90
      myservo.write(pos); //Sets the motor position according to the position variable
      delay(15); //Delays 15 milliseconds
    }
  }

  myservo.write(90); //Sets the position back to 0
  delay(15); //Delays 15 milliseconds
}
