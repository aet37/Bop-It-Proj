void setup(){
  // Power inputs
  pinMode(8, INPUT);    // Push Button  

  // Game outputs
  pinMode(9, OUTPUT);   // Speaker
  pinMode(1, OUTPUT);  // Green LED
  pinMode(3, OUTPUT);  // Red LED
  
}

void loop(){
  
  int state = 1;
  int score = 0;
  int task = 0;
  bool success = false;
  bool fail = false;
  int timer = 0;

  do{
    // Case Statements
    switch(state){

      // Case 1 Device on
      case 1:
        digitalWrite(3, HIGH);         // Red LED On
        // LCD Display
        
        // If Game start button high
        if(digitalRead(8) == HIGH){     // Push Button Starts Game
          state = 2;
        }
        break;
        
      // Case 2 Game start
      case 2:
        // Reset variables
        score = 0;
        success = false;
        fail = false;
        task = 0;
        timer = 0;

        digitalWrite(1, HIGH);                        // Green High
        digitalWrite(3, LOW);                         // Red Low
        // LCD Display
        
        // Tone sounds to indicate beginning of game
        tone(9, 450, 500);
        tone(9, 600, 500);
        tone(9, 450, 500);
        state = 3;                                    // Task Gen State
        break;
        
      // Case 3 Task generation
      case 3:
        // Randomly generate task
        task = random(1,4);
        success = false;
        timer = 0;
        digitalWrite(1, LOW);                         // Green LED Low

        // Branch correct case
        if(task == 1){state = 4;}
        else if(task == 2){state = 5;}
        else if(task == 3){state = 6;}
        break;
        
      // Case 4 Bop It
      case 4:

        // Tone for Bop It
        tone(9, 800, 500);                                     // One Tone
      
        //Loop for Task timing
        do{
          if(digitalRead(8) == HIGH){                          // Button Press
            success = true;
            break;
          }
          else if(analogRead(3) == HIGH){  // Incorrect Inputs
            break;
          }
        }while(timer < 100000);           // Timer Expiration

        break;
        
      // Case 5 Twist It
      case 5:

        // Tone for Twist
        tone(9, 800, 500);                                    // One Tone
        delay(20);
        tone(9, 800, 500);                                    // Second Tone
      
        //Loop for Task timing
        do{
          if(1){                          // Potentiometer Twist
            success = true;
            break;
          }
          else if(analogRead(3) > 0 || digitalRead(8) == HIGH){     // Incorrect Inputs
            break;
          }
        }while(timer < 100000);           // Timer Expiration
        
        break;
        
      // Case 6 Yell It
      case 6:

        // Tone for Yell
        tone(9, 800, 500);                                    // One Tone
        delay(20);
        tone(9, 800, 500);                                    // Second Tone
        delay(20);
        tone(9, 800, 500);                                    // Third Tone
      
        //Loop for Task timing
        do{
          if(analogRead(3) > 0){                              // Speaker high
            success = true;
            break;
          }
          else if(digitalRead(8) == HIGH){                    // Incorrect Inputs
            break;
          }
        }while(timer < 100000);                               // Timer Expiration
        
        break;
        
      // Case 7 Game Failure
      case 7:

        digitalWrite(1, LOW);                 // Green LED Low
        digitalWrite(3, HIGH);                // Red LED High
      
        // Play Failure tone
        tone(9, 350, 200);
        tone(9, 250, 200);
        tone(9, 150, 1000);
        // Display score
        
        state = 1;
        break;
      }
      
      // Check the input conditions
      if(state == 4 || state == 5 || state == 6){
        if(success == true){                                  // Success Conditions
          digitalWrite(1, HIGH);                              // Green LED HIGH  
          // Increment score          
          score++;
          // Play success tone
          
          //Next task
          state = 3;
        }  
        else{                                                 // Failure Conditions
          state = 7;
        } 
      }
      
  }while(state<8);
  
}
