#include "inventory.hpp"

Inventory playerInventory;

void Inventory::showArmorInventory() {
	cout << BOLDCYAN;
	for (int i = 0; i < maxArmor; i++) {	//Loops through the Inventory
		if (!armorInventory[i].empty()) {		//If the slot has an item, it will be displayed
			cout << " - " << armorInventory[i] << endl;
		}
	}
	cout << RESET;
}
void Inventory::showWeaponInventory(){
	cout << BOLDCYAN;
	for (int i = 0; i < maxWeapon; i++) {	//Loops through the Inventory
		if (!weaponInventory[i].empty()) {		//If the slot has an item, it will be displayed
			cout << " - " << weaponInventory[i] << endl;
		}
	}
	cout << RESET;
}
string Inventory::primaryWeapon() {
	cout << BOLDCYAN;
	return weaponInventory[0];
	cout << RESET;
};
void Inventory::showInventory() {
	cout << BOLDWHITE;
	cout << "============ Inventory ============\n";
	cout << BOLDCYAN;
	cout << " - " << nexusCredits << " Nexus Credits\n";
	playerInventory.showWeaponInventory();
	playerInventory.showArmorInventory();
	for (int i = 0; i < maxItems; i++) {	//Loops through the Inventory
		if (!itemInventory[i].empty()) {		//If the slot has an item, it will be displayed
			cout << " - " << itemInventory[i] << endl;
		}
	}
	cout << RESET;
	cout << BOLDWHITE;
	cout << "===================================\n\n";
	cout << RESET;
}

//Resets armor buffs. Newly added armor pieces should be added here.
void Inventory::removeArmorBuffs(int slot) {
	if (currentChestpiece == "Worn Chestplate" && slot == 1) {
		player.shielding -= 7;
	}
	else if (currentChestpiece == "Aegis' Cloak" && slot == 1) {
		player.shielding -= 5;
		player.magic -= 1;
	}
	else if (currentBoots == "Worn Boots" && slot == 3) {
		player.shielding -= 5;
	}
	else if (currentBoots == "Aegis' Boots" && slot == 3) {
		player.shielding -= 3;
		player.magic -= 1;
	}
}

//Resets weapon buffs. Newly added weapons should be added here.
void Inventory::removeWeaponBuffs(int slot) {
	if (currentPrimary == "Stun Baton" && slot == 0) {
		player.power -= 25;
	}
	else if (currentPrimary == "Sword of Ducane" && slot == 0) {
		player.power -= 17;
		player.health -= 15;
	}
	else if (currentPrimary == "Shield" && slot == 0) {
		player.power -= 15;
		player.shielding -= 10;
	}
	else if (currentPrimary == "Simple Crossbow" && slot == 0) {
		player.power -= 25;
	}
	else if (currentPrimary == "Vortex Blades" && slot == 0) {
		player.power -= 15;
		player.magic -= 3;
	}
}

//Adds new armor piece. Newly added armor pieces should be added here.
void Inventory::addArmor(int slot, const string& armor) {
	if (armorInventory[slot] == armor){
		cout << BOLDWHITE;
		cout << "===================================\n";
		cout << BOLDRED;
		cout << armor << " already equipped!\n";
		cout << RESET;
		cout << BOLDWHITE;
		cout << "===================================\n\n";
		cout << RESET;
	}
	else {
		removeArmorBuffs(slot);
		armorInventory[slot] = armor; // Assign the new armor to the specified slot
		cout << BOLDWHITE;
		cout << "===================================\n";
		cout << MINT;
		cout << armor << " has been equipped!\n";

		if (armor == "Worn Chestplate") {
			wornChestplate();
		}
		else if (armor == "Worn Boots") {
			wornBoots();
		}
		else if (armor == "Aegis' Cloak") {
			aegisCloak();
		}
		else if (armor == "Aegis' Boots") {
			aegisBoots();
		}
		cout << RESET;
		cout << BOLDWHITE;
		cout << "===================================\n\n";
		cout << RESET;
	}
}

//Adds new weapons. Newly added weapons should be added here.
void Inventory::addWeapon(int slot, const string& weapon) {
	if (weaponInventory[slot] == weapon) {
		cout << BOLDWHITE;
		cout << "===================================\n";
		cout << BOLDRED;
		cout << weapon << " already equipped!\n";
		cout << RESET;
		cout << BOLDWHITE;
		cout << "===================================\n\n";
		cout << RESET;
	}
	else {
		removeWeaponBuffs(slot);
		weaponInventory[slot] = weapon; // Assign the new armor to the specified slot
		cout << BOLDWHITE;
		cout << "===================================\n";
		cout << MINT;
		cout << weapon << " has been equipped!\n";

		if (weapon == "Stun Baton") {
			stunBaton();
		}
		else if (weapon == "Sword of Ducane") {
			swordOfDucane();
		}
		else if (weapon == "Shield") {
			shield();
		}
		else if (weapon == "Simple Crossbow") {
			simpleCrossbow();
		}
		else if (weapon == "Vortex Blades") {
			vortexBlades();
		}
		cout << RESET;
		cout << BOLDWHITE;
		cout << "===================================\n\n";
		cout << RESET;
	}
}

void Inventory::addItem(const string& item) {
	for (int i = 0; i < maxItems;i++) {
		if (itemInventory[i].empty()) {
			itemInventory[i] = item;
			cout << "===================================\n";
			cout << BOLDBLUE;
			cout << item << " has been added!\n";
			cout << RESET;
			cout << "===================================\n";
			return;
		}
	}
	cout << "Inventory is full! Cannot add item.\n";
}