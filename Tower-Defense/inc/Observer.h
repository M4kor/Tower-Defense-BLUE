#pragma once

class Tower;

class Observer {
    public:
	    virtual ~Observer() {}	    
};

class CritterObserver : public Observer
{
public:
	virtual void critterFinishedRoad() = 0;
};


class ViewObserver : public Observer
{
public:
	virtual void levelSelected (int selectedLevel) = 0;
	virtual void endGameRequest() = 0;

	virtual void towerPlaced(int type, Position towerPos) = 0;
	virtual void buyTower(Tower* tower) = 0;
	virtual void sellTower(Tower* tower) = 0;
	virtual void upgradeTower(Tower* tower) = 0;
};
