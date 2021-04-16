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
  bool in = digitalRead(6);
  bool new_in;
  digitalWrite(3, LOW);
  do{
    new_in = digitalRead(6);
  }while(new_in == in);
  digitalWrite(3, HIGH);
  delay(50);
}
