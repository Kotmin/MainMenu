#ifndef MENU_H
#define MENU_H

#include <avr/pgmspace.h>

typedef void (*menuitemfuncptr)(void);

typedef struct _menuitem {
    const char *text;
    menuitemfuncptr menuitemfunc;
    const struct _menuitem *parent;
    const struct _menuitem *submenu;
    const struct _menuitem *next;
} MenuItem;

void menu_init2(const MenuItem *startMenu);
void menu_next();
void menu_prev();
void menu_select();
void menu_back();
void display_menu();

#endif // MENU_H
