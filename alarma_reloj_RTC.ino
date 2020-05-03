// Made by: Juan Rodrigo Guzman Martinez

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc; // Declaramos RTC_DS3231 como rtc

LiquidCrystal_I2C lcd(0x27,16,2); // Declaramos LiquidCrystal_I2C como lcd, ponemos de cuantas filas y columnas es la pantlla

int buzzer= 2; // Declaramos el pin 2 con el nombre de buzzer

void setup() {
lcd.backlight(); // Usamos la luz de fondo de la pantalla LCD
lcd.init(); // Inicializamos la pantalla LCD
Serial.begin(9600); // Inicializamos el monitor serial a 9600 baudios
rtc.begin(); // Inicializamos el modulo RTC
//rtc.adjust(DateTime(__DATE__, __TIME__)); // obtenemos datos y fechas de computador donde se carga el programa,en la segunda carga de codigo comente esta instruccion
pinMode(buzzer, OUTPUT);
}

void loop() {
DateTime fecha = rtc.now(); // Obtenemos los datos y la fecha

if(fecha.hour()==20 && fecha.minute()==46){ // (condicional) si son las 8:00 entonces active el timbre 
timbre(); // Llamamos a la funcion timbre
texto(); // Llmamos a la funcion texto
}

else{ // si la condicional no se da entonces imprima la hora y fecha actual
digitalWrite(buzzer,0);
lcd.clear();
lcd.setCursor(4,0);
lcd.print(fecha.day());
lcd.print("/");
lcd.print(fecha.month());
lcd.print("/");
lcd.print(fecha.year());
lcd.setCursor(4,1);
lcd.print(fecha.hour());
lcd.print(":");
lcd.print(fecha.minute());
lcd.print(":");
lcd.print(fecha.second());
}

{ // Imprimimos la hora y fecha por el monitor serial
Serial.print(fecha.day());
Serial.print("/");
Serial.print(fecha.month());
Serial.print("/");
Serial.print(fecha.year());
Serial.print("/");
Serial.print(fecha.hour());
Serial.print(":");
Serial.print(fecha.minute());
Serial.print(":");
Serial.println(fecha.second());
delay(1000);
}

}
////////////////////// Funciones////////////////////////////////////

void timbre(){ // si se cumple la condicional entonces ejecuta esta funcion
digitalWrite(buzzer,1);
delay(100);
digitalWrite(buzzer,0);
delay(100);
}

void texto(){ // si se cumple la condicional entonces ejecuta esta funcion
lcd.clear();
lcd.print("    Alarma!!!  ");
delay(100);
}
