#include "Actions.h"
#include "Game.h"
#include "math.h"

std::unordered_map<std::string, helpcommandHandler> Actions::HelpActionsMap;
std::unordered_map<std::string, Handler> Actions::ActionsMap;
int Actions::selectedX = 0;
int Actions::selectedY = 0;
Coordinate Actions::lastElement = { 0,0 };
Tile* Actions::selectedTile = nullptr;
std::queue<Manufacture1*> Actions::waitActions ;

//Manufacture* GetTypeObject(Coordinate coord) {
//
//}

void Actions::Select(std::vector<std::string> args)
{
    selectedX = std::stoi(args[0])-1;
    selectedY = std::stoi(args[1])-1;
    selectedTile = Game::world->GetTile(selectedX, selectedY);
}
    
void Actions::Resource(std::vector<std::string> args)
{
    int amount = std::stoi(args[0]);
    std::string resourceName = args[1];

    Coordinate coord(std::stoi(args[2])-1, std::stoi(args[3])-1);
    Manufacture1* manufacture = Game::world->SelectedHighObject(coord);

    if (manufacture != nullptr) {
        manufacture->SetResource(amount, resourceName);

        //if ((*cell->typeIndexes)[CITY] != -1) {
        //    Settlement* city = Game::world->cellsTypesVectors->cities[(*cell->typeIndexes)[CITY]];
        //    int avaliableAmount = JsonConfig::CAPACITIES[city->TypeName()][JsonConfig::RESOURCETYPEASINDEX[resourceName]] - (*city->resources)[resourceName];
        //    amount = avaliableAmount > amount ? amount : avaliableAmount;
        //    (*city->resources)[resourceName] += amount;
        //} 
        //else if ((*cell->typeIndexes)[VILLAGE] != -1) {
        //    Settlement* village = Game::world->cellsTypesVectors->villages[(*cell->typeIndexes)[VILLAGE]];
        //    int avaliableAmount = JsonConfig::CAPACITIES[village->TypeName()][JsonConfig::RESOURCETYPEASINDEX[resourceName]] - (*village->resources)[resourceName];
        //    amount = avaliableAmount > amount ? amount : avaliableAmount;
        //    (*village->resources)[resourceName] += amount;
        //}
        //else if ((*cell->typeIndexes)[GROUNDT] != -1) {
        //    Transport* transport = Game::world->cellsTypesVectors->transports[(*cell->typeIndexes)[GROUNDT]];
        //    int avaliableAmount = JsonConfig::CAPACITIES[transport->TypeName()][JsonConfig::RESOURCETYPEASINDEX[resourceName]] - (*transport->resources)[resourceName];
        //    amount = avaliableAmount > amount ? amount : avaliableAmount;
        //    (*transport->resources)[resourceName] += amount;
        //} 
        //else if ((*cell->typeIndexes)[PEOPLE] != -1) {
        //    People1* people = Game::world->cellsTypesVectors->peoples[(*cell->typeIndexes)[PEOPLE]];
        //    //int avaliableAmount = JsonConfig::CAPACITIES[people->TypeName()][JsonConfig::RESOURCETYPEASINDEX[resourceName]] - (*people->resources)[resourceName];
        //    int avaliableAmount = 10;
        //    amount = avaliableAmount > amount ? amount : avaliableAmount;
        //    (*people->resources)[resourceName] += amount;
        //} 
  
    }
    else {
        Tile* tile = Game::world->GetTile(coord.x,coord.y);

        (*tile->resources)[resourceName] += amount;
    }
}

//void Actions::Car(std::vector<std::string> args) {
   /* args.insert(args.begin(), "Car");
    ActionsMap["GroundT"].Action(args);*/
//}

//void Actions::Truck(std::vector<std::string> args) {
   /* args.insert(args.begin(), "Truck");
    ActionsMap["GroundT"].Action(args);*/
//}

