#include "map.hpp"

// Constructor to initialize the locations and indicators
Map::Map() {
    // Initialize the grid with empty spaces
    grid.resize(height, vector<char>(width, '.'));

    // Add locations and corresponding indicators
    addLocation("Shao's Market", "[M]");
    addLocation("Abandoned Subway Station", "[A]");
    addLocation("Neon Nexus", "[N]");
    addLocation("Pines Citadel", "[C]");

    // Mark the locations on the grid
    markLocationsOnGrid();
}

// Function to display the map as a grid
void Map::displayMap() const {
    cout << SALMON;
    cout << "Map:" << endl;
    for (const auto& row : grid) {
        for (char tile : row) {
            cout << tile << ' '; // Print each tile followed by a space
        }
        cout << endl; // New line after each row
    }
    cout << "\nWhere would you like to go?\n";
    for (size_t i = 0; i < locations.size(); ++i) {
        cout << indicators[i] << " - " << locations[i] << endl; // Display indicator and location
    }
    cout << RESET;
}

// Function to add a location and its indicator
void Map::addLocation(const string& location, const string& indicator) {
    locations.push_back(location);
    indicators.push_back(indicator);
}

// Function to mark locations on the grid
void Map::markLocationsOnGrid() {
    // For simplicity, we can place locations at predetermined positions
    grid[1][1] = 'M'; // Shao's Market
    grid[2][3] = 'A'; // Abandoned Subway Station
    grid[0][5] = 'N'; // Neon Nexus
    grid[4][7] = 'C'; // Pines Citadel
}

// Function to prompt the player for a location
string Map::promptLocation() const {
    string choice;
    cout << "Enter location: ";
    getline(cin, choice); // Get the player's input
    return choice; // Return the input for further processing
}

void shaosMarket() {
    cout << BOLDCYAN;
    cout << "=============================\n";
    cout << "You are now at Shao's Market.\n";
    cout << "=============================\n\n";
    cout << RESET;

    vector<pair<string, int>> shopItems = {
       {"Slightly Contaminated Water", 10},
       {"Loose Rat Tails", 15},
       {"Fried Scalp", 50}
    };
    Shopkeeper shao("Shao", shopItems);
    shao.interact();
}
void abandonedSubway() {
    string choice;
    cout << BOLDCYAN;
    cout << "============================================\n";
    cout << "You are now at the Abandoned Subway Station.\n";
    cout << "============================================\n\n";
    cout << RESET;

    QuestGiver laneera("Laneera");
    laneera.interact();
    cout << "Will you accept?\n";
    cout << "Pick Action [Y] | [N]: ";
    cin >> choice;
    if (choice == "y" || choice == "Y") {
        cout << endl;
        cin.ignore();
        beginnerQuest();
    }
    else {
        cout << "Fair enough.\n\n";
    }

}
void neonNexus() {
    cout << BOLDCYAN;
    cout << "==============================\n";
    cout << "You are now at the Neon Nexus.\n";
    cout << "==============================\n\n";
    cout << RESET;
    vector<pair<string, int>> strangerItems = {
    {"Used Needle", 13},
    {"Shiv", 57},
    {"Cat Jerky", 45}
    };
    Stranger junkie("Unknown", strangerItems);
    junkie.interact();
    
}
void pinesCitadel() {
    cout << BOLDCYAN;
    cout << "=============================\n";
    cout << "You are now at Pines Citadel.\n";
    cout << "=============================\n\n";
    cout << RESET;

    Villager Eleanor("Eleanor");
    Eleanor.interact();
}