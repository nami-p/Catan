#include "Settlement.h"
#include "ReadConfigorations.h"

Settlement::Settlement(std::string typeName):Manufacture1(typeName), isComplete(false) {
	
	resources = std::make_shared<std::unordered_map<std::string, int>>();
	for (const auto& type : JsonConfig::RESOUREC_TYPES) {
		resources->emplace(type, 0);
	}
	(*resources)["People"] = JsonConfig::STARTING_RESOURCES[typeName];

	costs.resize(JsonConfig::COSTS[typeName].size());
	capicities.resize(JsonConfig::CAPACITIES[typeName].size());
	this->costs = JsonConfig::COSTS[typeName];
	this->capicities = JsonConfig::CAPACITIES[typeName];
	this->heghit = JsonConfig::SIZES[typeName].first;
	this->width = JsonConfig::SIZES[typeName].second;
	this->ticSpeed = JsonConfig::SPEEDS[typeName];
};
std::shared_ptr<std::unordered_map<std::string, int>> Settlement::GetResources() const{
	return resources;
}
std::string Settlement::TypeName() {
	return typeName;
};
void Settlement::SetResource(int amount, std::string resourceName) {
	int avaliableAmount = JsonConfig::CAPACITIES[typeName][JsonConfig::RESOURCETYPEASINDEX[resourceName]] - (*resources)[resourceName];
	amount = avaliableAmount > amount ? amount : avaliableAmount;
	(*resources)[resourceName] += amount;
};
bool Settlement::IsComplete() const {
	return isComplete;
}
