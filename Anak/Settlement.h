#pragma once
#include <string>
#include <memory>
#include<vector>
#include <unordered_map>
#include "Manufacture.h"

class Settlement : public Manufacture1
{
public:
	//int id;

	//inital values from the json 
	std::vector <int> costs;//nedded resources
	std::vector <int> capicities;//maximum resources 
	int heghit;
	int width;
	double ticSpeed;

	bool isComplete;
	std::shared_ptr <std::unordered_map<std::string, int>> resources;

	std::vector<int> peoplesInSettlement;
	std::vector<int> transportInSettlement;

	Settlement(std::string typeName);
	std::string TypeName() override;
	bool IsComplete() const override;
	std::shared_ptr<std::unordered_map<std::string, int>> GetResources() const override;
	void SetResource(int amount, std::string resourceName) override;


};

