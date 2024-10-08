#include "Road.h"


Road1::Road1(std::string typeName) : Manufacture1(typeName),isComplete(false) {

	costs.resize(JsonConfig::COSTS[typeName].size());
	this->costs = JsonConfig::COSTS[typeName];
	this->heghit = JsonConfig::SIZES[typeName].first;
	this->width = JsonConfig::SIZES[typeName].second;
}
std::shared_ptr<std::unordered_map<std::string, int>> Road1::GetResources() const {
	return nullptr;
}
void Road1::SetResource(int amount, std::string resourceName) {

}
std::string Road1::TypeName() {
	return typeName;
}
bool Road1::IsComplete() const{
	return isComplete;
}