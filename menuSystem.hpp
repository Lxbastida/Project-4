#ifndef menuSystem_hpp
#define menuSystem_hpp
#include <iostream>
#include <string>
#include "character.hpp"
#include "formatting.hpp"

//Dialogue
void intro();
void welcomePlayer();
void welcomeToTheCity();

//Gameplay
void exitGame();
void lootBody();

//Choices
void pickCharacter();

//Invalid choice 
void invalidAction();
void invalidChoice();
void invalidChoice5();
void invalidChoice4();

//Menu
void actionMenu();
void mainMenu();
void equipArmorWeapon();
void pickArmor();
void pickWeapon();


#endif // !menuSystem
