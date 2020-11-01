
class MenuOn
{
  public:
    MenuOn() {
    }
    int setup() {
    }
    int enter() {
      _led_switch = millis();
      _led_state = true;
    }
    void loop() {
      motor1_control.set(eeprom_settings.mot1_speed);
      motor2_control.set(eeprom_settings.mot2_speed);
      digitalWrite(LED1_PIN, true);
      digitalWrite(LED2_PIN, false);
      digitalWrite(LED3_PIN, true);
      switch(button_manager.check_repeat(false, false, false)) {
        case 1:
          switch_menu(MENU_MODE_EDIT_1);
          break;
        case 2:
          switch_menu(MENU_MODE_SLEEP);
          break;
        case 3:
          switch_menu(MENU_MODE_EDIT_2);
          break;
      }
    }
  private:
    unsigned long _led_switch;
    bool _led_state;
};
