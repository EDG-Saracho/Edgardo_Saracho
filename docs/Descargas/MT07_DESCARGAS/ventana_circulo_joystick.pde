import processing.serial.*;

Serial myPort;  // Objeto Serial para recibir los datos
float x, y;
int radius = 50;
String buttonState = "No Presionado";  // Estado inicial del botón en español
color circleColor;  // Color del círculo
color backgroundColor = color(255, 182, 213);  // Color de fondo (#ffb6d5)

void setup() {
  size(400, 400);
  
  // Listar todos los puertos disponibles
  String[] ports = Serial.list();
  println(ports);  // Imprimir la lista de puertos en la consola de Processing
  
  // Asegúrate de seleccionar el puerto correcto (ajusta el índice si es necesario)
  if (ports.length > 0) {
    myPort = new Serial(this, ports[0], 115200);
  } else {
    println("No se encontraron puertos seriales.");
  }
  
  x = width / 2;
  y = height / 2;
  circleColor = color(150, 0, 255);  // Color inicial del círculo
}

void draw() {
  background(backgroundColor);  // Establece el color de fondo
  
  // Dibuja el círculo en la posición calculada con el color dinámico
  fill(circleColor);
  noStroke();
  ellipse(x, y, radius, radius);
  
  // Muestra el estado del botón en español
  fill(0);
  textSize(16);
  text("Estado del Botón: " + buttonState, 10, height - 20);
  
  // Lee los datos del puerto serial si están disponibles
  while (myPort.available() > 0) {
    String message = myPort.readStringUntil('\n');  // Leer hasta el final de la línea
    if (message != null) {
      String[] values = split(trim(message), ',');
      if (values.length == 3) {
        // Parsear los valores de x e y
        float joyX = float(values[0]);
        float joyY = float(values[1]);
        buttonState = values[2].equals("Pressed") ? "Presionado" : "No Presionado";  // Traducir el estado del botón
        
        // Mapear los valores del joystick a la pantalla
        x = map(joyX, -1, 1, 0, width);
        y = map(joyY, -1, 1, 0, height);
        
        // Cambiar el color dependiendo de la posición del joystick
        circleColor = getColorBasedOnPosition(joyX, joyY);
      }
    }
  }
}

// Función para obtener el color basado en la posición del joystick
color getColorBasedOnPosition(float joyX, float joyY) {
  if (joyY < -0.5) {  // Norte (Rojo)
    return color(255, 0, 0);
  } else if (joyY > 0.5) {  // Sur (Violeta)
    return color(148, 0, 211);
  } else if (joyX > 0.5) {  // Este (Amarillo)
    return color(255, 255, 0);
  } else if (joyX < -0.5) {  // Oeste (Transición entre rojo y violeta)
    return lerpColor(color(255, 0, 0), color(148, 0, 211), map(joyX, -1, -0.5, 0, 1));
  } else {  // Intersecciones de los cuadrantes (mezcla de colores)
    return color(150, 0, 255);  // Color base
  }
}
