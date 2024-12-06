//Cristian Labastida Project 1
//City-04 Original Code
//Edited by Oswaldo 
#include <iostream>
#include <string>

#include "character.hpp"
#include "inventory.hpp"
#include "map.hpp"
#include "menuSystem.hpp"
#include "formatting.hpp"
#include "items.hpp"
#include "npc.hpp"
#include "quest.hpp"
#include "combatSystem.hpp"

using namespace std;

string playerName, playerType, action;
Player player("", "");

int main() {

	intro();
	setPlayerType();
	player = Player(playerName, playerType);
	welcomePlayer();

	while (true) {	//Keeps looping through so you can choose various actions
		actionMenu();

		if (action == "E" || action == "e") {	//Equip
			string item, weapon, armor;

			equipArmorWeapon();
			cin.ignore();
			getline(cin, item);
			cout << endl;

			if (item == "A" || item == "a") {
				int choice;
				pickArmor();
				cin >> choice;
				cout << endl;

				if (cin.fail() || choice < 1 || choice > 4) {	//Prevents strings from being entered
					invalidChoice4();
				}
				else {
					switch (choice) {	//Inventory[2] is for a chestpiece, Inventory[3] is for boots

					case 1:
						playerInventory.addArmor(1, "Worn Chestplate");
						break;
					case 2:
						playerInventory.addArmor(3, "Worn Boots");
						break;
					case 3:
						playerInventory.addArmor(1, "Aegis' Cloak");
						break;
					case 4:
						playerInventory.addArmor(3, "Aegis' Boots");
						break;
					}
				}
			}
			else if (item == "W" || item == "w") {
				int choice;
				pickWeapon();
				cin >> choice;

				if (cin.fail() || choice < 1 || choice > 5) {	//Makes sure no string is accepted
					invalidChoice5();
				}
				else {
					switch (choice) {	//Primary weapon (Inventory[0]), A secondary weapon can be added later (Inventory[1])
					case 1:
						playerInventory.addWeapon(0, "Stun Baton");
						break;
					case 2:
						playerInventory.addWeapon(0, "Sword of Ducane");
						break;
					case 3:
						playerInventory.addWeapon(0, "Shield");
						break;
					case 4:
						playerInventory.addWeapon(0, "Simple Crossbow");
						break;
					case 5:
						playerInventory.addWeapon(0, "Vortex Blades");
						break;
					}
				}
			}
		}
		else if (action == "I" || action == "i") {	//Displays the Inventory
			playerInventory.showInventory();	//Calls void showInventory
		}
		else if (action == "F" || action == "f") {	//Shows the player's stats
			showStats(player);	//Calls void showStats
		}
		else if (action == "P" || action == "p") {	//Enter the city (gameplay)
			break;
		}
		else if (action == "X" || action == "x") {	//Exit the game
			exitGame();
			return 0;
		}
		else {
			invalidAction();
		}
	}
	//Gameplay - City
	welcomeToTheCity();
	streetEncounter(player);
	while (true) {
		mainMenu();
		if (action == "M" || action == "m") {
			cin.ignore();
			Map gameMap; // Create the map

			gameMap.displayMap(); // Display the map locations

			string playerChoice = gameMap.promptLocation(); // Ask for the player's choice
			cout << endl;
			// Here you can use if statements to check the player's choice
			// For example:
			if (playerChoice == "M" || playerChoice == "m") {
				shaosMarket();
			}
			else if (playerChoice == "A" || playerChoice == "a") {
				abandonedSubway();
			}
			else if (playerChoice == "N" || playerChoice == "n") {
				neonNexus();
			}
			else if (playerChoice == "C" || playerChoice == "c") {
				pinesCitadel();
			}
			else {
				cout << "Location not recognized. Please try again." << endl;
			}

		}
		else if (action == "I" || action == "i") {	//Displays the Inventory
			playerInventory.showInventory();	//Calls void showInventory
		}
		else if (action == "F" || action == "f") {	//Shows the player's stats
			showStats(player);	//Calls void showStats
		}
		else if (action == "u" || action == "U") {	// Use Item
		
		}
		else if (action == "X" || action == "x") {	// Exit the game
			exitGame();
		}
	}
	return 0;
}