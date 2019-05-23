#include <iostream>

#include "Robot.hpp"
#include "SpaceStation.hpp"


Robot::Robot(int _id)
	: id(_id), m_x(0), m_y(0), m_z(0)
{
}


Robot::~Robot()
{
}

void Robot::talk() const {
	std::cout << "Peep peep my ID is " << id << std::endl;
}

void Robot::checkSpaceStation() const
{
	if (!m_station.expired())
	{
		m_station.lock()->printStatus();
	}
}


void Robot::setStation(std::weak_ptr<SpaceStation> _station)
{
	m_station = _station;
}