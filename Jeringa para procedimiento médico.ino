// Incluye las librerías necesarias para usar el sensor de distancia VL6180X, la pantalla OLED SSD1306 y las comunicaciones I2C y SPI
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Adafruit_VL6180X.h"

// Crea los objetos display y vl para controlar la pantalla y el sensor respectivamente
Adafruit_SSD1306 display = Adafruit_SSD1306();
Adafruit_VL6180X vl = Adafruit_VL6180X();

// Define las variables globales que se usarán en el programa
int fsr = A0;           // Pin analógico donde se conecta el sensor de fuerza FSR
int lectura;            // Variable para almacenar la lectura del sensor FSR
int conv;               // Variable para almacenar la conversión de la lectura a Newtons
int ultimaLectura = 0;  // Variable para almacenar la última lectura del sensor FSR
int button = 13;        // Pin digital donde se conecta el botón
int buzzer = 9;         // Pin digital donde se conecta el buzzer
float distancia;        // Variable para almacenar la distancia medida por el sensor VL6180X
float volumen;          // Variable para almacenar el volumen calculado a partir de la distancia
bool congelado = false; // Variable para indicar si el volumen está congelado o no
bool sonando = false;   // Variable para indicar si el buzzer está sonando o no
unsigned long tiempoCongelado = 0; // Variable para almacenar el tiempo en que se congeló el volumen

// Función que se ejecuta una sola vez al iniciar el programa
void setup()
{
 Serial.begin(9600); // Inicia la comunicación serial a 9600 baudios
 pinMode(button, INPUT); // Configura el pin del botón como entrada
 pinMode(buzzer, OUTPUT); // Configura el pin del buzzer como salida
//
 vl.begin(); // Inicia el sensor VL6180X

 display.begin(0x3C); // Inicia la pantalla OLED con la dirección I2C 0x3C
 display.display();
 //
 delay(1000); // Espera un segundo
}

// Función que se ejecuta en bucle después del setup
void loop()
{
 lectura = analogRead(fsr); // Lee el valor analógico del sensor FSR
 conv = map(lectura, 0, 883, 0, 21); // Convierte el valor leído a Newtons usando una función lineal
 Serial.println("Conv");
 Serial.println(conv); // Imprime el valor de la fuerza en Newtons en el monitor serial
  
 //distancia = vl.readRange(); // Lee la distancia en milímetros del sensor VL6180X
 volumen = (61-distancia)/10; // Calcula el volumen en mililitros a partir de la distancia
 Serial.println("Vol");
 Serial.println(volumen); // Imprime el valor del volumen en mililitros en el monitor serial

 if (!congelado || millis() - tiempoCongelado < 5000) { // Si el volumen no está congelado o si han pasado menos de 5 segundos desde que se congeló
    display.clearDisplay(); // Borra la pantalla
    display.setTextSize(1); // Establece el tamaño del texto a 1
    display.setTextColor(SSD1306_WHITE); // Establece el color del texto a blanco

    display.setCursor(0, 0); // Posiciona el cursor en la esquina superior izquierda
    display.print("Fuerza(N): "); // Imprime el texto "Fuerza(N): "
    display.print(conv); // Imprime el valor de la fuerza

    display.setCursor(0, 10); // Posiciona el cursor en la segunda línea
    display.print("Distancia(Mm): "); // Imprime el texto "Distancia(Mm): "
    display.println(distancia); // Imprime el valor de la distancia y salta a la siguiente línea

    display.setCursor(0, 20); // Posiciona el cursor en la tercera línea
    display.print("Volumen (ml): "); // Imprime el texto "Volumen (ml): "
    display.println(volumen); // Imprime el valor del volumen y salta a la siguiente línea
    display.display(); // Actualiza la pantalla con el contenido del buffer
 }

 if (digitalRead(button) == HIGH) { // Si se presiona el botón
    if (conv >= 18 && conv <= 20) { // Si la fuerza está entre 18 y 20 Newtons
      if (!congelado) { // Si el volumen no estaba congelado
        tiempoCongelado = millis(); // Guarda el tiempo actual en la variable tiempoCongelado
      }
      congelado = true; // Establece la variable congelado a verdadero
    }
 }
 else{ // Si no se presiona el botón
    congelado = false; // Establece la variable congelado a falso
 }

 if (congelado && tiempoCongelado != 0 && millis() - tiempoCongelado >= 5000) { // Si el volumen está congelado, el tiempoCongelado es distinto de cero y han pasado más de 5 segundos desde que se congeló
    tone(buzzer, 440); // Emite un tono de 440 Hz en el buzzer
    delay(50); // Espera 50 milisegundos
    noTone(buzzer); // Deja de emitir el tono
    delay(1000); // Espera un segundo
    tiempoCongelado = 0; // Resetea la variable tiempoCongelado a cero
 }
  
 delay(100); // Espera 100 milisegundos
} 
