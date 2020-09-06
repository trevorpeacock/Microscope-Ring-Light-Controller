//https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boards-manager/package_damellis_attiny_index.json

#define BUTTON_PIN 3
#define LED_EN_PIN 1

class ButtonManager
{
  public:
    ButtonManager() {
      _btn_laststate = false;
      _first_touch = millis();
    }
    bool check() {
      int btnstate;
      btnstate = not digitalRead(BUTTON_PIN);
      if(_btn_laststate) {
        _btn_laststate = btnstate;
        return false;
      }
      _btn_laststate = btnstate;
      if(btnstate) {
        if(millis() - _first_touch > 200) {
          _first_touch = millis();
          return true;
        }
        return false;
      }
      return false;
    }
  private:
    bool _btn_laststate;
    unsigned long _first_touch;
};

ButtonManager button_manager;

uint8_t brigntness_states[] = {0, 16, 64, 128, 255};
#define brigntness_states_len 5
uint8_t brightness_state;

void setup() {
  pinMode(LED_EN_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  delay(200);
  for(int i = 15; i <= 255; i += 16) {
    analogWrite(LED_EN_PIN, i);
    delay(40);
  }
  for(int i = 255; i > 0; i -= 16) {
    analogWrite(LED_EN_PIN, i);
    delay(40);
  }
  brightness_state = 0;
  analogWrite(LED_EN_PIN, brigntness_states[brightness_state]);
}

void loop() {
  if(button_manager.check()) {
    brightness_state++;
    if(brightness_state==brigntness_states_len)
      brightness_state=0;
    analogWrite(LED_EN_PIN, brigntness_states[brightness_state]);
  }
}
