#include <iostream>
#include "SpaceStation.hpp"
#include "Robot.hpp"


#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>




int main() {

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::cout << "Space Station 1" << std::endl;

	std::shared_ptr<SpaceStation> spaceStation = std::make_shared<SpaceStation>();
	spaceStation->init();
	spaceStation->printStatus();
	spaceStation->setPositionX(10);
	spaceStation->setPositionY(15);
	spaceStation->setPositionZ(20);

	auto allRobot = spaceStation->getRobots();
	if (!allRobot.expired())
	{
		for (int botNum = 0; botNum < 20; botNum++) {
			allRobot.lock()->at(botNum).talk();
			allRobot.lock()->at(botNum).checkSpaceStation();
		}
	}

	std::cout << "" << std::endl;

	std::cout << "Space Station 2" << std::endl;

	std::shared_ptr<SpaceStation> spaceStation2 = spaceStation;
	spaceStation2->init();
	spaceStation2->printStatus();

	auto allRobot2 = spaceStation2->getRobots();
	if (!allRobot2.expired())
	{
		for (int botNum = 0; botNum < 20; botNum++) {
			allRobot2.lock()->at(botNum).talk();
			allRobot2.lock()->at(botNum).checkSpaceStation();
		}
	}

	std::cout << "" << std::endl;

	spaceStation->setPositionX(30);
	spaceStation->setPositionY(35);
	spaceStation->setPositionZ(40);

	std::cout << "Space Station 1" << std::endl;
	spaceStation->printStatus();
	std::cout << "Space Station 2" << std::endl;
	spaceStation2->printStatus();

	std::cout << "" << std::endl;

	std::cout << "Space Station 3" << std::endl;

	std::shared_ptr<SpaceStation> spaceStation3 = std::make_shared<SpaceStation>();
	spaceStation3 = spaceStation2;
	spaceStation3->init();
	spaceStation3->printStatus();

	auto allRobot3 = spaceStation3->getRobots();
	if (!allRobot3.expired())
	{
		for (int botNum = 0; botNum < 20; botNum++) {
			allRobot3.lock()->at(botNum).talk();
			allRobot3.lock()->at(botNum).checkSpaceStation();
		}
	}

	std::cout << "" << std::endl;

	spaceStation2->setPositionX(100);
	spaceStation2->setPositionY(150);
	spaceStation2->setPositionZ(200);

	std::cout << "Space Station 1" << std::endl;
	spaceStation->printStatus();
	std::cout << "Space Station 2" << std::endl;
	spaceStation2->printStatus();
	std::cout << "Space Station 3" << std::endl;
	spaceStation3->printStatus();

	getchar();


}