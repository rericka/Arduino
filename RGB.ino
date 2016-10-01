// Sketch para controlar un led RGB con un
// mando a distancia IR con protocolo NEC

#include <Arduino.h> //Libreria antes llamada Wprogram.h
#include <NECIRrcv.h> //Libreria del protocolo NEC
#define IRPIN 8 // Pin del receptor IR

NECIRrcv ir(IRPIN);

int rojo = 9;  //Pin del color ROJO del led RGB
int verde = 10; //Pin del color VERDE del led RGB
int azul = 11; //Pin del color AZUL del led RGB

long power = 4228087680;  //Codigo correspondiente al boton POWER del mando a distancia
long butrojo = 4161240960; //Codigo correspondiente al boton 1 del mando a distancia
long butverde = 4194664320; //Codigo correspondiente al boton 2 del mando a distancia
long butazul = 4177952640; //Codigo correspondiente al boton 3 del mando a distancia

void setup()
{
  //Serial.begin(9600); //Iniciamos comunicacion serie
  
  ir.begin(); //Iniciamos la recepcion IR
  
  pinMode(rojo, OUTPUT);
  pinMode(verde,OUTPUT);
  pinMode(azul, OUTPUT);
}

void loop()
{
  unsigned long ircode; //Variable que contendra el codigo decimal del boton pulsado
  
  while (ir.available()) 
  {
    ircode = ir.read(); //Leemos el codigo del boton pulsado
    
     if (ircode == power) //Si el boton de power... apagamos el led
     {
       digitalWrite(rojo, LOW);
       digitalWrite(verde, LOW);
       digitalWrite(azul, LOW);
     }
     else if (ircode == butrojo) digitalWrite(rojo,HIGH);  //Si boton 1, encendemos color rojo
     else if (ircode == butverde) digitalWrite(verde,HIGH); //Si boton 2, encendemos color verde
     else if (ircode == butazul) digitalWrite(azul,HIGH); //Si boton 3, encendemos color azul
  }
}
