#include "Asserts.h"
#include "Actions.h"
#include "Game.h"


std::unordered_map<std::string, AssertsHandler> Asserts::AssertsMap;

void Asserts::SelectedCategory(std::string assert) {
    Manufacture1* manufacture = Game::world->SelectedHighObject({ Actions::selectedX,Actions::selectedY });

    if (manufacture != nullptr) {
        std::cout << manufacture->TypeName() << std::endl;
    }
    else {
        std::cout << JsonConfig::TILES[Actions::selectedTile->resourceId] << std::endl;
    }
}

void Asserts::SelectedResource(std::string assert) {
    Manufacture1* manufacture = Game::world->SelectedHighObject({ Actions::selectedX,Actions::selectedY });

    if (manufacture != nullptr) {
        auto resources = manufacture->GetResources();
        if (resources)
        {
            for (int resourceIndex = 0; resourceIndex < 4; resourceIndex++) {
                std::cout << " " << (*resources)[JsonConfig::RESOUREC_TYPES[resourceIndex]];
            }
            std::cout << std::endl;
        }
    }
    else {
        for (int resourceIndex = 0; resourceIndex < 4; resourceIndex++) {
            std::cout << " " << (*Actions::selectedTile->resources)[JsonConfig::RESOUREC_TYPES[resourceIndex]];
        }
        std::cout << std::endl;
    }
}

void Asserts::CityCount(std::string assert) {
    std::cout << Game::world->cellsTypesVectors->cities.size() << std::endl;
}

void Asserts::RoadCount(std::string assert) {
    std::cout << Game::world->cellsTypesVectors->roads.size() << std::endl;
}

void Asserts::VillageCount(std::string assert) {
    std::cout << Game::world->cellsTypesVectors->villages.size() << std::endl;
}

void Asserts::CarCount(std::string assert) {
    std::cout << std::count_if(Game::world->cellsTypesVectors->transports.begin(), Game::world->cellsTypesVectors->transports.end(), []( Transport* transport) {
        return transport->TypeName() == "Car";
        }) << std::endl;
}

void Asserts::TruckCount(std::string assert) {
    std::cout << std::count_if(Game::world->cellsTypesVectors->transports.begin(), Game::world->cellsTypesVectors->transports.end(), []( Transport* transport) {
        return transport->TypeName() == "Truck";
        }) << std::endl;
}

void Asserts::HelicopterCount(std::string assert) {
    std::cout << std::count_if(Game::world->cellsTypesVectors->transports.begin(), Game::world->cellsTypesVectors->transports.end(), []( Transport* transport) {
        return transport->TypeName() == "Helicopter";
        }) << std::endl;
}

void Asserts::SelectedComplete(std::string assert) {
    Manufacture1* manufacture = Game::world->SelectedHighObject({ Actions::selectedX,Actions::selectedY });

    if (manufacture != nullptr && manufacture->IsComplete()) {
        std::cout << "true" << std::endl;
    }
    else {
        std::cout << "false" << std::endl;
    }
}

void Asserts::SelectedCar(std::string assert) {
    Manufacture1* manufacture = Game::world->SelectedHighObject({ Actions::selectedX,Actions::selectedY });

    if (manufacture != nullptr) {
        std::cout << (*manufacture->GetResources())["Car"] << std::endl;
    }
    else {
        if (!(Actions::selectedTile == nullptr))
            std::cout << (*Actions::selectedTile->resources)["Car"] << std::endl;
    }
}

void Asserts::SelectedPeople(std::string assert) {
    Manufacture1* manufacture = Game::world->SelectedHighObject({ Actions::selectedX,Actions::selectedY });

    if (manufacture != nullptr) {
        std::cout << (*manufacture->GetResources())["People"] << std::endl;
    }
    else {
        if (!(Actions::selectedTile == nullptr))
            std::cout << (*Actions::selectedTile->resources)["People"] << std::endl;
    }
}

void Asserts::SelectedTruck(std::string assert) {
    Manufacture1* manufacture = Game::world->SelectedHighObject({ Actions::selectedX,Actions::selectedY });

    if (manufacture != nullptr) {
        std::cout << (*manufacture->GetResources())["Truck"] << std::endl;
    }
    else {
        if (!(Actions::selectedTile == nullptr))
            std::cout << (*Actions::selectedTile->resources)["Truck"] << std::endl;
    }
}

void Asserts::SelectedCoordinates(std::string assert) {
    std::cout << (Actions::lastElement.x ) / 5 << " " << (Actions::lastElement.y ) / 5 << std::endl;
}

Asserts::Asserts()
{
    AssertsMap["SelectedCategory"] = { &Asserts::SelectedCategory };
    AssertsMap["SelectedResource"] = { &Asserts::SelectedResource };
    AssertsMap["CityCount"] = { &Asserts::CityCount };
    AssertsMap["RoadCount"] = { &Asserts::RoadCount };
    AssertsMap["CarCount"] = { &Asserts::CarCount };
    AssertsMap["TruckCount"] = { &Asserts::TruckCount };
    AssertsMap["HelicopterCount"] = { &Asserts::HelicopterCount };
    AssertsMap["VillageCount"] = { &Asserts::VillageCount };
    AssertsMap["SelectedComplete"] = { &Asserts::SelectedComplete };
    AssertsMap["SelectedCar"] = { &Asserts::SelectedCar };
    AssertsMap["SelectedPeople"] = { &Asserts::SelectedPeople };
    AssertsMap["SelectedTruck"] = { &Asserts::SelectedTruck };
    AssertsMap["SelectedCoordinates"] = { &Asserts::SelectedCoordinates };
}