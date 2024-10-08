#pragma once
#include <vector>
#include "People.h"
#include "Transport.h"
#include "Settlement.h"
#include "Road.h"

class CellsTypesVectors
{
public:

    //std::unordered_map<std::string, std::shared_ptr<std::vector<Manufacture>>> types;
    std::vector<People1*> peoples;

    std::vector<Transport*> transports;

    std::vector<Settlement*> cities;

    std::vector<Settlement*> villages;

    std::vector<Road1*> roads;

    CellsTypesVectors();

    int AddPeople(People1* p);
    int AddTransport(Transport* t);
    int AddCity(Settlement *c);
    int AddVillage(Settlement* v);
    int AddRoad(Road1* r);

//private:
    int pIndex;
    int Tindex;
    int cIndex;
    int Vindex;
    int rIndex;

};

