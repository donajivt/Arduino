#include <Servo.h> 

Servo servo; // Declaración del objeto servo

void setup() {
  Serial.begin(9600); // Inicializa la comunicación serial a 9600 bps
  servo.attach(9); // Conecta el servo al pin 9
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil(','); // Lee los datos del puerto serial hasta encontrar una coma
    int servoIndex = data.toInt(); // Convierte el primer valor a entero (número de servo)
    int position = Serial.parseInt(); // Lee el segundo valor como un entero (posición del servo)
    
    // Mueve el servo correspondiente a la posición especificada
    switch (servoIndex) {
      case 1:
        servo.write(position);
        break;
      default:
        break;
    }
  }
}
