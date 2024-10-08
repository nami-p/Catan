#include "Cell.h"

Cell::Cell():typeIndexes(std::make_shared<std::vector<int>>(std::vector<int>{-1, -1, -1, -1, -1 ,-1})) {

}

//for (const auto& type : JsonConfig::COSTS) {
//    //acces the key of the costs and place as the typeindexex key 
//    typeIndexes->emplace(type, std::make_shared<int>(-1));
//}