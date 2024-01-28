
#include <avr/io.h>
#include <stdio.h>


#include "lcd_lib.h"
#include "my_keyboard_lib.h"
#include "menu.h"


LCD lcd1;


void option1_action(void);
void option2_action(void);

void goToMenu1(Menu **currentMenuPtr);
void goToMenu2(Menu **currentMenuPtr);
void goToMenu3(Menu **currentMenuPtr);
void goToMenu4(Menu **currentMenuPtr);
void goToMainMenu(Menu **currentMenuPtr);


volatile Menu *currentMenu;

Menu mainMenu, menu1, menu2, menu3, menu4;

void setupMenus() {

    // Initialize menus
    menu_init(&mainMenu, 0, &lcd1, NULL);
    menu_init(&menu1, 1, &lcd1, &mainMenu);
    menu_init(&menu2, 2, &lcd1, &mainMenu);
    menu_init(&menu3, 3, &lcd1, &mainMenu);
	menu_init(&menu4, 4, &lcd1, &menu3);

    // Add items to mainMenu
    menu_addItem(&mainMenu, "Menu 1", goToMenu1);
    menu_addItem(&mainMenu, "Menu 2", goToMenu2);
    menu_addItem(&mainMenu, "Menu 3", goToMenu3);


    menu_addItem(&menu1, "Option 1", option1_action);
    menu_addItem(&menu1, "Option 2", option2_action);

	menu_addItem(&menu2, "Option 1", option1_action);
    menu_addItem(&menu2, "Option 2", option2_action);

	menu_addItem(&menu3, "Option 1", option1_action);
    menu_addItem(&menu3, "Return", goToMenu4);

	menu_addItem(&menu4, "Main Menu", goToMainMenu);
    menu_addItem(&menu4, "Menu 1", goToMenu1);

	currentMenu = &mainMenu;

    // Display the main menu
    menu_display(&mainMenu);
}






int main(void)
{
	// Set kbd port
	set_DDR('A');
	//Led bar
	DDRD =0xFF;
	PORTD =0xFF;


    LCD_init(&lcd1, 'B'); // LCD on PORTB


    menu_init(&mainMenu, 0, &lcd1, NULL);

    menu_addItem(&mainMenu, "Menu 1", option1_action);
    menu_addItem(&mainMenu, "Menu 2", goToMenu2);
    menu_addItem(&mainMenu, "Menu 3", goToMenu3);

	menu_init(&menu1, 1, &lcd1, &mainMenu);
	menu_addItem(&menu1, "Sm1", option1_action);
    menu_addItem(&menu1, "Sm2", option2_action);


    menu_display(&mainMenu);

	currentMenu = &mainMenu;


    while (1) 
    {
		PORTD = get_key('d', 'A');
		
			

			 switch (get_key('d', 'A')) {
            case 4: // Up
                menu_prevItem(currentMenu);

                break;
            case 8: // Down
                menu_nextItem(currentMenu);

                break;
            case 12: // Enter

                menu_selectItem(&currentMenu); 
				option1_action();

                break;
            case 16: // Return
                if (currentMenu->parentMenu != NULL) {
                    currentMenu = currentMenu->parentMenu;
                    menu_display(currentMenu);
					}
                break;
        }
		    }

			
	
}


void goToMenu1(Menu **currentMenuPtr) {
    *currentMenuPtr = &menu1;
    menu_display(*currentMenuPtr);
}

void goToMenu2(Menu **currentMenuPtr) {
    *currentMenuPtr = &menu2;
    menu_display(*currentMenuPtr);
}

void goToMenu3(Menu **currentMenuPtr) {
    *currentMenuPtr = &menu3;
    menu_display(*currentMenuPtr);
}

void goToMenu4(Menu **currentMenuPtr) {
    *currentMenuPtr = &menu4;
    menu_display(*currentMenuPtr);
}

void goToMainMenu(Menu **currentMenuPtr) {
    *currentMenuPtr = &mainMenu;
    menu_display(*currentMenuPtr);
}



void option1_action(void) {
    // Action for option 1
	menu_goto(currentMenu,1);
	
	return;
		}

void option2_action(void) {
    // Action for option 2
		return;
}

