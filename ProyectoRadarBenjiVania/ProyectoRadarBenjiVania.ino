#include <Servo.h>

const int trigPin = 10;   // Pin de salida para el pulso de trigger del sensor ultrasónico
const int echoPin = 11;   // Pin de entrada para recibir el eco del sensor ultrasónico
const int servoPin = 12;  // Pin de control para el servo motor

long duration;            // Duración del pulso de eco del sensor ultrasónico
int distance;             // Distancia medida por el sensor ultrasónico
Servo myServo;            // Objeto del servo motor

void setup() {
  pinMode(trigPin, OUTPUT);  // Configura el pin de trigger como salida
  pinMode(echoPin, INPUT);   // Configura el pin de echo como entrada
  Serial.begin(9600);        // Inicializa la comunicación serial
  myServo.attach(servoPin);   // Adjunta el servo al pin correspondiente
}

void loop() {
  // Escaneo en un rango de 15 a 165 grados
  for (int i = 15; i <= 165; i++) {
    myServo.write(i);        // Gira el servo al ángulo actual (i)
    delay(30);               // Pequeña pausa para permitir que el servo alcance la posición
    distance = calculateDistance();  // Mide la distancia con el sensor ultrasónico
    printData(i, distance);   // Imprime los datos (ángulo, distancia) en el puerto serial
  }

  // Escaneo en reversa desde 165 grados hasta 15 grados
  for (int i = 165; i > 15; i--) {
    myServo.write(i);        // Gira el servo al ángulo actual (i)
    delay(30);               // Pequeña pausa para permitir que el servo alcance la posición
    distance = calculateDistance();  // Mide la distancia con el sensor ultrasónico
    printData(i, distance);   // Imprime los datos (ángulo, distancia) en el puerto serial
  }
}

// Función para medir la distancia con el sensor ultrasónico
int calculateDistance() {
  const int soundSpeed = 034;  // Velocidad del sonido en cm/µs
  digitalWrite(trigPin, LOW);  // Inicia el pulso de trigger
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);  // Termina el pulso de trigger
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);  // Mide la duración del pulso de eco
  distance = duration * 0.5 * soundSpeed / 10000;  // Calcula la distancia en centímetros
  return distance;
}

// Función para imprimir los datos en el puerto serial
void printData(int angle, int dist) {
  Serial.print(angle); 
  Serial.print(",");
  Serial.print(dist);
  Serial.print(".");
}