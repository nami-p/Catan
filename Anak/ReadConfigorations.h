#pragma once
#include <fstream>
#include <string>
#include <map>
#include <iostream>
//#include "json.hpp"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

class JsonConfig {

private:
	void InitResourceTypesAsIndex();
	void InitTiles();
	void InitStartingResources();
	void InitResourceTypes();
	void InitCosts();
	void InitCapacities();
	void InitSizes();
	void InitSpeeds();
	void InitRains();

public:
	static  std::map<int, std::string> TILES;
	static  std::map<std::string, int> STARTING_RESOURCES;
	static  std::vector <std::string> RESOUREC_TYPES;
	static  std::map<std::string, int> RESOURCETYPEASINDEX;
	static  std::map<std::string, std::vector<int>> COSTS;
	static  std::map<std::string, std::vector<int>> CAPACITIES;
	static  std::map<std::string, std::pair<int, int>> SIZES;
	static  std::map<std::string, double> SPEEDS;
	static  std::map<std::string, int> RAINS;

	json config;

	void loadConfig(const std::string& config_path){

		std::ifstream config_file(config_path);
		if (!config_file.is_open())
		{
			std::cout << "some problem accured while opening the json file" << std::endl;
			throw std::runtime_error("Could not open file");
		}
		config_file >> config;
		config_file.close();

		InitResourceTypesAsIndex();
		InitTiles();
		InitStartingResources();
		InitResourceTypes();
		InitCosts();
		InitCapacities();
		InitSizes();
		InitSpeeds();
		InitRains();
}


	//std::string findKeyByValue( const int& value) {

	//	for (auto it = TILES.begin(); it != TILES.end(); ++it) {
	//		if (it.value() == value) {
	//			return it.key();
	//		}
	//	}
	//	return "";  // Return empty std::string if key not found 
	//};

};