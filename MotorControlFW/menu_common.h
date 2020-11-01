enum MENU_MODE {
  MENU_MODE_SLEEP,
  MENU_MODE_ON,
  MENU_MODE_EDIT_1,
  MENU_MODE_EDIT_2
};

int menu_mode;
bool menu_enter = false;

void switch_menu(int menu) {
  menu_mode = menu;
  menu_enter = true;
}
