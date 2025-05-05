int led = 8;
void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0 ){
    char data = Serial.read(); // y o n de python
    if(data == 'y'){
      digitalWrite(led,HIGH);

    }
    else if(data == 'n'){
      digitalWrite(led,LOW);
    }
  }
}
