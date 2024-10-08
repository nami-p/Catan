#pragma once
#include <iostream>
#include <memory>
#include <unordered_map>


//typedef struct coordinate {
//	int x;
//	int y;
//
//}Coordinate;

class Tile
{

public:
	//coordinate corners[4];
	int resourceId;
	int tileHeight;
	int tileWidth;
	//std::shared_ptr<std::vector<std::vector<bool>>> peoplePositions;

	//for printing resources
	std::shared_ptr <std::unordered_map<std::string, int>> resources;

	Tile(int resourceId, int& tileWidth, int& tileHeight);
	void Rain(int time);
	Tile();
};




