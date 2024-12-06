#ifndef npc_hpp
#define npc_hpp
#include <iostream>
#include <vector>
#include "character.hpp"
#include "menuSystem.hpp"
#include "inventory.hpp"

using namespace std;

class NPC {
public:
    string npcName;

    NPC(string npcName) : npcName(npcName) {}

    virtual ~NPC() {}
    virtual void interact() {
        cout << npcName<<": Hey there.\n";
    }

    // Method to display npcName
    void display() const {
        cout << "NPC Name: " << npcName << endl;
    }
};

class Shopkeeper : public NPC {
private:
    vector<pair<string, int>> npcItems;

public:
    Shopkeeper(string npcName, vector<pair<string, int>> shopItems)
        : NPC(npcName), npcItems(shopItems) {}

    void interact() override {
        cout << npcName << ": Welcome, what're you looking for?:\n";
        for (const auto& npcItem : npcItems) {
            cout << "- " << npcItem.first <<" :  "<< npcItem.second<<" Nexus Credits\n";
        }
        cout << endl;
    }

    void removeItem(const string& itemName) {
        npcItems.erase(remove_if(npcItems.begin(), npcItems.end(),
            [&](const pair<string, double>& npcItem) { return npcItem.first == itemName; }), npcItems.end());
    }

};

class QuestGiver : public NPC {
public:
    QuestGiver(string npcName) : NPC(npcName) {}

    void interact() override {
        cout << npcName << ": I have a task for you, if you're brave enough.\n\n";
    }
};

class Villager : public NPC {
public:
    Villager(string npcName) : NPC(npcName) {}

    void interact() override {
        cout << npcName << ": Hello there! Nice weather we're having.\n";
    }
};

class Stranger : public NPC {
private:
    vector<pair<string, int>> npcItems;

public:
    Stranger(string npcName, vector<pair<string, int>> strangerItems)
        : NPC(npcName), npcItems(strangerItems) {}

    void interact() override {
        cout << npcName << ": ...What're you doing here? Lookin to buy something? Here's what I got:\n";
        for (const auto& npcItem : npcItems) {
            cout << "- " << npcItem.first<<" :  "<<npcItem.second<<" Nexus Credits\n";
        }
        cout << endl;
    }
    void removeItem(const string& itemName) {
        npcItems.erase(remove_if(npcItems.begin(), npcItems.end(),
            [&](const pair<string, double>& npcItem) { return npcItem.first == itemName; }), npcItems.end());
    }
};

class Doctor : public NPC {
private:
    vector<pair<string, int>> npcItems;

public:
    Doctor(string npcName, vector<pair<string, int>> doctorItems)
        : NPC(npcName), npcItems(doctorItems) {}

    void interact() override {
        cout << npcName << ": Need healing supplies? These might help:\n";
        for (const auto& npcItem : npcItems) {
            cout << "- " << npcItem.first<<" :  "<<npcItem.second<<" Nexus Credits\n";
        }
        cout << endl;
    }
     void removeItem(const string& itemName) {
        npcItems.erase(remove_if(npcItems.begin(), npcItems.end(),
            [&](const pair<string, double>& npcItem) { return npcItem.first == itemName; }), npcItems.end());
    }
};

#endif // !npc
