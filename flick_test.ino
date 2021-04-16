void setup() {
  // put your setup code here, to run once:
  // Power inputs
  pinMode(8, INPUT);    // Push Button  
  pinMode(7, INPUT);    // Mic
  pinMode(6, INPUT);    // Flick

  // Game outputs
  pinMode(9, OUTPUT);   // Speaker
  pinMode(1, OUTPUT);   // Green LED
  pinMode(3, OUTPUT);   // Red LED 
}

void loop() {
  digitalWrite(3, LOW);
  if(digitalRead(6) == HIGH){
    do{}while(digitalRead(6) == HIGH);
  }
  else if(digitalRead(6) == LOW){
    do{}while(digitalRead(6) == LOW);
  }
  digitalWrite(3, HIGH);
  delay(50);
}
