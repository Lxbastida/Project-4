#ifndef map_hpp
#define map_hpp

#include <iostream>
#include <vector>
#include <string>
#include "formatting.hpp"
#include "npc.hpp"
#include "quest.hpp"

using namespace std;

class Map {
private:
    const int width = 10; // Width of the map
    const int height = 5; // Height of the map
    vector<vector<char>> grid; // 2D grid representing the map
    vector<string> locations; // List of locations
    vector<string> indicators; // Indicators for locations

public:
    // Constructor
    Map();

    // Function to display the map as a grid
    void displayMap() const;

    // Function to add a location and its indicator
    void addLocation(const string& location, const string& indicator);

    // Function to prompt the player for a location
    string promptLocation() const;

    // Function to mark locations on the grid
    void markLocationsOnGrid();
};

void shaosMarket();
void abandonedSubway();
void neonNexus();
void pinesCitadel();

#endif // map_hpp