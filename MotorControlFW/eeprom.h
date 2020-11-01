struct EEPROM_SETTINGS {
    bool blank;
    uint8_t mot1_speed;
    uint8_t mot2_speed;
};

struct EEPROM_SETTINGS eeprom_settings;
struct EEPROM_SETTINGS EEMEM e_eeprom_settings;

void save_eeprom() {
    eeprom_busy_wait();
    eeprom_update_block(&eeprom_settings, &e_eeprom_settings, sizeof(struct EEPROM_SETTINGS));
}

void load_eeprom() {
    eeprom_busy_wait();
    eeprom_read_block(&eeprom_settings, &e_eeprom_settings, sizeof(struct EEPROM_SETTINGS));
    if(eeprom_settings.blank) {
      eeprom_settings.blank = false;
      eeprom_settings.mot1_speed = 1;
      eeprom_settings.mot2_speed = 1;
    }
}
