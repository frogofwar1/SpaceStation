#pragma once

#include <memory>
#include "SpaceStation.hpp"

class Robot
{
public:
	Robot(int _id);
	virtual ~Robot();

	void talk() const;
	void checkSpaceStation() const;
	void setStation(std::weak_ptr<SpaceStation> _s);

private:
	int id;
	float m_x;
	float m_y;
	float m_z;

	std::weak_ptr<SpaceStation> m_station;
};

