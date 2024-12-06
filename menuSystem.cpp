#include "menuSystem.hpp"

using namespace std;

//Dialogue
void intro() {
	cout << BOLDCYAN;
	cout << "=================================================================================\n";
	cout << "City-04, in a place shaped by the wounds of war, a story unfolds.\n"
		<< "The Sentinels keep a watchful eye over the metropolis, a result of the\n"
		<< "troubled past that led to cities being numbered instead of named.\n\n"
		<< "Travelers, skilled at manipulating time, navigate the complex weave of reality.\n"
		<< "Their talents honed with technology, developed in the midst of conflict.\n"
		<< "Alongside them, the mysterious Casters harness ancient magics that grant them \n"
		<< "formidable shielding, allowing them to navigate the city with a sense of protection.\n\n"
		<< "Meanwhile, the ordinary Explorers move through the broken streets, seeking \n"
		<< "refuge amidst the remnants of past battles.\n"
		<< "Yet, amid this delicate balance, the ominous Time Eaters lurk in the shadows, a \n"
		"somber reminder of the perils hidden in the dim corners of City-04.\n";
	cout << "=================================================================================\n";
	cout << RESET;
	cout << "Enter name: ";
	getline(cin, playerName);
	cout << endl;
};
void welcomePlayer() {
	cout << BOLDCYAN;
	cout << "=================================================================================\n";
	cout << "Welcome, " << player.name << " the " << player.type << ". You have arrived at the outskirts of City-04.\n"
		<< "The city can be dangerous, so make sure you are well-equipped for your journey.\n"
		<< "Equip some armor and a weapon before venturing out into the city streets.\n";
	cout << "=================================================================================\n\n";
	cout << RESET;
};
void welcomeToTheCity() {
	cout << BOLDCYAN;
	cout << "==================================\n";
	cout << "You have entered the city streets.\n";
	cout << "==================================\n\n";
	cout << RESET;
}

//Gameplay
void exitGame() {
	cout << "\n===============================================";
	cout << "\n You Have Left ";
	cout << BOLDRED;
	cout << "City - 04";
	cout << RESET;
	cout << ". Proceed With caution.\n";
	cout << "===============================================\n";
};
void lootBody() {

}

//Choices
void pickCharacter() {
	cout << SALMON;
	cout << "    Pick Character Type (1-5):    \n";
	cout << RESET;
	cout << BOLDWHITE;
	cout << "===================================\n";
	cout << SALMON;
	cout << " [1] Traveler     |  [4] Sentinel  \n";
	cout << " [2] Time Eater   |  [5] Explorer   \n";
	cout << " [3] Caster       |      \n";
	cout << RESET;
	cout << BOLDWHITE;
	cout << "===================================\n";
	cout << RESET;
};

//Invalid Choice
void invalidAction() {
	cout << BOLDRED;
	cout << "===============\n";
	cout << "Invalid Action!\n";
	cout << "===============\n\n";
	cout << RESET;
};
void invalidChoice() {
	cout << BOLDRED;
	cout << "===============\n";
	cout << "Invalid Choice!\n";
	cout << "===============\n\n";
	cout << RESET;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void invalidChoice5() {
	cout << BOLDRED;
	cout << "==========================================\n";
	cout << "Invalid Choice! Pick A Number Between 1-5.\n";
	cout << "==========================================\n\n";
	cout << RESET;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');	//Telling the program to ignore string inputs until there is a new line
}
void invalidChoice4() {
	cout << BOLDRED;
	cout << "==========================================\n";
	cout << "Invalid Choice! Pick A Number Between 1-4.\n";
	cout << "==========================================\n\n";
	cout << RESET;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
};

//Menu
void actionMenu() {
	cout << BOLDWHITE;
	cout << "[E] Equip  |  [I] Inventory  |  [F] Stats  |  [P] Enter City  |  [X] Exit Game\n";
	cout << RESET;
	cout << "Choose An Action:";
	cin >> action;
	cout << endl;
};
void mainMenu() {
	cout << BOLDWHITE;
	cout << "[M] Open Map  |  [I] Inventory  |  [F] Stats  |  [U] Use Item |  [X] Exit Game\n";
	cout << RESET;
	cout << "Choose An Action:";
	cin >> action;
	cout << endl;
}
void equipArmorWeapon() {
	cout << BOLDWHITE;
	cout << "[A] Equip Armor  |  [W] Equip Weapon\n";
	cout << RESET;
	cout << "Choose An Action: ";
};
void pickArmor() {
	cout << BOLDWHITE;
	cout << "==== Pick Your Armor (1-4) ===========================================================================\n";
	cout << LPURPLE;
	cout << " [1] Worn Chestplate    :Offers decent protection.\n"
		<< " [2] Worn Boots         :Provides steady footing.\n"
		<< " [3] Aegis' Cloak       :Believed to contain magical abilities.\n"
		<< " [4] Aegis' Boots       :Infused with magic.\n";
	cout << RESET;
	cout << BOLDWHITE;
	cout << "======================================================================================================\n";
	cout << RESET;
};
void pickWeapon() {
	cout << RESET;
	cout << BOLDWHITE;
	cout << "==== Pick a Weapon (1-5) =============================================================================\n";
	cout << LPURPLE;
	cout << " [1] Stun Baton         : A weapon that delivers a powerful electric shock.\n"
		<< " [2] Sword of Ducane    : The long lost sword of the healers.\n"
		<< " [3] Shield             : A sturdy protector against incoming attacks.\n"
		<< " [4] Simple Crossbow    : A basic ranged weapon for accurate shooting.\n"
		<< " [5] Vortex Blades      : Three blades that create swirling energy with each strike.\n";
	cout << BOLDWHITE;
	cout << "======================================================================================================\n";
	cout << RESET;
};