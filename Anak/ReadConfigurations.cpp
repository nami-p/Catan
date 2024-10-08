#include "ReadConfigorations.h"
#include <fstream>
#include <map>

std::map<int, std::string> JsonConfig::TILES;
std::map<std::string, int>JsonConfig::STARTING_RESOURCES;
std::vector<std::string> JsonConfig::RESOUREC_TYPES;
std::map<std::string, int>JsonConfig::RESOURCETYPEASINDEX;
std::map<std::string, std::vector<int>>JsonConfig::COSTS;
std::map<std::string, std::vector<int>>JsonConfig::CAPACITIES;
std::map<std::string, std::pair<int, int>>JsonConfig::SIZES;
std::map<std::string, double>JsonConfig::SPEEDS;
std::map<std::string, int>JsonConfig::RAINS;




void JsonConfig::InitTiles()
{
	auto tiles = config["Tiles"].get<std::map<std::string, int>>();
	for (const auto& pair : tiles)
	{
		TILES[pair.second] = pair.first;
	}
}
void JsonConfig::InitCapacities()
{
	CAPACITIES = config["Capacities"].get < std::map<std::string, std::vector<int>>>();
}
void JsonConfig::InitCosts()
{
	COSTS = config["Costs"].get<std::map<std::string, std::vector<int>>>();
}
void JsonConfig::InitResourceTypes()
{
	RESOUREC_TYPES = config["ResourceTypes"].get<std::vector<std::string>>();
}
void JsonConfig::InitResourceTypesAsIndex()
{
	RAINS = config["ResourceTypesAsIndex"].get<std::map<std::string, int>>();
}
void JsonConfig::InitSizes()
{
	SIZES = config["Sizes"].get<std::map<std::string, std::pair<int, int>>>();
}
void JsonConfig::InitStartingResources()
{
	STARTING_RESOURCES = config["StartingResources"].get<std::map<std::string, int>>();
}
void JsonConfig::InitRains()
{
	RAINS = config["Rains"].get<std::map<std::string, int>>();
}
void JsonConfig::InitSpeeds()
{
	SPEEDS = config["Speeds"].get <std::map<std::string, double>>();
}
