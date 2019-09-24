#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "State.h"
class StateMachine;

#include "FPSCounter.h"
#include "Button.h"
#include "Text.h"
#include "MoreInfo.h"

class MainMenuState : public State {
	public:
		MainMenuState(StateMachine& machine, sf::RenderWindow& window, bool replace = true);
		~MainMenuState();

		void updateEvents();
		void update();
		void render();

	private:
		//Variables



		//Class objects
		FPSCounter fpsCounter;
		Button loginButton, joinButton, quitButton;
		Text titleText;
	

		//SFML
		sf::Event sfEvent;
};

#endif