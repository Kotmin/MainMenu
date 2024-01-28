#include "menu3.h"
#include "lcd_lib.h" // Include your LCD library here
#include <avr/io.h>

static const MenuItem *currentMenu;

extern LCD lcd1;

void menu_init2(const MenuItem *startMenu) {
    currentMenu = startMenu;
    display_menu();
}

void display_menu() {
    // Implement LCD display logic here
    LCD_clear(&lcd1);
    LCD_writeText(&lcd1, currentMenu->text);
    // ... additional code to display submenu items or parent menu
}

void menu_next() {
    if (currentMenu->next) {
        currentMenu = currentMenu->next;
        display_menu();
    }
}

void menu_prev() {
    // Implement previous menu logic
}

void menu_select() {
    if (currentMenu->menuitemfunc) {
        currentMenu->menuitemfunc();
    } else if (currentMenu->submenu) {
        currentMenu = currentMenu->submenu;
        display_menu();
    }
}

void menu_back() {
    if (currentMenu->parent) {
        currentMenu = currentMenu->parent;
        display_menu();
    }
}


