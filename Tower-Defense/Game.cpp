#include "Game.h"

void Game::playGame()
{
	setupGame();
	//_view->displayIntro();
	_view->displayMenu();

	setupRound();	
	
	while (0 < _player->getLife())
	{
		currentRound();
	}
}

void Game::critterFinishedRoad()
{
	_player->setLife(_player->getLife() - 1);

	if (_player->getLife() == 0)
	{
		_view->displayGameOver(LOST);
	}
}


void Game::setupGame()
{	
	// add Game to CritterManager observer
	_cm->addCritterObserver(this);
	// add Game to View observer
	_view->addViewObserver(this);

	_grid->loadRoads();
}

void Game::setupRound()
{
	_currentRound = 0;
	_view->setUpDisplay(_cm->getCrittersForRound(_currentRound), _grid->getRoad(_selectedRoad));
}

void Game::currentRound()
{	
	if(!_isPaused)
		_cm->moveActualRoundCritters(_currentRound, _grid->getRoad(_selectedRoad));
	
	_view->updateGraphic(_cm->getCrittersForRound(_currentRound));	
}

void Game::placeTower()
{
}

void Game::levelSelected(int selectedRoad)
{
	_selectedRoad = selectedRoad;
}