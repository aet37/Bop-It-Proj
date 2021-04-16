void setup() {
  // put your setup code here, to run once:
   // Power inputs
  pinMode(8, INPUT);    // Push Button  

  // Game outputs
  pinMode(9, OUTPUT);   // Speaker
  pinMode(1, OUTPUT);   // Green LED
  pinMode(3, OUTPUT);   // Red LED  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(8) == HIGH){
    // Tone for Yell
        tone(9, 600, 400);                                      // One Tone
        delay(50);
        noTone(9);
        tone(9, 1000, 500);                                      // Second Tone
        delay(50);
        tone(9, 1000, 500);                                      // Third Tone
        delay(50);
  }
  noTone(9);
}
