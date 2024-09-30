#include <Arduino.h>

const int xPin = A0;  // Conectar al eje X del joystick
const int yPin = A1;  // Conectar al eje Y del joystick
const int swPin = 2;  // Conectar al pin SW del joystick

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT_PULLUP);  // Configura el pin SW como entrada con pull-up interno
}

void loop() {
  int joyX = analogRead(xPin);
  int joyY = analogRead(yPin);
  int swState = digitalRead(swPin);  // Leer el estado del botón (HIGH o LOW)

  // Normalizar los valores del joystick a un rango de -1 a 1
  float normX = map(joyX, 0, 1023, -100, 100) / 100.0;
  float normY = map(joyY, 0, 1023, -100, 100) / 100.0;

  // Enviar los valores por el puerto serial
  Serial.print(normX);
  Serial.print(",");
  Serial.print(normY);
  Serial.print(",");

  // Verificar si el botón está presionado
  if (swState == LOW) {
    Serial.println("Pressed");
  } else {
    Serial.println("Not Pressed");
  }

  delay(50);
}
