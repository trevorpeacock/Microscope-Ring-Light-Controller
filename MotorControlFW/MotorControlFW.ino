// https://github.com/arduino/Arduino/wiki/Unofficial-list-of-3rd-party-boards-support-urls
// https://raw.githubusercontent.com/carlosefr/atmega/master/package_carlosefr_atmega_index.json

//Board: ATmega328/328p
//Processor: ATmega328p
//Clock: External 20MHz

//avrdude -cusbtiny -p ATmega328p -U lfuse:w:0xf7:m
#include "common.h"
#include "menus.h"

void setup() {
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  motor1_control.setup();
  motor2_control.setup();
  //motor1_control.set(1);
  //delay(1000);
  //motor1_control.set(0);
  //motor2_control.set(1);
  //delay(1000);
  //motor2_control.set(0);
  init_menus();
  load_eeprom();
}

void loop() {
  menu_run();
  return;
  switch(button_manager.check()) {
    case 0:
      digitalWrite(LED1_PIN, LOW);
      digitalWrite(LED2_PIN, LOW);
      digitalWrite(LED3_PIN, LOW);
      break;
    case 1:
      digitalWrite(LED1_PIN, HIGH);
      digitalWrite(LED2_PIN, LOW);
      digitalWrite(LED3_PIN, LOW);
      break;
    case 2:
      digitalWrite(LED1_PIN, LOW);
      digitalWrite(LED2_PIN, HIGH);
      digitalWrite(LED3_PIN, LOW);
      break;
    case 3:
      digitalWrite(LED1_PIN, LOW);
      digitalWrite(LED2_PIN, LOW);
      digitalWrite(LED3_PIN, HIGH);
      break;
  }
}
