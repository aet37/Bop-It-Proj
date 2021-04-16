void setup() {
  // put your setup code here, to run once:
  // Power inputs
  pinMode(8, INPUT);    // Push Button  
  pinMode(7, INPUT);    // Mic

  // Game outputs
  pinMode(9, OUTPUT);   // Speaker
  pinMode(1, OUTPUT);   // Green LED
  pinMode(3, OUTPUT);   // Red LED  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(3,LOW);
  if(digitalRead(7) == LOW){
    digitalWrite(3, HIGH);
    delay(50);
    digitalWrite(3, LOW);
    delay(50);
  }
}
