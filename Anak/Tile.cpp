
#include "Tile.h"
#include "ReadConfigorations.h"


Tile::Tile(int resourceId, int& tileWidth, int& tileHeight) : resourceId(resourceId) {

    resources = std::make_shared<std::unordered_map<std::string, int>>();
    for (const auto& type : JsonConfig::RESOUREC_TYPES) {
        resources->emplace(type, 0);
    }
    // Initialize corners 
}

void Tile::Rain(int time) {
    if(resourceId >=3){
         std::string resourceName = JsonConfig::RESOUREC_TYPES[ resourceId-3];
        //checking if the rain indeed growing up the resource
        if (JsonConfig::RAINS.find(resourceName) != JsonConfig::RAINS.end())
        if (time > JsonConfig::RAINS[resourceName])
            //the resource grows up according to the rain time
            (*resources)[resourceName]+=((int)time / JsonConfig::RAINS[resourceName]);
    }
}
Tile::Tile() {}
#include "Tile.h"
