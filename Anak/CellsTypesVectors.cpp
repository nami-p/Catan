#include "CellsTypesVectors.h"

CellsTypesVectors::CellsTypesVectors() :cIndex(0),Vindex(0),rIndex(0),Tindex(0) {
	/*types["Road"] = std::make_shared<std::vector<Transport>>();
	types["Village"] = std::make_shared<std::vector<Settlement>>();
	types["City"] = std::make_shared<std::vector<Settlement>>();
	types["Car"] = std::make_shared<std::vector<Transport>>();
	types["Truck"] = std::make_shared<std::vector<Transport>>();
	types["Helicopter"] = std::make_shared<std::vector<Transport>>();*/
}

int CellsTypesVectors::AddPeople(People1* p) {
	peoples.push_back(p);
	return pIndex++;
}
int CellsTypesVectors::AddTransport(Transport* t) {
	transports.push_back(t);
	return Tindex++;
}
int CellsTypesVectors::AddCity(Settlement *c) {
	cities.push_back(c);
	return cIndex++;
}
int CellsTypesVectors::AddVillage(Settlement *v) {
	villages.push_back(v);
	return Vindex++;
}
int CellsTypesVectors::AddRoad(Road1 *r) {
	roads.push_back(r);
	return rIndex++;
}