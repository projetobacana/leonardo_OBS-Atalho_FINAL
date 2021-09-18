/* *************************
 *  Projeto Bacana - 09/2021
 *  www.projetobacana.com.br
 *  Júlio Vansan Gonçalves
 *  
 *  https://www.arduino.cc/reference/en/language/functions/usb/keyboard/
 *  
 *  ************************
 */

#include "Keyboard.h"

const int LED=13;

const int bt01=8;
const int bt02=A3;
const int bt03=A4;
const int bt04=A5;
const int bt05=9;
const int bt06=A2;
const int bt07=10;
const int bt08=A1;
const int bt09=11;
const int bt10=12;
const int bt11=A0;


void setup() {
  Serial.begin(9600); // Habilita a comunicação serial
  pinMode(LED,OUTPUT);
  pinMode(bt01,INPUT_PULLUP);
  pinMode(bt02,INPUT_PULLUP);
  pinMode(bt03,INPUT_PULLUP);
  pinMode(bt04,INPUT_PULLUP);
  pinMode(bt05,INPUT_PULLUP);
  pinMode(bt06,INPUT_PULLUP);
  pinMode(bt07,INPUT_PULLUP);
  pinMode(bt08,INPUT_PULLUP);
  pinMode(bt09,INPUT_PULLUP);
  pinMode(bt10,INPUT_PULLUP);
  pinMode(bt11,INPUT_PULLUP);
  
  Keyboard.begin();
Serial.println("Iniciando");
}

void loop() {
   if (digitalRead(bt01) == LOW) {
      enviaMacro('8',bt01);
    }//Botão 1
   if (digitalRead(bt02) == LOW) {
    enviaMacro('6',bt02);
  }//Botão 2
   if (digitalRead(bt03) == LOW) {
    enviaMacro('3',bt03);
  }//Botão 3
  if (digitalRead(bt04) == LOW) {
    enviaMacro('1',bt04);
  }//Botão 4
  if (digitalRead(bt05) == LOW) {
    enviaMacro('9',bt05);
  }//Botão 5
  if (digitalRead(bt06) == LOW) {
    enviaMacro('7',bt06);
  }//Botão 6
  if (digitalRead(bt07) == LOW) {
    enviaMacro('4',bt07);
  }//Botão 7
  if (digitalRead(bt08) == LOW) {
    enviaMacro('2',bt08);
  }//Botão 8
   
 if (digitalRead(bt09) == LOW) {
    Serial.println("ctrl_C Enviado");
    digitalWrite(LED,HIGH);   
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('c');
    delay(100);
    Keyboard.releaseAll();
    while(digitalRead(bt09) == LOW) {
      delay(50);
    }
    digitalWrite(LED,LOW);
  }//Botão 9
  if (digitalRead(bt10) == LOW) {
    Serial.println("ctrl_V Enviado");
    digitalWrite(LED,HIGH);   
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('v');
    delay(100);
    Keyboard.releaseAll();
    while(digitalRead(bt10) == LOW) {
      delay(50);
    }
    digitalWrite(LED,LOW);
  }//Botão 10
  
 if (digitalRead(bt11) == LOW) {
    enviaMacro(']',bt11);
  }//Botão 11
  
  delay(30);

}//loop

void enviaMacro(char teclaFuncao, int porta){
    digitalWrite(LED,HIGH);     
    //Keyboard.write(teclaFuncao);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_SHIFT);
   // Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(teclaFuncao);
    delay(100);
    Keyboard.releaseAll();
    Serial.print(teclaFuncao);
    Serial.println(" Enviada");
    while(digitalRead(porta) == LOW) {
      delay(30);
    }
    digitalWrite(LED,LOW);
}//enviaMacro
