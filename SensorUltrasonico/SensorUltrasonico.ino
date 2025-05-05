double t,d;
void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(3,HIGH);
  delay(10);
  digitalWrite(3,LOW);
  t = pulseIn(2,HIGH);
  Serial.print("\n");
  Serial.print("\t");
  Serial.print("Tiempo en retornar la señal: ");
  Serial.print(t);
  d = t/58.2;
  Serial.print("\n");
  Serial.print("\t");
  Serial.print("Distancia con el objeto: ");
  Serial.print(d);
  delay(200);
}
