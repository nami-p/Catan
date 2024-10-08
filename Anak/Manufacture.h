#pragma once
#include <string>
#include <unordered_map>
#include <memory>

class Manufacture1
{
protected:
	std::string typeName;

public:
	 Manufacture1(std::string typeName) :typeName(typeName){}
	virtual ~Manufacture1() {}
	virtual std::string TypeName() = 0;
	virtual std::shared_ptr<std::unordered_map<std::string, int>> GetResources() const = 0;
	virtual void SetResource(int amount, std::string resourceName) = 0;
	virtual bool IsComplete() const { return false; };


};