//void Actions::GroundT( std::vector<std::string> args )
//{
    //int amount = std::stoi(args[0]);
    /*int amount = 1;
    std::string resourceName = args[0];
    Coordinate coord(std::stoi(args[1])-1, std::stoi(args[2])-1);
    Cell* cell = Game::world->cellsHash->findCell(coord);
    if (cell != nullptr) {
        if ((*cell->typeIndexes)[CITY] != -1) {
            Settlement* city = Game::world->cellsTypesVectors->cities[(*cell->typeIndexes)[CITY]];
            int avaliableAmount = JsonConfig::CAPACITIES[city->TypeName()][JsonConfig::RESOURCETYPEASINDEX[resourceName]] - (*city->resources)[resourceName];
            amount = avaliableAmount > amount ? amount : avaliableAmount;
            (*city->resources)[resourceName] += amount;
            
        }
        else if ((*cell->typeIndexes)[VILLAGE] != -1) {
            Settlement* village = Game::world->cellsTypesVectors->villages[(*cell->typeIndexes)[VILLAGE]];
            int avaliableAmount = JsonConfig::CAPACITIES[village->TypeName()][JsonConfig::RESOURCETYPEASINDEX[resourceName]] - (*village->resources)[resourceName];
            amount = avaliableAmount > amount ? amount : avaliableAmount;
            (*village->resources)[resourceName] += amount;
        }
        else if ((*cell->typeIndexes)[GROUNDT] != -1) {
            throw "there is transport in this cell ";
        }
        else if ((*cell->typeIndexes)[ROAD] != -1) {
            Transport* transport = Game::world->cellsTypesVectors->transports[(*cell->typeIndexes)[GROUNDT]];
            int avaliableAmount = JsonConfig::CAPACITIES[transport->TypeName()][JsonConfig::RESOURCETYPEASINDEX[resourceName]] - (*transport->resources)[resourceName];
            amount = avaliableAmount > amount ? amount : avaliableAmount;
            (*transport->resources)[resourceName] += amount;
        }
        else {
            throw "car can be only at road / city / villlae ";
        }
    }
    else
    {
        Tile* tile = Game::world->GetTile(coord.x, coord.y);
        Transport* transport = new Transport(resourceName);

        int indexAtTransportVector = Game::world->cellsTypesVectors->AddTransport(transport);
        Cell* c = new Cell();
        (*c->typeIndexes)[GROUNDT] = indexAtTransportVector;
        Game::world->cellsHash->addCell(coord, c);
        (*tile->resources)[resourceName] += amount;
    }*/
//}

void Actions::People(std::vector<std::string> args)
{
    std::string resourceName = "People";
    int amount = std::stoi(args[0]);
    Coordinate coord(std::stoi(args[1]) - 1, std::stoi(args[2]) - 1);

    Manufacture1* manufacture = Game::world->SelectedHighObject(coord);
    People1* people = dynamic_cast<People1*>(manufacture);

    if(manufacture != nullptr){
        /*if ((*cell->typeIndexes)[CITY] != -1) {
            Settlement* city = Game::world->cellsTypesVectors->cities[(*cell->typeIndexes)[CITY]];
            int avaliableAmount = JsonConfig::CAPACITIES[city->TypeName()][JsonConfig::RESOURCETYPEASINDEX[resourceName]] - (*city->resources)[resourceName];
            amount = avaliableAmount > amount ? amount : avaliableAmount;
            (*city->resources)[resourceName] += amount;
        }
        else if ((*cell->typeIndexes)[VILLAGE] != -1) {
            Settlement* village = Game::world->cellsTypesVectors->villages[(*cell->typeIndexes)[VILLAGE]];
            int avaliableAmount = JsonConfig::CAPACITIES[village->TypeName()][JsonConfig::RESOURCETYPEASINDEX[resourceName]] - (*village->resources)[resourceName];
            amount = avaliableAmount > amount ? amount : avaliableAmount;
            (*village->resources)[resourceName] += amount;
        }
        else if ((*cell->typeIndexes)[GROUNDT] != -1) {
            Transport* transport = Game::world->cellsTypesVectors->transports[(*cell->typeIndexes)[GROUNDT]];
            int avaliableAmount = JsonConfig::CAPACITIES[transport->TypeName()][JsonConfig::RESOURCETYPEASINDEX[resourceName]] - (*transport->resources)[resourceName];
            amount = avaliableAmount > amount ? amount : avaliableAmount;
            (*transport->resources)[resourceName] += amount;
        }
        else if ((*cell->typeIndexes)[AIRT] != -1) {
            Transport* transport = Game::world->cellsTypesVectors->transports[(*cell->typeIndexes)[GROUNDT]];
            int avaliableAmount = JsonConfig::CAPACITIES[transport->TypeName()][JsonConfig::RESOURCETYPEASINDEX[resourceName]] - (*transport->resources)[resourceName];
            amount = avaliableAmount > amount ? amount : avaliableAmount;
            (*transport->resources)[resourceName] += amount;
        }*/
         if (people) {
            throw "there is people in this cell ";
        }
         else {
             manufacture->SetResource(amount, resourceName);
         }
        /*else {
            throw "people cant be on a road";
        }*/
    }
    else {
        Tile* tile = Game::world->GetTile(coord.x, coord.y);
        People1* people = new People1(resourceName);
        
        int indexAtPeopleVector =Game::world->cellsTypesVectors->AddPeople(people);
        Cell* c = new Cell();
        (*c->typeIndexes)[PEOPLE] = indexAtPeopleVector;
        Game::world->cellsHash->addCell(coord, c);
        (*tile->resources)[resourceName] += amount;
    }
}

