
int servo1 = 9;
int userValue = 0;
int prevValue = 0;

void setup() {
  pinMode(servo1, OUTPUT);
  Serial.begin(9600); // Iniciar comunicación serial a 9600 baudios
}

void loop() {
  // Preguntar al usuario por un valor entero
  Serial.println("Por favor, ingresa un valor de angulo");
  while (Serial.available() == 0) {
    // Esperar hasta que el usuario ingrese un valor
  }
  
  // Leer el valor ingresado por el usuario
  userValue = Serial.parseInt();
  userValue = userValue * (255-42)/180 + 42;
  
  // Asegurarse de que el valor esté en el rango válido (0-255)
  userValue = constrain(userValue, 0, 255);
  
  // Establecer el valor del servo solo si es diferente al valor anterior
  if (userValue != prevValue) {
    if (prevValue < userValue) {
      for (int i = prevValue; i <= userValue; i++) {
        analogWrite(servo1, i);
        delay(10); // Agregar un pequeño retraso para que el servo tenga tiempo de moverse
      }
    } else if (prevValue > userValue) {
      for (int i = prevValue; i >= userValue; i--) {
        analogWrite(servo1, i);
        delay(10); // Agregar un pequeño retraso para que el servo tenga tiempo de moverse
      }
    }
    prevValue = userValue; // Actualizar el valor previo
  }
  
  // Esperar un breve período de tiempo antes de repetir el ciclo
  delay(1000); // Puedes ajustar este valor según sea necesario
}

//143 es 90 grados
//255 es 180 grados
//no se mueve hasta los 42
