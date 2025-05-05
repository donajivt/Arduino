#include <Servo.h>

Servo servoMotor;

void setup() {
  servoMotor.attach(9); // Pin donde está conectado el servo
  Serial.begin(9600);   // Inicializa la comunicación serial a 9600 bps
}

void loop() {
  if (Serial.available() > 0) {
    int angle = Serial.parseInt(); // Lee el ángulo enviado desde C++
    angle = constrain(angle, 0, 180); // Asegura que el ángulo esté dentro del rango permitido
    servoMotor.write(angle); // Mueve el servo al ángulo especificado
  }
}