void Actions::Work(std::vector<std::string> args)
{
    int x = std::stoi(args[0])-1, y = std::stoi(args[1])-1;
    Tile* selectedTile = Game::world->GetTile(selectedX,selectedY);
    Tile* newTile = Game::world->GetTile(x,y);
    Cell* selectedCell = Game::world->cellsHash->findCell({ selectedX, selectedY });
    Cell* newCell = Game::world->cellsHash->findCell({ x, y });

    if (selectedCell == nullptr || (*selectedCell->typeIndexes)[PEOPLE] == -1)
        throw "there is no people in your selected point";

    //walk todo: how to make timer (if i will do a loop the wait in the main will do also loop- multiply loops)
    //speed * the shortest path(can go in slant??)

    if (newCell != nullptr && (*newCell->typeIndexes)[PEOPLE]!=-1)
        throw "in every coordinate just 1 people can work";

    int indexAtPeopleVector = (*selectedCell->typeIndexes)[PEOPLE];
    (*selectedCell->typeIndexes)[PEOPLE] = -1;
    (*selectedTile->resources)["People"]--;

    if (newCell == nullptr) {
        newCell= new Cell();
    } 

    (*newCell->typeIndexes)[PEOPLE] = indexAtPeopleVector;
    //assume people can work just on tiles ( not on city  / village / road ) 
    (*newTile->resources)["People"]++;

    //doing the work
    if (newTile->resourceId < 3)
        throw "there is no resource to work with";

    (*newTile->resources)[JsonConfig::RESOUREC_TYPES[newTile->resourceId - 3]]--;

}

void Actions::Rain(std::vector<std::string> args)
{
    int timeOfRain = std::stoi(args[0]);
    for (auto tiles : Game::world->tilesMap)
    {
        for (auto tile : tiles)
        {
            tile->Rain(timeOfRain);
        }
    }
}

void Actions::Wait(std::vector<std::string> args)
{
    int time = std::stoi(args[0]);
    while (!waitActions.empty() && time > 0) {
        time--;
        //waitActions.Top()
    }
}

void Actions::Build(std::vector<std::string> args)
{
    std::string typeName = args[0];
    int locationX = std::stoi(args[1])-1;
    int locationY = std::stoi(args[2])-1;
    std::string state = args[3];

    int tempLocationX = locationX;
    int tempLocationY = locationY;

    int width = JsonConfig::SIZES[typeName].first;
    int height = JsonConfig::SIZES[typeName].second;

    std::vector<std::vector<Coordinate*>> manufactureCells(height, std::vector<Coordinate*>(width, nullptr));

    for (auto& row : manufactureCells) {
        for (auto& cell : row) {
            cell = new Coordinate(tempLocationX++, tempLocationY);
        }
        tempLocationX = locationX;
        tempLocationY += 1;
    }

  
    HelpActionsMap[typeName].Action(state, manufactureCells);

    // Clean up dynamically allocated memory (if no longer needed)
    for (auto& row : manufactureCells) {
        for (auto& cell : row) {
            delete cell;
        }
    }
}

