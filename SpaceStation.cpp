#include <iostream>

#include "Robot.hpp"
#include "SpaceStation.hpp"


SpaceStation::SpaceStation()
	:m_posX(0), m_posY(0), m_posZ(0), botNum(20)
{
}

SpaceStation::SpaceStation(const SpaceStation &_s)
	: m_posX(_s.m_posX), m_posY(_s.m_posY), m_posZ(_s.m_posZ), botNum(_s.botNum)
{
}


SpaceStation::~SpaceStation()
{
}

SpaceStation& SpaceStation::operator = (const SpaceStation &_s)
{
	m_posX = _s.m_posX;
	m_posY = _s.m_posY;
	m_posZ = _s.m_posZ;
	botNum = _s.botNum;
	return *this;
}

void SpaceStation::init()
{
	m_robot = std::make_shared<std::vector<Robot>>();
	//m_robot(new std::vector<Robot>, [](std::vector<Robot>* p) {delete[] p; });


	for (int i = 0; i < botNum; i++) {
		m_robot->push_back(Robot(i));
	}

	// shared_from_this requires the object to exist, so
	// it cannot use within intializer.
	for (int i = 0; i < botNum; i++) {
		m_robot->at(i).setStation(shared_from_this());
	}
}


void SpaceStation::printStatus() const
{
	std::cout << "Space Station location is " << "x "
		<< m_posX << ", y " << m_posY << ", z " << m_posZ << std::endl;
}


std::weak_ptr<std::vector<Robot>> SpaceStation::getRobots() const
{
	return m_robot;
}

float SpaceStation::getPositionX() const {
	return m_posX;
}

float SpaceStation::getPositionY() const {
	return m_posY;
}

float SpaceStation::getPositionZ() const {
	return m_posZ;
}

void SpaceStation::setPositionX(float _posX) {
	m_posX = _posX;
}

void SpaceStation::setPositionY(float _posY) {
	m_posY = _posY;
}

void SpaceStation::setPositionZ(float _posZ) {
	m_posZ = _posZ;
}