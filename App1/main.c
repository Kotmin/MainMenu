
#include <avr/io.h>
#include <stdio.h>


#include "lcd_lib.h"
#include "my_keyboard_lib.h"
#include "menu.h"
#include "menu2.h"

static LCD lcd1;


void option1_action(void);
void option2_action(void);

void goToMenu1(Menu **currentMenuPtr);
void goToMenu2(Menu **currentMenuPtr);
void goToMenu3(Menu **currentMenuPtr);
void goToMenu4(Menu **currentMenuPtr);
void goToMainMenu(Menu **currentMenuPtr);



Menu mainMenu, menu1, menu2, menu3, menu4;

void setupMenus() {
    LCD lcd1; // Assuming this is your LCD object
    LCD_init(&lcd1, 'B'); // Initialize LCD

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

//	LCD lcd1;
    LCD_init(&lcd1, 'B'); // Initialize LCD on PORTB
/*
    LCD_clear(&lcd1); // Clear the LCD
    LCD_writeText(&lcd1, "Techniki"); // Write text to the first line
    LCD_setCoursor(&lcd1, 0, 1); // Move cursor to the second line
    LCD_writeText(&lcd1, "Mikroprocesorowe"); // Write text to the second line

	Menu menu;
    menu_init(&menu, 0, &lcd1,NULL);
	menu_init(&menu1, 1, &lcd1, &menu);
    menu_addItem(&menu1, "Sm1", option1_action);
    menu_addItem(&menu1, "Sm2", option2_action);
    menu_addItem(&menu, "Option 1", goToMenu1); // do not work properly
    menu_addItem(&menu, "Option 2", option2_action);
	menu_addItem(&menu, "Option 3", option2_action);



	
	menu_display(&menu);
*/

//	 setupMenus();

	Menu *currentMenu = &mainMenu;
//	Menu *currentMenu = &menu;

	// menu 2 section
	MenuOption *currentOption;

    initMenu(&currentOption);

// recombine init m functions
    LCD lcd1; // Assuming this is your LCD object
    LCD_init(&lcd1, 'B'); // Initialize LCD
	    // Initialize menus

    menu_init(&mainMenu, 0, &lcd1, NULL);

	    // Add items to mainMenu
    menu_addItem(&mainMenu, "Menu 1", goToMenu1);
    menu_addItem(&mainMenu, "Menu 2", goToMenu2);
    menu_addItem(&mainMenu, "Menu 3", goToMenu3);

	menu_init(&menu1, 1, &lcd1, &mainMenu);
	menu_addItem(&menu1, "Sm1", option1_action);
    menu_addItem(&menu1, "Sm2", option2_action);





    // Display the main menu
    menu_display(&mainMenu);

    while (1) 
    {
		PORTD = get_key('d', 'A');
		
	

		/*

		switch (get_key('d', 'A'))
		{
		case 4:
		menu_prevItem(&menu);

		break;

		case 8:
		
		menu_nextItem(&menu);

		break;

		case 12:
		LCD_clear(&lcd1);
		LCD_setCoursor(&lcd1, 0, 0);
		LCD_writeText(&lcd1, "Clear");
		break;

		case 16:
		menu_selectItem(&menu);
		break;

		default:

		continue;
		}

    	}
		
*/
		 
/*
		 switch (get_key('d', 'A')) {
            case 4: // Up
                menu_prevItem(currentMenu);
                break;
            case 8: // Down
                menu_nextItem(currentMenu);
                break;
            case 12: // Enter
                menu_selectItem(&currentMenu); // Pass the address of currentMenu
                break;
            case 16: // Return
                if (currentMenu->parentMenu != NULL) {
                    currentMenu = currentMenu->parentMenu;
                    menu_display(currentMenu);
                }
                break;
        }
		    }

			*/

			 switch (get_key('d', 'A')) {
            case 4: // Up
                menu_prevItem(currentMenu);
				moveNext(&currentOption);
                break;
            case 8: // Down
                menu_nextItem(currentMenu);
				movePrev(&currentOption);
                break;
            case 12: // Enter
                menu_selectItem(&currentMenu); // Pass the address of currentMenu

                break;
            case 16: // Return
                if (currentMenu->parentMenu != NULL) {
                    currentMenu = currentMenu->parentMenu;
                    menu_display(currentMenu);
				if (currentOption->actionBackward != NULL)
                    currentOption->actionBackward(&currentOption);
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
	return;
		}

void option2_action(void) {
    // Action for option 2
		return;
}