#include <LiquidCrystal.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Define variables 
#define I2C_ADDR          0x27        //Define I2C Address where the PCF8574A is
#define BACKLIGHT_PIN      3
#define En_pin             2
#define Rw_pin             1
#define Rs_pin             0
#define D4_pin             4
#define D5_pin             5
#define D6_pin             6
#define D7_pin             7

//Initialise the LCD
LiquidCrystal_I2C      lcd(0x27, 16, 2);

void setup(){
  // Power inputs
  pinMode(6, INPUT);    // Flick
  pinMode(7, INPUT);    // Microphone
  pinMode(8, INPUT);    // Push Button  

  // Game outputs
  pinMode(9, OUTPUT);  // Speaker
  pinMode(1, OUTPUT);  // Green LED
  pinMode(3, OUTPUT);  // Red LED

  // Random Seed Generation
  randomSeed(analogRead(5));

  // LCD Configurations
  lcd.backlight();
  lcd.begin (16,2);     //Define the LCD as 16 column by 2 rows 
}

void loop(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Welcome!");
  delay(200);
  unsigned long currTime = 0;
  unsigned long loopTime = 0;
  unsigned long timeLimit = 200;
  int state = 1;
  int score = 0;
  int task = 0;
  bool success = false;
  bool fail = false;
  int timer = 0;
  int select = 0;
  digitalWrite(1,LOW);
  digitalWrite(3,LOW);
  digitalWrite(9,LOW);

  do{
    // Case Statements
    switch(state){

      // Case 1 Device on
      case 1:
        digitalWrite(3, HIGH);         // Red LED On
        // LCD Display
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Score: ");
        lcd.print(score);
        lcd.setCursor(0,1);
        lcd.print("Press Bop-It!");
        while(digitalRead(8) == LOW){}  // Push Button Starts Game
        state = 2;
        break;
        
      // Case 2 Game start
      case 2:
        // Reset variables
        score = 0;
        success = false;
        fail = false;
        task = 0;
        timer = 0;
        timeLimit = 200;

        digitalWrite(1, HIGH);                        // Green High
        digitalWrite(3, LOW);                         // Red Low
        // LCD Display
        
        // Tone for start
        tone(9, 1200);                                      // One Tone
        delay(20);
        tone(9, 1400);                                      // Second Tone
        delay(20);
        tone(9, 1800);                                      // Third Tone
        delay(50);
        noTone(9);
        delay(50);
        digitalWrite(9, LOW);
        state = 3;                                    // Task Gen State
        break;
        
      // Case 3 Task generation
      case 3:
        // Randomly generate task
        task = random(1,34);
        success = false;
        timer = 0;
        select = 1;

        // Branch correct case
        if(task < 12){state = 4;}
        else if(task >= 12 && task < 23){state = 5;}
        else if(task >= 22 && task < 34){state = 6;}
        digitalWrite(1, LOW);
        break;
        
      // Case 4 Bop It
      case 4:
        
        // Tone for Bop It
        noTone(9);
        delay(20);
        tone(9, 2000);                                      // One Tone
        delay(20);
        noTone(9);

        // LCD Display Bop It
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Score: ");
        lcd.print(score);
        lcd.setCursor(0,1);
        lcd.print("Bop-It!");
      
        //Loop for Task timing
        currTime = millis();
        if(digitalRead(6) == LOW){  
          do{
              if(digitalRead(8) == HIGH){
                success = true;
                break;
              }
              else if(digitalRead(7) == LOW || digitalRead(6) == HIGH){
                break;
              }
              loopTime = millis();
          }while(loopTime < currTime + timeLimit);
        }
        else if(digitalRead(6) == HIGH){  
          do{
              if(digitalRead(8) == HIGH){
                success = true;
                break;
              }
              else if(digitalRead(7) == LOW || digitalRead(6) == LOW){
                break;
              }
              loopTime = millis();
          }while(loopTime < currTime + timeLimit);
        }
        break;
        
      // Case 5 Flick It
      case 5:
        
        // Tone for Flick
        noTone(9);
        delay(20);
        tone(9, 2000);                                      // One Tone
        delay(20);
        noTone(9);
        delay(10);
        tone(9, 2000);                                      // Second Tone
        delay(20);
        noTone(9);
        delay(10);

        // LCD Display Flick It
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Score: ");
        lcd.print(score);
        lcd.setCursor(0,1);
        lcd.print("Flick-It!");
        
        //Loop for Task timing
        currTime = millis();
        if(digitalRead(6) == LOW)  
          do{  
            if(digitalRead(6) == HIGH){                          // Potentiometer Twist
              success = true;
              break;
            }
            else if(digitalRead(7) == LOW || digitalRead(8) == HIGH){     // Incorrect Inputs
              break;
            }
          loopTime = millis();
          }while(loopTime < currTime + timeLimit);
        else if(digitalRead(6) == HIGH)  
          do{  
            if(digitalRead(6) == LOW){                          // Potentiometer Twist
              success = true;
              break;
            }
            else if(digitalRead(7) == LOW || digitalRead(8) == HIGH){     // Incorrect Inputs
              break;
            }
          loopTime = millis();
          }while(loopTime < currTime + timeLimit);
        
        break;
        
      // Case 6 Yell It
      case 6:
        
        // Tone for Yell
        noTone(9);
        delay(20);
        tone(9, 2000);                                      // One Tone
        delay(20);
        noTone(9);
        delay(10);
        tone(9, 2000);                                      // Second Tone
        delay(20);
        noTone(9);
        delay(10);
        tone(9, 2000);                                      // Third Tone
        delay(20);
        noTone(9);
        delay(10);

        // LCD Display Yell-It
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Score: ");
        lcd.print(score);
        lcd.setCursor(0,1);
        lcd.print("Yell-It!");
      
        //Loop for Task timing
        currTime = millis();
        if(digitalRead(6) == LOW){  
          do{
              if(digitalRead(7) == LOW){
                success = true;
                break;
              }
              else if(digitalRead(8) == HIGH || digitalRead(6) == HIGH){
                break;
              }
              loopTime = millis();
          }while(loopTime < currTime + timeLimit);
        }
        else if(digitalRead(6) == HIGH){  
          do{
              if(digitalRead(7) == LOW){
                success = true;
                break;
              }
              else if(digitalRead(8) == HIGH || digitalRead(6) == LOW){
                break;
              }
              loopTime = millis();
          }while(loopTime < currTime + timeLimit);
        }
        break;
        
      // Case 7 Game Failure
      case 7:

        // LCD Display Failure
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Score: ");
        lcd.print(score);
        lcd.setCursor(0,1);
        lcd.print("Game-Over");

        digitalWrite(1, LOW);                               // Green LED Low
        digitalWrite(3, HIGH);                              // Red LED High
        noTone(9);
        delay(20);
        tone(9, 1600);                                      // One Tone
        delay(20);
        noTone(9);
        delay(5);
        tone(9, 1000);                                      // Second Tone
        delay(20);
        noTone(9);
        delay(5);
        tone(9, 600);                                      // Third Tone
        delay(60);
        noTone(9);
        delay(50);
        
        // Display score
        
        state = 1;
        break;
      }
      
      // Check the input conditions
      if((state == 4 || state == 5 || state == 6) && select == 0){
        if(success == true){                                  // Success Conditions
          
          digitalWrite(1, HIGH);                              // Green LED HIGH            
          score++;                                            // Increment score
          timeLimit-=2;                                       // Decrement time allotment

          // LCD Display Failure
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Score: ");
          lcd.print(score);
          lcd.setCursor(0,1);
          lcd.print("Correct!");
          
          // Tone for success
          noTone(9);
          delay(20);
          tone(9, 3000);                                      // One Tone
          delay(10);
          noTone(9);
          delay(5);
          tone(9, 3500);                                      // Second Tone
          delay(20);
          noTone(9);
          delay(5);
          digitalWrite(1, LOW);                               // Green LED Off

          if(score == 99){state = 7;}
          //Next task
          state = 3;
        }  
        else{                                                 // Failure Conditions
          state = 7;
        } 
      }
      else{
        select = 0;
      }
      
  }while(state<8);
  
}
