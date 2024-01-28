#ifndef MENU2_H_
#define MENU2_H_


#include <stdio.h>
#include <stdbool.h>

typedef struct MenuOption MenuOption;

struct MenuOption {
    char *title;
    MenuOption *prev;
    MenuOption *next;
    MenuOption *child;
    MenuOption *parent;

    bool (*actionForward)(MenuOption **); // sender of action
    bool (*actionBackward)(MenuOption **); // sender of action
};

bool moveNext(MenuOption **root);

bool movePrev(MenuOption **root);

bool moveToChild(MenuOption **root);

bool moveToParent(MenuOption **root);


#endif /* MENU2_H_ */
