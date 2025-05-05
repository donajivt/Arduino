#include <Servo.h>

Servo servo1; // Declaración del objeto servo1
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

void setup() {
  Serial.begin(9600); // Inicializa la comunicación serial a 9600 bps
  servo1.attach(9); // Conecta el servo 1 al pin 9
  servo2.attach(10); // Conecta el servo 2 al pin 10
  servo3.attach(11); // Conecta el servo 3 al pin 11
  servo4.attach(12); // Conecta el servo 4 al pin 12
  servo5.attach(13); // Conecta el servo 5 al pin 13
}

void loop() {
  // Verifica si hay datos disponibles en el puerto serial
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n'); // Lee los datos del puerto serial hasta encontrar un salto de línea
    Serial.print("Datos recibidos: ");
    Serial.println(data); // Imprime los datos recibidos para depuración

    // Analiza los datos recibidos
    char servoIndex = data.charAt(0); // Obtener el índice del servo
    int position = data.substring(2).toInt(); // Obtener la posición del servo como un entero

    Serial.print("Recibido: Servo ");
    Serial.print(servoIndex);
    Serial.print("Posición: ");
    Serial.println(position);

    // Mover el servo correspondiente a la posición especificada
    switch (servoIndex) {
      case 'A':
        servo1.write(position);
        break;
      case 'B':
        servo2.write(position);
        break;
      case 'C':
        servo3.write(position);
        break;
      case 'D':
        servo4.write(position);
        break;
      case 'E':
        servo5.write(position);
        break;
      default:
        break;
    }
  }
}