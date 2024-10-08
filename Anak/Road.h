#pragma once
#include <string>
#include <memory>
#include<vector>
#include "Manufacture.h"
#include "ReadConfigorations.h"

class Road1 : public Manufacture1
{
public:

	//inital values from the json 
	std::vector <int> costs;//nedded resources
	int heghit;
	int width;

	bool isComplete;

	Road1(std::string typeName);
	Road1();
	std::shared_ptr<std::unordered_map<std::string, int>> GetResources() const override;
	void SetResource(int amount ,std::string resourceName) override;
	std::string TypeName() override;
	bool IsComplete() const  override;
};

