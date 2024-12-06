#include "quest.hpp"

void beginnerQuest() {
    // Start the quest dialogue
    cout << BOLDCYAN;
    cout << "[Laneera]: A few weeks ago, I got scammed at the Neon Nexus. Some piece of shit by the name of Pierce.\n";
    cout << "Now, I'd go myself, but I'm injured. Twisted my ankle trying to get away from him.\n";
    cout << "Could you do me a favor and confront him? I need my Nexus Credits back!\n";
    cout << RESET;

    // Ask the player if they accept the quest
    string response;
    cout << "Will you help me? [Y] | [N]: ";
    getline(cin, response);

    if (response == "y" || response == "Y") {
        cout << BOLDCYAN;
        cout << "\n[Laneera]: Thank you! Head to the Neon Nexus. Pierce usually hangs around the market area.\n";
        cout << "Be careful; he might try to scam you too!\n\n";
        cout << RESET;

        // Quest objective
        cout << BOLDWHITE;
        cout << "Objective: Confront Pierce at the Neon Nexus and retrieve the stolen credits.\n\n";
        cout << RESET;

        // Simulating the player going to the Neon Nexus
        cout << BOLDCYAN;
        cout << "==============================\n";
        cout << "You are now at the Neon Nexus.\n";
        cout << "==============================\n\n";
       
        cout << "You spot Pierce lounging near the market stalls, looking smug.\n";
        cout << RESET;
        // Confrontation dialogue
        cout << "What will you do? [C] Confront | [I] Ignore): ";
        getline(cin, response);

        if (response == "c" || response == "C") {
            cout << BOLDCYAN;
            cout << "\nYou approach Pierce and accuse him of scamming your friend.\n";
            cout << "Pierce smirks and says, 'What are you gonna do about it?'\n";
            cout << "You can either fight him or try to persuade him to return the credits.\n";
            cout << RESET;

            cout << "Choose your action: [F] Fight | [P] persuade): ";
            getline(cin, response);

            if (response == "f" || response == "F") {
                cout << BOLDCYAN;
                cout << "\nYou engage in a fight with Pierce!\n";
                // Fighting logic goes here (not implemented in this example)
                cout << "After a tough battle, you manage to defeat him!\n";
                cout << "You retrieve the stolen Nexus Credits!\n\n";
                cout << RESET;
            }
            else if (response == "p" || response == "P") {
                cout << BOLDCYAN;
                cout << "\nYou try to reason with Pierce and persuade him to return the credits.\n";
                cout << "Pierce, realizing you mean business, reluctantly hands over the credits.\n\n";
                cout << RESET;
            }
            else {
                cout << "That option isn't valid. You hesitate, and Pierce gets suspicious.\n";
            }
            cout << BOLDWHITE;
            cout << "Quest Complete! You return to the injured NPC with the credits.\n\n";
            cout << RESET;
        }
        else {
            cout << "\nYou decide to ignore Pierce and head back. The quest remains incomplete.\n\n";
        }
    }
    else {
        cout << "No worries! If you change your mind, come back to me.\n";
    }
}