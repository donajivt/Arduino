int pR,pV,pA, valor;
void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  pR= analogRead(A0);
  pV= analogRead(A1);
  pA= analogRead(A2);
  Serial.println("\n");
  //Manipulacion del LED RGB color Rojo.
  Serial.println("Valor del potenciometro Rojo: ");
  valor = map(pR,0,1023,0,255);
  Serial.println(valor);
  analogWrite(11,valor);
  Serial.println("\n");
  //Manipulacion del LED RGB color Verde.
  Serial.println("Valor del potenciometro Verde: ");
  valor = map(pV,0,1023,0,255);
  Serial.println(valor);
  analogWrite(10,valor);
  Serial.println("\n");
  //Manipulacion del LED RGB color Azul.
  Serial.println("Valor del potenciometro Azul: ");
  valor = map(pA,0,1023,0,255);
  Serial.println(valor);
  analogWrite(9,valor);
  delay(800);
}
