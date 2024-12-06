#ifndef character_hpp
#define character_hpp
#include <iostream>
#include <string>
#include "formatting.hpp"
#include "menuSystem.hpp"

using namespace std;

class Player {			//Makes the class player
public:
	string name, type;
	int power, health, magic, shielding;

	/*
	~~Max Stats for a player, not counting item buffs~~
	health = 200
	power = 100 ~ Damage 1x
	magic = 60 ~ Damage 2x
	shielding = 40 ~ Damage 0.5x
	*/

	Player(string playerName, string playerType): name(playerName), type(playerType) {

		if (type == "Traveler" || type == "traveler") {		// Types of characters and their attributes
			health = 90;
			power = 5;
			magic = 25;
			shielding = 0;
		}
		else if (type == "Time Eater" || type == "time eater") {
			health = 130;
			power = 50;
			magic = 0;
			shielding = 0;
		}
		else if (type == "Caster" || type == "caster") {
			health = 90;
			power = 40;
			magic = 0;
			shielding = 20;
		}
		else if (type == "Sentinel" || type == "sentinel") {
			health = 110;
			power = 60;
			magic = 0;
			shielding = 10;
		}
		else {
			type = "Explorer";
			health = 100;
			power = 50;
			magic = 0;
			shielding = 0;
		}
	}
};

extern Player player;
extern string playerName, playerType, action;

void setPlayerType();
void showStats(const Player player);

class Enemy {
public:
    string type;
    int power, health, magic, shielding;

    // Constructor for the base class
    Enemy(string type) : type(type), power(0), health(0), magic(0), shielding(0) {}

    // Destructor
    virtual ~Enemy() {
        if (health <= 0) {
            cout << type << " has been killed!\n" << endl;
        }
    }

    // Method to display enemy details
    void display() const {
        cout << BOLDWHITE;
        cout << "============================================================\n";
        cout << "[" << type << "]: Health: " << health << " | Power: " << power
            << " | Magic: " << magic << " | Shielding: " << shielding << endl;
        cout << "============================================================\n\n";
        cout << RESET;
    }
};

// Subclass for Boss enemies
class Boss : public Enemy {
public:
    Boss(string bossType) : Enemy(bossType) {
        if (bossType == "Khovnovik") {
            health = 240;
            power = 120;
            magic = 0;
            shielding = 50;
        }
        else if (bossType == "Demon Queen") {
            health = 300;
            power = 80;
            magic = 30;
            shielding = 20;
        }
    }
};

// Subclass for Lead enemies
class Lead : public Enemy {
public:
    Lead(string leadType) : Enemy(leadType) {
        if (leadType == "Pyromancer") {
            health = 120;
            power = 30;
            magic = 5;
            shielding = 10;
        }
        else if (leadType == "Necromancer") {
            health = 100;
            power = 17;
            magic = 17;
            shielding = 5;
        }
    }
};

// Subclass for Minion enemies
class Minion : public Enemy {
public:
    Minion(string enemyType) : Enemy(enemyType) {
        if (enemyType == "Arsonist") {
            health = 60;
            power = 12;
            magic = 0;
            shielding = 0;
        }
        else if (enemyType == "Tweaker") {
            health = 50;
            power = 10;
            magic = 0;
            shielding = 0;
        }
        else if (enemyType == "Scammer") {
            health = 50;
            power = 10;
            magic = 0;
            shielding = 5;
        }
    }
};


#endif // !character_hpp
