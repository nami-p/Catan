#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <functional>


struct AssertsHandler {
    void (*Asserts)(std::string);
};


class Asserts
{
public:

    // Map to store Asserts names and their corresponding functions
    static std::unordered_map<std::string, AssertsHandler> AssertsMap;

    // Asserts methods
    static void SelectedCategory(std::string assert);
    static void SelectedResource(std::string assert);
    static void CityCount(std::string assert);
    static void RoadCount(std::string assert);
    static void CarCount(std::string assert);
    static void TruckCount(std::string assert);
    static void HelicopterCount(std::string assert);
    static void VillageCount(std::string assert);
    static void SelectedComplete(std::string assert);
    static void SelectedCar(std::string assert);
    static void SelectedPeople(std::string assert);
    static void SelectedTruck(std::string assert);
    static void SelectedCoordinates(std::string assert);


    Asserts();

};
