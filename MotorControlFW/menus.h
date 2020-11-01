#include "menu_common.h"
#include "mode_sleep.h"
#include "mode_on.h"
#include "mode_edit.h"

MenuSleep menu_sleep;
MenuOn menu_on;
MenuEdit menu_edit;

void init_menus() {
    menu_sleep.setup();
    menu_on.setup();
    menu_edit.setup();

    switch_menu(MENU_MODE_SLEEP);
}

void menu_run() {
  if(menu_enter) {
      switch(menu_mode) {
        case MENU_MODE_SLEEP:
          menu_sleep.enter();
          break;
        case MENU_MODE_ON:
          menu_on.enter();
          break;
        case MENU_MODE_EDIT_1:
          menu_edit.enter();
          break;
        case MENU_MODE_EDIT_2:
          menu_edit.enter();
          break;
      }
    menu_enter = false;
  }

  switch(menu_mode) {
    case MENU_MODE_SLEEP:
      menu_sleep.loop();
      break;
    case MENU_MODE_ON:
      menu_on.loop();
      break;
    case MENU_MODE_EDIT_1:
      menu_edit.loop();
      break;
    case MENU_MODE_EDIT_2:
      menu_edit.loop();
      break;
  }
}
