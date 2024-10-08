#pragma once
#include <string>
#include <memory>
#include <vector>
#include <unordered_map>
#include "Manufacture.h"

//enum SettlementName {CAR , TRUCK , HELICOPTER };
//enum { WOOD, WOOL, IRON, BLOCKS, PEOPLE };

class Transport:public Manufacture1
{
public:


	//inital values from the json 
	std::vector<int> costs;//nedded resources
	std::vector<int> capicities;//maximum resources 
	int heghit;
	int width;
	double ticSpeed;


	std::shared_ptr <std::unordered_map<std::string, int>> resources;

	Transport(std::string name);
	std::string TypeName() override;
	std::shared_ptr<std::unordered_map<std::string, int>> GetResources() const override;
	void SetResource(int amount, std::string resourceName) override;

};

