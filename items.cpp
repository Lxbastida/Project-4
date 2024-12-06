#include "items.hpp"

string currentWeapon;
string currentArmor;
/*
"+ Shielding"
"+ Magic"
"+ Power"
"+ Healing"
*/


/*  Armor  */

//Helmet

//Chestpiece
void wornChestplate() {
	playerInventory.currentChestpiece = "Worn Chestplate";
	player.shielding += 7;	//Adds shielding to the current stats
	cout << "+7 Shielding\n";
}
void aegisCloak() {
	playerInventory.currentChestpiece = "Aegis' Cloak";
	player.shielding += 5;
	player.magic += 1;
	cout << "+5 Shielding, +1 Magic\n";
}

//Pants

//Boots
void wornBoots() {
	playerInventory.currentBoots = "Worn Boots";
	player.shielding += 5;
	cout << "+ 5 Shielding\n";
}
void aegisBoots() {
	playerInventory.currentBoots= "Aegis' Boots";
	player.shielding += 3;
	player.magic += 1;
	cout << "+3 Shielding, +1 Magic\n";
}

/*  Weapons  */

//Primary
void stunBaton(){
	playerInventory.currentPrimary = "Stun Baton";
	player.power += 25;
	cout << "+25 Power\n";
}
void swordOfDucane(){
	playerInventory.currentPrimary = "Sword of Ducane";
	player.power += 17;
	player.health += 15;
	cout << "+17 Power, +15 Health\n";
}
void shield(){
	playerInventory.currentPrimary = "Shield";
	player.power += 15;
	player.shielding += 10;
	cout << "+15 Power, +10 Shielding\n";

}
void simpleCrossbow(){
	playerInventory.currentPrimary = "Simple Crossbow";
	player.power += 25;
	cout << "+25 Power\n";
}
void vortexBlades(){
	playerInventory.currentPrimary = "Vortex Blades";
	player.power += 15;
	player.magic += 3;
	cout << "+15 Power, +3 Magic\n";
}

//Secondary
