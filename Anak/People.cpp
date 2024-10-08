#include "People.h"
#include <memory>
#include "ReadConfigorations.h"

People1::People1(std::string typeName):Manufacture1(typeName) {
	id = ++count;
    resources = std::make_shared<std::unordered_map<std::string, int>>();
    for (const auto& type : JsonConfig::RESOUREC_TYPES) {
        resources->emplace(type, 0);
    }
};
std::string People1::TypeName() {
    return typeName;
};
std::shared_ptr<std::unordered_map<std::string, int>> People1::GetResources() const
{
    return resources;
}
void People1::SetResource(int amount, std::string resourceName) {
    int avaliableAmount = JsonConfig::CAPACITIES[typeName][JsonConfig::RESOURCETYPEASINDEX[resourceName]] - (*resources)[resourceName];
    amount = avaliableAmount > amount ? amount : avaliableAmount;
    (*resources)[resourceName] += amount;
};

int People1::count = 0;


