#pragma once
#include "Transport.h"
#include "Settlement.h"
#include "People.h"
#include "Road.h"
#include<vector>
#include <unordered_map>

 enum types{ CITY, VILLAGE, GROUNDT, AIRT, ROAD, PEOPLE };

class Cell
{
public:

    //indexes At Types Vectors
    std::shared_ptr <std::vector<int>> typeIndexes;
    //std::unordered_map<std::string, std::shared_ptr <int>> typeIndexes;


    Cell();

    //suppose point to transport vector
    //std::vector < std::shared_ptr<Transport>>* transport = nullptr;

    /*int groundT_index = -1;
    int airTindex = -1;*/


    //suppose points to city or village  
    //(if this pointer is initalize so other pointers in the class are none)
    //std::vector < std::shared_ptr<ComplexStructure>>* complexStructure = nullptr;
    /*int settlemmentIndex = -1;*/


    //people index at place of cell
    /*int peopleIndex = -1;*/

};
