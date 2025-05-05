

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  for(int j=13;j>4;j--){
    digitalWrite(j,HIGH);
    delay(200);
    digitalWrite(j,LOW);
    delay(200);
  }
  for(int j=4;j<13;j++){
    digitalWrite(j,HIGH);
    delay(200);
    digitalWrite(j,LOW);
    delay(200);
  }
}
