#include "combatSystem.hpp"

void combat(Player& player, Enemy& enemy) {

    while (player.health > 0 && enemy.health > 0) {
        // Player's attack
        int playerDamage = player.power + (player.magic * 2);
        cout <<"You attack " << enemy.type << " using " << playerInventory.primaryWeapon() << "!" << endl;

        // Calculate effective damage to enemy considering its shielding
        int totalDamageToEnemy = playerDamage - enemy.shielding;
        if (totalDamageToEnemy > 0) {
            enemy.health -= totalDamageToEnemy;
            cout << enemy.type << " takes " << totalDamageToEnemy << " damage!" << endl;
        }
        else {
            cout << enemy.type << " blocked all damage!" << endl;
        }

        // Display health after player's attack
        cout << enemy.type << " Health: " << enemy.health << endl;

        // Check if enemy is defeated
        if (enemy.health <= 0) {
            break;
        }

        // Enemy's attack
        int enemyDamage = enemy.power + (enemy.magic * 2);
        cout << enemy.type << " attacks " << player.name << " for " << enemyDamage << " damage!" << endl;

        // Calculate effective damage to player considering its shielding
        int totalDamageToPlayer = enemyDamage - player.shielding;
        if (totalDamageToPlayer > 0) {
            player.health -= totalDamageToPlayer;
            cout << player.name << " takes " << totalDamageToPlayer << " damage!" << endl;
        }
        else {
            cout << player.name << " blocked all damage!" << endl;
        }

        // Display health after enemy's attack
        cout << player.name << " Health: " << player.health << endl;

        // Check if player is defeated
        if (player.health <= 0) {
            break;
        }     
    }
}

void streetEncounter(Player& player) {
    Minion clave("Tweaker");
    string answer;
    cout << "[Tweaker]: Ay, got anything on you? If so, hand it over and nobody has to get hurt.\n\n";
    cout << BOLDWHITE;
    cout << "[Y] Empty pockets | [F] Fight\n";
    cout << RESET;
    cout << "Choose an action: ";
    cin >> answer;
    if (cin.fail() || (answer != "y" && answer != "Y" && answer != "f" && answer != "F")) {
        invalidChoice();
    }
    else if (answer == "y" || answer == "Y") {
        cout << "[Tweaker]: Smart.\n";
        playerInventory.nexusCredits -= 10;
        cout << "\n*You were robbed! You lost 10 Nexus Credits*\n";
    }
    else if (answer == "f" || answer == "F") {
        cout << "\n[Tweaker]: Someone has to get hurt then.\n";
        clave.display();
        combat(player, clave);
    }
};