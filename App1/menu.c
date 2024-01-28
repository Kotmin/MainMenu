#include "menu.h"
#include "lcd_lib.h"
#include <string.h>


Menu menus[MAX_MENUS];

void menu_init(Menu *menu, uint8_t id, LCD *lcd, Menu *parentMenu) {
    menu->id = id;
    menu->itemCount = 0;
    menu->current = 0;
    menu->lcd = lcd;
	menu->parentMenu = parentMenu;
    menus[id] = *menu; // Store the menu in the global array
}


void menu_addItem(Menu *menu, const char *text, void (*action)(Menu *)) {
    if (menu->itemCount < MAX_MENU_ITEMS) {
        strncpy(menu->items[menu->itemCount].text, text, MAX_MENU_LENGTH);
        menu->items[menu->itemCount].action = action;
        menu->itemCount++;
    }
}


void menu_display(Menu *menu) {
    LCD_clear(menu->lcd);
    uint8_t start = menu->current;
    uint8_t end = start + 1 < menu->itemCount ? start + 1 : start;

    for (uint8_t i = start; i <= end; i++) {
        LCD_setCoursor(menu->lcd, 0, i - start);
        if (i == menu->current) {
            LCD_writeCharacter(menu->lcd, '>');
        }
        LCD_writeText(menu->lcd, menu->items[i].text);
    }
}

void menu_nextItem(Menu *menu) {
    if (menu->current < menu->itemCount - 1) {
        menu->current++;
        menu_display(menu);
    }
}

void menu_prevItem(Menu *menu) {
    if (menu->current > 0) {
        menu->current--;
        menu_display(menu);
    }
}



void menu_selectItem(Menu *menu) {
    if (menu->items[menu->current].action) {
        menu->items[menu->current].action(menu);
		menu_display(menu);
    }
}





void menu_return(Menu *menu) {
    if (menu->parentMenu) {
        menu_display(menu->parentMenu);
    }
}

void menu_goto(Menu *currentMenu, uint8_t targetMenuId) {
    if (targetMenuId < MAX_MENUS && &menus[targetMenuId] != NULL) {
        menu_display(&menus[targetMenuId]);
		currentMenu = &menus[targetMenuId];
    }
}

