#include "Transport.h"
#include <string>
#include "ReadConfigorations.h"

Transport::Transport(std::string typeName) : Manufacture1(typeName) {

	resources = std::make_shared<std::unordered_map<std::string, int>>();
	for (const auto& type : JsonConfig::RESOUREC_TYPES) {
		resources->emplace(type, 0);
	}

	costs.resize(JsonConfig::COSTS[typeName].size());
	capicities.resize(JsonConfig::CAPACITIES[typeName].size());
	this->costs = JsonConfig::COSTS[typeName];
	this->capicities = JsonConfig::CAPACITIES[typeName];
	this->heghit = JsonConfig::SIZES[typeName].first;
	this->width = JsonConfig::SIZES[typeName].second;
	this->ticSpeed = JsonConfig::SPEEDS[typeName];
};

std::shared_ptr<std::unordered_map<std::string, int>> Transport::GetResources() const {
	return resources;
};
void Transport::SetResource(int amount, std::string resourceName) {
	int avaliableAmount = JsonConfig::CAPACITIES[typeName][JsonConfig::RESOURCETYPEASINDEX[resourceName]] - (*resources)[resourceName];
	amount = avaliableAmount > amount ? amount : avaliableAmount;
	(*resources)[resourceName] += amount;
};
std::string Transport::TypeName() {
	return typeName;
}