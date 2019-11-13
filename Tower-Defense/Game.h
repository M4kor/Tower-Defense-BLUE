#pragma once
#include <memory>

#include "Player.h"
#include "View.h"
#include "Grid.h"
#include "CritterManager.h"
#include "Observer.h"

class Game : public CritterObserver, public ViewObserver
{	  
private:
	void setupGame();
	void setupRound();
	void currentRound();

public:
	Game(int defaultRoad = 0, int currentRound = 0, bool isPaused = false) : 
		_player(std::make_unique<Player>()), _view(std::make_unique<View>()), _grid(std::make_shared<Grid>()), _cm(std::make_shared<CritterManager>()), 
		_selectedRoad(defaultRoad), _currentRound(currentRound), _isPaused(isPaused)
	{		
	}

	void playGame();

	// Events
	// Inherited via CritterObserver
	virtual void critterFinishedRoad() override;
	// Inherited via ViewObserver
	virtual void placeTower() override;
	virtual void levelSelected(int selectedLevel) override;

private:
	std::unique_ptr<Player> _player;
	std::unique_ptr<View> _view;
	std::shared_ptr<Grid> _grid;
	std::shared_ptr<CritterManager> _cm;
		
	int _currentRound;	
	int _selectedRoad;
	bool _isPaused;
};