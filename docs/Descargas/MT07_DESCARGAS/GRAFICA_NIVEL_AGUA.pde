import processing.serial.*;  // Importa la biblioteca para manejar la conexión serial
Serial myPort;               // Objeto para la conexión serial
int sensorValue = 0;         // Valor del sensor de agua
int maxWaterLevel = 800;     // Máximo nivel de agua

void setup() {
  size(500, 200);           // Tamaño de la ventana

  // Inicializa la fuente por defecto en tamaño grande
  textSize(32);             // Tamaño del texto
  textAlign(CENTER, CENTER); // Alineación del texto
  // No se aplica estilo de negrita, solo el tamaño
  println(Serial.list());
  myPort = new Serial(this, Serial.list()[0], 115200); // Cambia el índice si es necesario
}

void draw() {
  background(255);  // Fondo blanco

  // Si hay datos disponibles en el puerto serie
  while (myPort.available() > 0) {
    String input = myPort.readStringUntil('\n');
    if (input != null) {
      input = input.trim();
      // Intenta convertir el valor recibido a un número
      try {
        sensorValue = int(input);
      } catch (NumberFormatException e) {
        println("Error en la lectura del valor del sensor");
      }
    }
  }

  // Dibuja el rectángulo horizontal que representa el nivel de agua
  noStroke();
  float rectWidth = map(sensorValue, 0, maxWaterLevel, 0, width);  // Mapea el valor del sensor al ancho del rectángulo
  // Cambia de celeste claro a violeta oscuro
  color c = lerpColor(color(173, 216, 230), color(128, 0, 128), map(sensorValue, 0, maxWaterLevel, 0, 1));  // De celeste a violeta
  fill(c);  // Establece el color
  rect(0, height / 2 - 25, rectWidth, 50);  // Dibuja el rectángulo

  // Muestra el valor del sensor como texto en el centro
  fill(0);
  text("Nivel de agua: " + sensorValue, width / 2, height / 4);
}
