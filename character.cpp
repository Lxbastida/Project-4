#include "character.hpp"

void setPlayerType() {
	while (true) {

		int choice;
		pickCharacter();
		cin >> choice;

		if (cin.fail() || choice < 1 || choice > 5) {	//If statement to prevent strings from being entered, otherwise it'll break my code lol
			invalidChoice5();
		}
		else {
			switch (choice) {	//Options for character types

			case 1:
				playerType = "Traveler";
				break;
			case 2:
				playerType = "Time Eater";
				break;
			case 3:
				playerType = "Caster";
				break;
			case 4:
				playerType = "Sentinel";
				break;
			default:
				playerType = "Explorer";
				break;
			}
			break;
		}
	}
};
void showStats(const Player player) {		//Shows the stats of your character
	cout << BOLDWHITE;
	cout << "===== Stats =====\n";
	cout << BOLDCYAN;
	cout << "~ " << player.type << " ~\n";
	cout << " Health: " << player.health << "\n Power: " << player.power
		<< "\n Magic: " << player.magic << "\n Shielding: " << player.shielding;
	cout << RESET;
	cout << BOLDWHITE;
	cout << "\n=================\n\n";
	cout << RESET;
}

