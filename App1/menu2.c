#include "menu2.h"
#include <stdio.h>
#include <stdbool.h>

bool moveNext(MenuOption **root) {
    if (root == NULL || (*root)->next == NULL)
        return false;
    *root = (*root)->next;
    return true;
}

bool movePrev(MenuOption **root) {
    if (root == NULL || (*root)->prev == NULL)
        return false;
    *root = (*root)->prev;
    return true;
}

bool moveToChild(MenuOption **root) {
    if (root == NULL || (*root)->child == NULL)
        return false;
    *root = (*root)->child;
    return true;
}

bool moveToParent(MenuOption **root) {
    if (root == NULL || (*root)->parent == NULL)
        return false;
    *root = (*root)->parent;
    return true;
}

void initMenu(MenuOption **root) {
    static MenuOption option1, option2, option3;
    static MenuOption option1_1, option1_2;
    static MenuOption option2_1, option2_2;

    // ================== option 1 ==================
    option1.title = "Menu 1";
    option1.next = &option2;
    option1.prev = NULL;
    option1.child = NULL;
    option1.parent = NULL;
    option1.actionForward = &moveToChild;
    option1.actionBackward = &moveToParent;

    // ================== option 2 ==================
    option2.title = "Menu 2";
    option2.next = &option3;
    option2.prev = &option1;
    option2.child = NULL;
    option2.parent = NULL;
    option2.actionForward = &moveToChild;
    option2.actionBackward = &moveToParent;

    // ================== option 3 ==================
    option3.title = "Menu 3";
    option3.next = NULL;
    option3.prev = &option2;
    option3.child = NULL;
    option3.parent = NULL;
    option3.actionForward = &moveToChild;
    option3.actionBackward = &moveToParent;

    // ================== option 1_1 ==================
    option1_1.title = "Menu 1_1";
    option1_1.next = &option1_2;
    option1_1.prev = NULL;
    option1_1.child = NULL;
    option1_1.parent = &option1;
    option1.child = &option1_1; // link parent
    option1_1.actionForward = NULL;
    option1_1.actionBackward = &moveToParent;

    // ================== option 1_2 ==================
    option1_2.title = "Menu 1_2";
    option1_2.next = NULL;
    option1_2.prev = &option1_1;
    option1_2.child = NULL;
    option1_2.parent = &option1;
    option1_2.actionForward = NULL;
    option1_2.actionBackward = &moveToParent;

    // ================== option 2_1 ==================
    option2_1.title = "Menu 2_1";
    option2_1.next = &option2_2;
    option2_1.prev = NULL;
    option2_1.child = NULL;
    option2_1.parent = &option2;
    option2.child = &option2_1; // link parent
    option2_1.actionForward = NULL;
    option2_1.actionBackward = &moveToParent;

    // ================== option 1_2 ==================
    option2_2.title = "Menu 2_2";
    option2_2.next = NULL;
    option2_2.prev = &option2_1;
    option2_2.child = &option1;
    option2_2.parent = &option2;
    option2_2.actionForward = &moveToChild;
    option2_2.actionBackward = &moveToParent;

    // ============= return initial value =============
    *root = &option1;
}
