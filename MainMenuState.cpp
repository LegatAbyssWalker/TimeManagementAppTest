#include "MainMenuState.h"

#include "State.h"
#include "StateMachine.h"

#include "PlayingState.h"
#include "MoreInfo.h"

#include <iostream>
#include <fstream>

MainMenuState::MainMenuState(StateMachine& machine, sf::RenderWindow& window, bool replace)
	: State{ machine, window, replace },
	//Text
	titleText(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 4 + 20, 50, ARIAL_FONT, "Time Management App!", sf::Color(255, 255, 255)),
	//Buttons
	loginButton(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 3 + 100, 100, 40, 30, ARIAL_FONT, "Login",
		sf::Color(0, 0, 0), sf::Color(0, 0, 0), sf::Color(0, 0, 0), sf::Color(255, 255, 255), sf::Color(0, 255, 255)),
	joinButton(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 3 + 200, 100, 40, 30, ARIAL_FONT, "Create Account",
		sf::Color(0, 0, 0), sf::Color(0, 0, 0), sf::Color(0, 0, 0), sf::Color(255, 255, 255), sf::Color(0, 255, 255)),
	quitButton(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 300, 100, 40, 30, ARIAL_FONT, "Quit",
		sf::Color(0, 0, 0), sf::Color(0, 0, 0), sf::Color(0, 0, 0), sf::Color(255, 255, 255), sf::Color(0, 255, 255)) {
	

}

MainMenuState::~MainMenuState() {
	//
}

void MainMenuState::updateEvents() {
	sf::Vector2<int> mousepos = sf::Mouse::getPosition(window);

	//Updating mouse position for button functionality
	loginButton.update(sf::Vector2<float>(mousepos));
	joinButton.update(sf::Vector2<float>(mousepos));
	quitButton.update(sf::Vector2<float>(mousepos));
	
	//Events while loop
	while (window.pollEvent(sfEvent)) {
		switch (sfEvent.type) {
			case sf::Event::Closed:
				machine.quit();
				break;

			case sf::Event::MouseButtonPressed:
				if (loginButton.isPressed() == true) { machine.run(machine.buildState<PlayingState>(machine, window, true)); }
				if (quitButton.isPressed() == true) { machine.quit(); }

		}
	}

}

void MainMenuState::update() {
	fpsCounter.updateCounter();
}

void MainMenuState::render() {
	window.clear();

	//Render items
	loginButton.renderTo(window);
	joinButton.renderTo(window);
	quitButton.renderTo(window);

	titleText.renderTo(window);
	fpsCounter.renderTo(window);


	window.display();
}
