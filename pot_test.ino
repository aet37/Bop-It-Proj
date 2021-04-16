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

  int initial_val = analogRead(3);
  int new_val;
  do{
    new_val = analogRead(3);
    digitalWrite(3,LOW);
  }while(new_val < initial_val+100 && new_val > initial_val-100);
  
  digitalWrite(3, HIGH);
  delay(100);
}
