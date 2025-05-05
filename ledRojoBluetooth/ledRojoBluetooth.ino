char val;
int ledRojo =13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledRojo,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  val = Serial.read(); //lee el valor enviado por el Bloetooth

  if( val == 'A' ){ //si es A, enciende el led
    digitalWrite(ledRojo, HIGH);
  }
  if( val == 'B' ){ //si es B, apaga el led
    digitalWrite(ledRojo, LOW);
  }
}