void Actions::City(std::string state, std::vector<std::vector<Coordinate*>> cells) {
    
        bool validCity = true, hasRoad=false;
        int row = 0, cell = 0;

        //Detemine  all cells are ground or village
        while (validCity && row < cells.size()) {
            auto tempRow = cells[row];

            if (!hasRoad) {

                Cell* leftCell = Game::world->cellsHash->findCell({ (tempRow[0]->x) - 1, tempRow[0]->y +row });
                Cell* rightCell = Game::world->cellsHash->findCell({ (tempRow[tempRow.size()-1]->x) +1, tempRow[0]->y + row });
                if ((leftCell != nullptr && (*leftCell->typeIndexes)[ROAD] != -1 ) || (rightCell!= nullptr && (*rightCell->typeIndexes)[ROAD] != -1)) {
                    hasRoad = true;
                }
            }
            
            while (validCity && cell < cells[0].size()) {
                if (row == 0 && !hasRoad) {
                    Cell* aboveCell = Game::world->cellsHash->findCell({ (tempRow[cell]->x) , tempRow[0]->y + row - 1 });
                    if (aboveCell != nullptr && (*aboveCell->typeIndexes)[ROAD] != -1) {
                        hasRoad = true;
                    }
                }

                if (!(Game::world->GetTile(tempRow[cell]->x, tempRow[cell]->y)->resourceId == 1)) {
                    validCity = false;  
                }
                cell++;
            }
            row++;
        }

        if (validCity && (hasRoad || state == Command::START )){
            Settlement* city = new Settlement("City");

            if (state == Command::START) {
                city->isComplete = true;
            }

            int index = Game::world->cellsTypesVectors->AddCity(city);

            //Initialize  all the cells 
            for (auto& row : cells) {
                for (auto& cell : row) {
                    //assume there is no such a cell in that state of game (we are in start)
                    Cell* newCell =Game::world->cellsHash->findCell({ (cell->x) , (cell->y) });
                    newCell = newCell==nullptr? new Cell(): newCell;
                    (*newCell->typeIndexes)[CITY] = index;
                    Game::world->cellsHash->addCell({ cell->x,cell->y }, newCell);
                }
            }
        }
}

void Actions::Village(std::string state, std::vector<std::vector<Coordinate*>> cells) {
    
        bool validVillage = true, hasRoad = false;
        int row = 0, cell = 0;

        //Determine  all cells are ground or village
        while (validVillage && row < cells.size()) {
            auto tempRow = cells[row];

            if (!hasRoad) {

                Cell* leftCell = Game::world->cellsHash->findCell({ (tempRow[0]->x) - 1, tempRow[0]->y + row });
                Cell* rightCell = Game::world->cellsHash->findCell({ (tempRow[tempRow.size() - 1]->x) + 1, tempRow[0]->y + row });
                if ((leftCell != nullptr && (*leftCell->typeIndexes)[ROAD] != -1) || (rightCell != nullptr && (*rightCell->typeIndexes)[ROAD] != -1)) {
                    hasRoad = true;
                }
            }

            while (validVillage && cell < cells[0].size()) {
                if (row == 0 && !hasRoad) {
                    Cell* aboveCell = Game::world->cellsHash->findCell({ (tempRow[cell]->x) , tempRow[0]->y + row - 1 });
                    if (aboveCell != nullptr && (*aboveCell->typeIndexes)[ROAD] != -1) {
                        hasRoad = true;
                    }
                }

                if (!(Game::world->GetTile(tempRow[cell]->x, tempRow[cell]->y)->resourceId == 1)) {
                    validVillage = false;
                }
                cell++;
            }
            row++;
        }

        if (validVillage && (hasRoad || state == Command::START)) {
            Settlement* village = new Settlement("Village");

            if (state == Command::START) {
                village->isComplete = true;
            }

            int index = Game::world->cellsTypesVectors->AddVillage(village);

            //Initialize  all the cells 
            for (auto& row : cells) {
                for (auto& cell : row) {
                    //assume there is no such a cell in that state of game (we are in start)
                    Cell* newCell = Game::world->cellsHash->findCell({ (cell->x) , (cell->y) });
                    newCell = newCell == nullptr ? new Cell() : newCell;
                    (*newCell->typeIndexes)[VILLAGE] = index;
                    Game::world->cellsHash->addCell({ cell->x,cell->y }, newCell);
                }
            }
        }
}

void Actions::Road(std::string state, std::vector<std::vector<Coordinate*>> cells) {
    
        bool validRoad = true;
        int row = 0, cell = 0;

        //Detemine  all cells are ground 
        while (validRoad && row < cells.size()) {
            auto tempRow = cells[row];
            while (validRoad && cell < cells[0].size()) {
                if (!(Game::world->GetTile(tempRow[cell]->x, tempRow[cell]->y)->resourceId == 1)) {
                    validRoad = false;
                }
                cell++;
            }
            row++;
        }

        if (validRoad) {
            Road1* road = new Road1("Road");
            int index = Game::world->cellsTypesVectors->AddRoad(road);

            //Initialize  all the cells 
            for (auto& row : cells) {
                for (auto& cell : row) {
                    //assume there is no such a cell in that state of game (we are in start)
                    Cell* newCell = new Cell();
                    (*newCell->typeIndexes)[ROAD] = index;
                    Game::world->cellsHash->addCell({ cell->x,cell->y }, newCell);
                }
            }
            waitActions.push(road);
        }
}

