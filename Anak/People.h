#pragma once
#include <iostream>
#include <memory>
#include <unordered_map>
#include "Manufacture.h"

class People1:public Manufacture1
{

	//enum { WOOD, WOOL, IRON, BLOCKS, PEOPLE };

public:
	int id;
	std::shared_ptr <std::unordered_map<std::string,int>> resources;
	People1(std::string typeName) ;
	std::string TypeName()override;
	std::shared_ptr<std::unordered_map<std::string, int>> GetResources() const override;
	void SetResource(int amount, std::string resourceName) override;


private:
	static int count; //for id

};

