#ifndef MENU_H_
#define MENU_H_

#include "lcd_lib.h"
#include <stdint.h>

#define MAX_MENU_ITEMS 10
#define MAX_MENU_LENGTH 16
#define MAX_MENUS 5 // Maximum number of different menus

typedef struct MenuStruct Menu;


typedef struct {
    char text[MAX_MENU_LENGTH + 1];
    void (*action)(Menu *);
} MenuItem;

struct MenuStruct {
    uint8_t id; 
    MenuItem items[MAX_MENU_ITEMS];
    uint8_t itemCount;
    uint8_t current;
    LCD *lcd;
    Menu *parentMenu;
};


void menu_init(Menu *menu, uint8_t id, LCD *lcd, Menu *parentMenu);
void menu_addItem(Menu *menu, const char *text, void (*action)(Menu *));
void menu_display(Menu *menu);
void menu_nextItem(Menu *menu);
void menu_prevItem(Menu *menu);
void menu_selectItem(Menu *menu);
void menu_goto(Menu *currentMenu, uint8_t targetMenuId);

#endif /* MENU_H_ */
