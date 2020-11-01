#include "eeprom.h"

#define LED1_PIN 2
#define LED2_PIN 3
#define LED3_PIN 4
#define BUTTON_PIN A2
#define MOT1_EN_PIN A4
#define MOT2_EN_PIN A3
#define MOT1_PWM_PIN 9
#define MOT2_PWM_PIN 10
#define MOT1_TACH_PIN A0
#define MOT2_TACH_PIN A1

#define BUTTON_READINGS 8

const word PWM_FREQ_HZ = 20000; //Adjust this value to adjust the frequency
const word TCNT1_TOP = F_CPU/(2*PWM_FREQ_HZ);

class ButtonManager
{
  public:
    ButtonManager() {
      for(uint8_t i = 0; i < BUTTON_READINGS; i++) {
        _btn_laststate[i]=1023;
      }
      _btn_laststate_count = 0;
      _btn_down = false;
      _last_trigger = millis();
    }
    int readval() {
      int btnstate;
      btnstate = analogRead(BUTTON_PIN);
      _btn_laststate[_btn_laststate_count++]=btnstate;
      if(_btn_laststate_count == BUTTON_READINGS) _btn_laststate_count=0;
      return btnstate;
    }
    int avgval() {
      int total = 0;
      for(uint8_t i = 0; i < BUTTON_READINGS; i++) {
        total += _btn_laststate[i];
      }
      return total / BUTTON_READINGS;
    }
    uint8_t check() {
      int btnstate = this->readval();
      if(abs(this->avgval() - btnstate) > 10) return 0;
      if(btnstate < 256) return 1;
      if(btnstate < 600) return 2;
      if(btnstate < 800) return 3;
      return 0;
    }
    uint8_t check_repeat(bool rpt1, bool rpt2, bool rpt3) {
      int btnstate = this->check();
      //no button pressed
      if(btnstate==0) {
        _btn_down = false;
        return 0;
      }
      
      bool new_press = not _btn_down;
      _btn_down = true;
      if(millis() - _last_down_state < 50) new_press = false;
      _last_down_state = millis();
      
      if(btnstate == 1 && not rpt1) {
        if(new_press) return btnstate;
        return 0;
      }
      if(btnstate == 2 && not rpt2) {
        if(new_press) return btnstate;
        return 0;
      }
      if(btnstate == 3 && not rpt3) {
        if(new_press) return btnstate;
        return 0;
      }
      if(millis() - _last_trigger > 50) {
        _last_trigger = millis();
        return btnstate;
      }
      return 0;
    }
    void wait_for_release() {
      unsigned long last_press = millis();
      while(millis() - last_press < 50) {
        if(this->check()) last_press = millis();
      }
    }
  private:
    int _btn_laststate[BUTTON_READINGS];
    uint8_t _btn_laststate_count;
    bool _btn_down;
    unsigned long _last_trigger;
    unsigned long _last_down_state;
};

class MotorControl
{
  public:
    MotorControl(uint8_t mot) {
      _mot = mot;
      if(_mot==0) {
        _en_pin = MOT1_EN_PIN;
        _pwm_pin = MOT1_PWM_PIN;
        _tach_pin = MOT1_TACH_PIN;
        _ocr = &OCR1A;
      } else if(_mot==1) {
        _en_pin = MOT2_EN_PIN;
        _pwm_pin = MOT2_PWM_PIN;
        _tach_pin = MOT2_TACH_PIN;
        _ocr = &OCR1B;
      }
    }
    int setup() {
      pinMode(_en_pin, OUTPUT);
      pinMode(_pwm_pin, OUTPUT);
      pinMode(_tach_pin, INPUT);
    
      // Clear Timer1 control and count registers
      TCCR1A = 0;
      TCCR1B = 0;
      TCNT1  = 0;
    
      // Set Timer1 configuration
      // COM1A(1:0) = 0b10   (Output A clear rising/set falling)
      // COM1B(1:0) = 0b00   (Output B normal operation)
      // WGM(13:10) = 0b1010 (Phase correct PWM)
      // ICNC1      = 0b0    (Input capture noise canceler disabled)
      // ICES1      = 0b0    (Input capture edge select disabled)
      // CS(12:10)  = 0b001  (Input clock select = clock/1)
      
      TCCR1A |= (1 << COM1A1) | (1 << COM1B1) | (1 << WGM11);
      TCCR1B |= (1 << WGM13) | (1 << CS10);
      ICR1 = TCNT1_TOP;
    }
    void set(int spd) {
      if(spd<0) spd=0;
      if(spd>101) spd=101;
      _cur_speed = spd;
      if(_cur_speed==0) {
        *_ocr = (word) 0;
        digitalWrite(_en_pin, LOW);
        return;
      }
      *_ocr = (word) ((_cur_speed-1)*TCNT1_TOP)/100;
      digitalWrite(_en_pin, HIGH);
    }
    uint8_t get_speed() {
      return _cur_speed;
    }
  private:
    uint8_t _mot;
    uint8_t _en_pin;
    uint8_t _pwm_pin;
    uint8_t _tach_pin;
    uint16_t *_ocr;
    uint8_t _cur_speed;
};

ButtonManager button_manager;
MotorControl motor1_control(0);
MotorControl motor2_control(1);
