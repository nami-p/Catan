#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <functional>
#include "Tile.h"
#include "CellsHash.h"
#include <queue>

 struct Handler {
     void (*Action)(std::vector<std::string> args);
};
 struct helpcommandHandler {
     void (*Action)(std::string state , std::vector<std::vector<Coordinate*>> cells);
};

class Actions
{
public:
    
    static std::queue <Manufacture1*> waitActions;
    static Tile* selectedTile;
    static int selectedX;
    static int selectedY;
    static Coordinate lastElement;

    // Map to store action names and their corresponding functions
    static std::unordered_map<std::string, Handler> ActionsMap;
    static std::unordered_map<std::string, helpcommandHandler> HelpActionsMap;

    // Action methods
    static void Select(std::vector<std::string> args);
    //static void Asserts(std::vector<std::string> args);
    static void Resource(std::vector<std::string> args);
    static void People(std::vector<std::string> args);
    static void Work(std::vector<std::string> args);
    static void Rain(std::vector<std::string> args);
    static void Wait(std::vector<std::string> args);
    static void Build(std::vector<std::string> args);
    static void MakeEmpty(std::vector<std::string> args);
    static void Manufacture(std::vector<std::string> args);
    static void Deposit(std::vector<std::string> args);
    static void TakeResource(std::vector<std::string> args);
    static void Resources(std::vector<std::string> args);
    static void Move(std::vector<std::string> args);

    static void City(std::string state, std::vector<std::vector<Coordinate*>> cells);
    static void Village(std::string state, std::vector<std::vector<Coordinate*>> cells);
    static void Road(std::string state, std::vector<std::vector<Coordinate*>> cells);

   

    // Constructor to initialize the ActionsMap
    Actions();
private:
    //Manufacture* GetTypeObject();

};
