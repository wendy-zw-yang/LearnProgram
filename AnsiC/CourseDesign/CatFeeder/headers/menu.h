#ifndef MENU_HEADER_FILE
#define MENU_HEADER_FILE

void displayMenu();
/**
 * displayMenu()：show the main menu
 */
void showCats(CatList *list);
/**
 * showCats(): show the cat list
 */
void dataSetting(CatList *list);
/**
 * dataSetting()：show the data setting menu, and run the functions
 */
void feederMods(CatList *list);
/**
 * feederMds()：show the menu of feeder mods, and run the functions
 */

void systemInfo(); //show the info and log
void systmeIntroduction();

#endif