#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Crear el objeto LCD con la dirección I2C encontrada (sustituye 0x27 si es necesario)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pines del joystick
const int VRx = A0;
const int VRy = A1;
const int SW = 8;

// Servo
Servo servo_9;

void setup() {
  // Configuración de los pines del joystick
  pinMode(SW, INPUT_PULLUP);

  // Inicializar la pantalla LCD
  lcd.init();
  lcd.backlight();
  lcd.print("Joystick LCD");

  // Inicializar el servo
  servo_9.attach(9, 500, 2500);

  // Esperar un segundo
  delay(1000);

  // Limpiar la pantalla
  lcd.clear();
}

void loop() {
  // Leer los valores del joystick y estado del botón
  int xPosition = analogRead(VRx);
  int yPosition = analogRead(VRy);
  int buttonState = digitalRead(SW);

  // Limpiar la pantalla
  lcd.clear();

  // Mover el cursor a la primera línea
  lcd.setCursor(0, 0);
  if (xPosition < 400) {
    lcd.print("PING");
  } else if (xPosition > 600) {
    lcd.print("PONG");
  } else if (yPosition < 400) {
    lcd.print("PING");
  } else if (yPosition > 600) {
    lcd.print("PONG");
  } else {
    lcd.print("CENTRO");
  }

  // Mostrar el estado del botón en la segunda línea
  lcd.setCursor(0, 1);
  if (buttonState == LOW) {
    lcd.print("Soltá Boludo ");
  } else {
    lcd.print("Dale movete");
  }

  // Controlar el servo con el joystick
  int servoPos = map(xPosition, 0, 1023, 0, 180); // Mapear la posición del joystick al rango del servo
  servo_9.write(servoPos); // Mover el servo a la posición correspondiente

  // Pequeño retraso para evitar parpadeo
  delay(200);
}