void Actions::MakeEmpty(std::vector<std::string> args) {
    Manufacture1* m = Game::world->SelectedHighObject({ selectedX, selectedY });

    if (m != nullptr) {
        auto resources = m->GetResources();  
        for (auto& resource : *resources) {  
            resource.second = 0;  
        }
    }
}

void Actions::Manufacture(std::vector<std::string> args) {

    std::string state = args[3];
    int amount = 1;
    std::string resourceName = args[0];
    Coordinate coord(std::stoi(args[1])-1, std::stoi(args[2])-1);

    Manufacture1* manufacture = Game::world->SelectedHighObject(coord);
    Settlement* settlement = dynamic_cast<Settlement*>(manufacture);
    Transport* transport = dynamic_cast<Transport*>(manufacture);
    Road1* road = dynamic_cast<Road1*>(manufacture);
    People1* people = dynamic_cast<People1*>(manufacture);

    int index = 0;
    bool hasEnoughResources = true;
    //assume if it is not on start state it cant be on simple tile
    if (!(state == Command::START)&& manufacture!= nullptr) {
        for (int i = 0; i < (*manufacture->GetResources()).size()-3 && hasEnoughResources;i++) {
            if (!((*manufacture->GetResources())[JsonConfig::RESOUREC_TYPES[i]] >= JsonConfig::COSTS[resourceName][i])) {
                hasEnoughResources = false;
            }
        }
    }

    if (state == Command::START || hasEnoughResources) {

        Transport* newTransport = new Transport(resourceName);
        index = Game::world->cellsTypesVectors->AddTransport(newTransport);

        if (transport && resourceName != "Helicopter") {
            throw "2 transports cant be at the same cell";
        }
       /* else if (people) {
            throw "transport cant replace at cell contain people";
        }*/
       /* if(manufacture != nullptr){
            int avaliableAmount = JsonConfig::CAPACITIES[manufacture->TypeName()][JsonConfig::RESOURCETYPEASINDEX[resourceName]] - (*manufacture->GetResources())[resourceName];
            amount = avaliableAmount > amount ? amount : avaliableAmount;
            (*manufacture->GetResources())[resourceName] += amount;
        }*/
        if (settlement) {
            int avaliableAmount = JsonConfig::CAPACITIES[manufacture->TypeName()][JsonConfig::RESOURCETYPEASINDEX[resourceName]] - (*manufacture->GetResources())[resourceName];
            amount = avaliableAmount > amount ? amount : avaliableAmount;
            (*manufacture->GetResources())[resourceName] += amount;
            settlement->transportInSettlement.push_back(index);
        }
        else if (road) {
            Cell* cell = Game::world->cellsHash->findCell(coord);
            (*cell->typeIndexes)[GROUNDT] = index;
        }

        //i dont have to check if it is an air transport because helicopter will be the last type wich selectHighObject return
        else {
            // It doesn't make sense that a transport can be located in a tile, but the test maintains that it does.
            Tile* tile = Game::world->GetTile(coord.x, coord.y);
            Cell* c = new Cell();
            if(!(resourceName == "Helicopter")){
                (*c->typeIndexes)[GROUNDT] = index;
            }
            else {
                (*c->typeIndexes)[AIRT] = index;
            }
            Game::world->cellsHash->addCell(coord, c);
            (*tile->resources)[resourceName] += amount;
        }
        if (!(state == Command::START) && hasEnoughResources) {
            // Reduce all resources used to build the transport
            for (auto& resource : (*manufacture->GetResources())) {
                resource.second -= JsonConfig::COSTS[manufacture->TypeName()][JsonConfig::RESOURCETYPEASINDEX[resource.first]];
            }
        }
    }

}

void Actions::Deposit(std::vector<std::string> args) {

    Manufacture1* selectedCell = Game::world->SelectedHighObject({ selectedX-1,selectedY-1});
    Manufacture1* depositCell = Game::world->SelectedHighObject({ std::stoi(args[0])-1,std::stoi(args[1]) -1});

    if (selectedCell != nullptr && depositCell != nullptr) {
        for (auto& resource : (*selectedCell->GetResources())) {
            int avaliableAmount = JsonConfig::CAPACITIES[depositCell->TypeName()][JsonConfig::RESOURCETYPEASINDEX[resource.first]] - (*depositCell->GetResources())[resource.first];
            (*depositCell->GetResources())[resource.first] += fmin(avaliableAmount, resource.second);
            resource.second -= fmin(avaliableAmount, resource.second);
        }
    }
    //check if now we can start building
    if (!depositCell->IsComplete()) {
        //compare the resources with the costs
        //if true push to the queue
        //sub the taken resources for the building
    }
}

