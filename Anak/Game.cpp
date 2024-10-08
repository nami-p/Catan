#include "Game.h"

World* Game::world = nullptr;

Game::Game() {

	JsonConfig json;
	json.loadConfig("Configuration.json");

	input.parse_and_store();

	world = new World(input.world->data);
	actions = new Actions();
	asserts = new Asserts();
}

void Game::Play() {
	int selectedX = 0, selectedY = 0;
	StartGame();
	PlaySteps(selectedX, selectedY);
	Asserts1();
}

void Game::StartGame() {

	for (const auto& command : input.start) {

		if (command->name == Command::BUILD || command->name == Command::MANUFACTURE) {
			command->arguments.push_back(Command::START);
		}

		actions->ActionsMap[command->name].Action(command->arguments);

	}
}

Tile* selectedTile = new Tile();

void Game::PlaySteps(int& selectedX, int& selectedY) {

	for (const auto& command : input.steps) {

		if (command->name == Command::BUILD || command->name == Command::MANUFACTURE) {
			command->arguments.push_back("Steps");
		}

		actions->ActionsMap[command->name].Action(command->arguments);

		//if (command->name == Command::SELECT) {

		//	selectedX = std::stoi(command->arguments[0]);
		//	selectedY = std::stoi(command->arguments[1]);
		//	selectedTile = Select(selectedX, selectedX);
		//}
		//else if (command->name == Command::WORK) {

		//	int newX = std::stoi(command->arguments[0]);
		//	int newY = std::stoi(command->arguments[1]);
		//	Work(selectedX, selectedY, selectedTile, newX, newY);
		//}
		//else if (command->name == "Rain") {

		//	//rain effect all the inital resources tails ??
		//	for (const auto& resource : initalTilesResources) {

		//		if (resource->resourceName == "Wood" || resource->resourceName == "Wool") {

		//			int timeRain = json.config["Rains"][resource->resourceName];

		//			if (timeRain > std::stoi(command->arguments[0]))
		//				throw "There are no resources the rain affects them";

		//			//wait(timeRain);
		//			for (size_t time = timeRain; time > 0; time--);

		//			world.Rain(resource->resourceName, resource->x, resource->y);
		//		}
		//	}
		//}
		//if (command->name == "Wait") {
		//	//todo 
		//	//how to check the waiting?
		//}
	}

}

void Game::Asserts1() {
	for(const auto& assert: input.asserts){
		std::cout << assert << " ";
		asserts->AssertsMap[assert].Asserts(assert);
	}
}
