const int trigPin = 3;
const int echoPin = 2;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  char letra = Serial.read();
  if(letra == 'e'){
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
    Serial.println("Encendido");
    //delay(1000);
  } else if(letra == 'a'){
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("Apagado");
    //delay(1000);
  }
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lee la duración del pulso de eco
  long duration = pulseIn(echoPin, HIGH);

  // Calcula la distancia en centímetros
  int distance = duration * 0.034 / 2;

  // Muestra la distancia en el Monitor Serie
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(2500);
}
