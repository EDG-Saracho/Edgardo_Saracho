#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inicialización de la pantalla LCD I2C con la dirección 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Definición de pines
const int TRIG = 13;
const int ECHO = 12;
const int LED = 5;
const int pinBuzzer = 9;
long duracion;
int distancia;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);

  lcd.init(); // Inicializa el LCD
  lcd.backlight(); // Enciende la luz de fondo
  lcd.print("Inicializando...");

  delay(2000); // Espera 2 segundos para que el mensaje se vea
  lcd.clear();
}

void loop() {
  // Generar pulso de ultrasonido
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Leer el tiempo de duración del pulso
  duracion = pulseIn(ECHO, HIGH);

  // Calcular la distancia en centímetros
  distancia = duracion * 0.034 / 2;

  // Mostrar mensaje en la pantalla LCD según la distancia
  if (distancia < 1) {
    lcd.clear();
    lcd.setCursor(0, 0); // Colocar el cursor en la primera línea
    lcd.print("hombre sexy");
    lcd.setCursor(0, 1); // Colocar el cursor en la segunda línea
    lcd.print("cerca");
    tone(pinBuzzer, 1200);
    digitalWrite(LED, HIGH);
    delay(300); // Tiempo de luz encendida
    noTone(pinBuzzer);
    digitalWrite(LED, LOW);
    delay(300); // Tiempo de luz apagada
  } else {
    lcd.clear(); // Apaga la pantalla LCD
    digitalWrite(LED, LOW);
    noTone(pinBuzzer);
  }

  delay(100); // Pequeño retardo antes de la próxima lectura
}
