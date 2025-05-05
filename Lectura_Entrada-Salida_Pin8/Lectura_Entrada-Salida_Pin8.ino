void setup() {
  // put your setup code here, to run once:
  pinMode(8, INPUT); //entrada INPUT
  pinMode(9, OUTPUT); //salida OUTPUT
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int dato=0;
  dato = digitalRead(8); //guardar la condición de estado del pin 8
  Serial.println(dato);
  
  if(dato == 1){
  	digitalWrite(9,HIGH);
    
  }else{
  	digitalWrite(9,LOW);
  }
}
