#ifndef inventory_hpp
#define inventory_hpp
#include <iostream>
#include <vector>
#include "character.hpp"
#include "formatting.hpp"
#include "items.hpp"

using namespace std;

class Inventory {
private:
	const int maxItems = 10;
	vector<string>itemInventory;

	string armorInventory[4];	//Allows or helmet, chestpiece, pants, and boots
	const int maxArmor = 4;

	string weaponInventory[2];	//Allows for a primary and secondary weapon
	const int maxWeapon = 2;

public:
	int nexusCredits;
	string currentHelmet, currentChestpiece, currentPants, currentBoots;
	string currentPrimary, currentSecondary;

	Inventory() : nexusCredits(10), itemInventory(maxItems) {
		for (int i = 0; i < maxArmor; i++) {
			armorInventory[i] = "";
		}
		weaponInventory[0] = "Fists";  // Primary weapon
		weaponInventory[1] = "";       // Secondary weapon is empty

	}

	void showInventory();
	void showArmorInventory();
	void showWeaponInventory();
	string primaryWeapon();

	void addItem(const string& item);
	void addArmor(int slot, const string& armor);
	void addWeapon(int slot, const string& weapon);

	void removeArmorBuffs(int slot);
	void removeWeaponBuffs(int slot);

};

extern Inventory playerInventory;

#endif // !inventory