void Actions::TakeResource(std::vector<std::string> args) {

    Manufacture1* selectedCell = Game::world->SelectedHighObject({ selectedX,selectedY});
    Manufacture1* takenCell = Game::world->SelectedHighObject({ std::stoi(args[0]),std::stoi(args[1]) });

    if (selectedCell != nullptr && takenCell != nullptr) {
        for (auto& resource : (*takenCell->GetResources())) {
            int avaliableAmount = JsonConfig::CAPACITIES[selectedCell->TypeName()][JsonConfig::RESOURCETYPEASINDEX[resource.first]] - (*selectedCell->GetResources())[resource.first];
            (*selectedCell->GetResources())[resource.first] += fmin(avaliableAmount, resource.second);
            resource.second -= fmin(avaliableAmount, resource.second);
        }
    }
}

void Actions::Resources(std::vector<std::string> args) {

    Manufacture1* manufacture = Game::world->SelectedHighObject({ std::stoi(args[4]) ,std::stoi(args[5])});
    std::vector<int> resources(4); 

    std::transform(args.begin(), args.begin() + 4, resources.begin(), [](const std::string& str) {
        return std::stoi(str);
     });

    if (manufacture != nullptr) {
        int i = 0;
        for (auto& resourceAmount : resources) {
            int avaliableAmount = JsonConfig::CAPACITIES[manufacture->TypeName()][i] - (*manufacture->GetResources())[JsonConfig::RESOUREC_TYPES[i]];
            (*manufacture->GetResources())[JsonConfig::RESOUREC_TYPES[i++]] += fmin(avaliableAmount, resourceAmount);
        }
        //check if now we can start building
        if (!manufacture->IsComplete()) {
            //compare the resources with the costs
            //if true push to the queue
            //sub the taken resources for the building
        }
    }
}

void Actions::Move(std::vector<std::string> args) {

    Manufacture1* manufacture = Game::world->SelectedHighObject({ selectedX-1,selectedY-1});
    Transport* transport = dynamic_cast<Transport*>(manufacture);
    Coordinate coord(std::stoi(args[0]) - 1, std::stoi(args[1]) - 1);

    if (manufacture != nullptr && transport) {
        Cell* cell = Game::world->cellsHash->findCell({ selectedX-1, selectedY-1 });
        Cell* destination = Game::world->cellsHash->findCell(coord);
      
        if (destination == nullptr) {
            destination = new Cell();
            Game::world->cellsHash->addCell(coord, destination);
        }
        if ((*destination->typeIndexes)[ROAD] != -1) {
                (*destination->typeIndexes)[GROUNDT] = (*cell->typeIndexes)[GROUNDT];
                (*cell->typeIndexes)[GROUNDT] = -1;
        }
        else {
                (*destination->typeIndexes)[AIRT] = (*cell->typeIndexes)[AIRT];
                (*cell->typeIndexes)[AIRT] = -1;
        }

        lastElement = coord;
    }
}

Actions::Actions() 
{
    ActionsMap[Command::SELECT] = { &Actions::Select };
    ActionsMap[Command::RESOURCE] = { &Actions::Resource };
    ActionsMap[Command::PEOPLE] = { &Actions::People};
    ActionsMap[Command::WORK] = { &Actions::Work };
    ActionsMap[Command::RAIN] = { &Actions::Rain };
    ActionsMap[Command::WAIT] = { &Actions::Wait };
    ActionsMap[Command::BUILD] = { &Actions::Build };
    ActionsMap[Command::MAKE_EMPTY] = { &Actions::MakeEmpty };
    ActionsMap[Command::MANUFACTURE] = { &Actions::Manufacture };
    ActionsMap[Command::DEPOSIT] = { &Actions::Deposit };
    ActionsMap[Command::TAKE_RESOURCES] = { &Actions::TakeResource };
    ActionsMap[Command::RESOURCES] = { &Actions::Resources };
    ActionsMap[Command::MOVE] = { &Actions::Move };
   /* ActionsMap["Car"] = { &Actions::Car };
    ActionsMap["Truck"] = { &Actions::Truck };*/
    //ActionsMap["GroundT"] = { &Actions::GroundT };

    HelpActionsMap["City"] = { &Actions::City };
    HelpActionsMap["Village"] = { &Actions::Village };
    HelpActionsMap["Road"] = { &Actions::Road };

}
