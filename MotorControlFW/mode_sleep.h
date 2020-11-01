
class MenuSleep
{
  public:
    MenuSleep() {
    }
    int setup() {
    }
    int enter() {
      _led_switch = millis();
      _led_state = true;
    }
    void loop() {
      motor1_control.set(0);
      motor2_control.set(0);
      digitalWrite(LED1_PIN, false);
      digitalWrite(LED2_PIN, _led_state);
      digitalWrite(LED3_PIN, false);
      if(_led_state) {
        if(millis() - _led_switch > 100) {
          _led_state = false;
          _led_switch = millis();
        }
      } else {
        if(millis() - _led_switch > 1900) {
          _led_state = true;
          _led_switch = millis();
        }
      }
      if(button_manager.check_repeat(false, false, false)==2) switch_menu(MENU_MODE_ON);
    }
  private:
    unsigned long _led_switch;
    bool _led_state;
};
