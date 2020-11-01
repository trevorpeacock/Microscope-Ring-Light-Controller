
class MenuEdit
{
  public:
    MenuEdit() {
    }
    int setup() {
    }
    int enter() {
      button_manager.wait_for_release();
      _led_switch = millis();
      _led_state = true;
    }
    void loop() {
      switch(menu_mode) {
        case MENU_MODE_EDIT_1:
          digitalWrite(LED1_PIN, _led_state);
          digitalWrite(LED2_PIN, false);
          digitalWrite(LED3_PIN, true);
          break;
        case MENU_MODE_EDIT_2:
          digitalWrite(LED1_PIN, true);
          digitalWrite(LED2_PIN, false);
          digitalWrite(LED3_PIN, _led_state);
          break;
      }
      if(_led_state) {
        if(millis() - _led_switch > 200) {
          _led_state = false;
          _led_switch = millis();
        }
      } else {
        if(millis() - _led_switch > 200) {
          _led_state = true;
          _led_switch = millis();
        }
      }
      switch(button_manager.check_repeat(true, false, true)) {
        case 1:
          switch(menu_mode) {
            case MENU_MODE_EDIT_1:
              motor1_control.set(motor1_control.get_speed()-1);
              break;
            case MENU_MODE_EDIT_2:
              motor2_control.set(motor2_control.get_speed()-1);
              break;
          }
          break;
        case 2:
          eeprom_settings.mot1_speed = motor1_control.get_speed();
          eeprom_settings.mot2_speed = motor2_control.get_speed();
          save_eeprom();
          switch_menu(MENU_MODE_ON);
          break;
        case 3:
          switch(menu_mode) {
            case MENU_MODE_EDIT_1:
              motor1_control.set(motor1_control.get_speed()+1);
              break;
            case MENU_MODE_EDIT_2:
              motor2_control.set(motor2_control.get_speed()+1);
              break;
          }
          break;
      }
    }
  private:
    unsigned long _led_switch;
    bool _led_state;
};
