#pragma once
#include <vector>

//Forward Decoration
class Robot;

class SpaceStation final : public std::enable_shared_from_this <SpaceStation>
{
public:
	SpaceStation();
	SpaceStation(const SpaceStation &_s);
	virtual ~SpaceStation();

	SpaceStation& operator = (const SpaceStation &_s);

	void init();

	void printStatus() const;
	std::weak_ptr<std::vector<Robot>> getRobots() const;

	float getPositionX() const;
	float getPositionY() const;
	float getPositionZ() const;

	void setPositionX(float _posX);
	void setPositionY(float _posY);
	void setPositionZ(float _posZ);



private:
	float m_posX;
	float m_posY;
	float m_posZ;
	int botNum;

	std::shared_ptr<std::vector<Robot>> m_robot;
};

