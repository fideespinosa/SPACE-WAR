#include "PauseMenu.h"

PauseMenu::PauseMenu() {
	_font.loadFromFile("SPACE.ttf");
	arrow.loadFromFile("img/arrow.png");
	background.loadFromFile("img/Pause.jpg");

	pause.setFont(_font);
	resume.setFont(_font);
	exit.setFont(_font);

	pause.setString("PAUSE");
	pause.setStyle(sf::Text::Underlined);
	pause.setStyle(sf::Text::Italic);
	pause.setOutlineThickness(2);
	pause.setOutlineColor(sf::Color::Black);

	resume.setStyle(sf::Text::Italic);
	exit.setStyle(sf::Text::Italic);

	resume.setOutlineColor(sf::Color::White);
	exit.setOutlineColor(sf::Color::White);

	resume.setString("Resume");
	exit.setString("Exit");

	pause.setPosition(450, 110);
	resume.setPosition(450, 225);
	exit.setPosition(450, 275);

	img.setTexture(background);
	indicator.setTexture(arrow);

	indicator.setRotation(90);
	img.setPosition(200, 100);
}

bool PauseMenu::Pause(sf::RenderWindow& window)
{
	resume.setFillColor(sf::Color::White);
	exit.setFillColor(sf::Color::Transparent);
	exit.setOutlineThickness(1);
	resume.setOutlineThickness(2);
	resume.setOutlineColor(sf::Color::Black);
	exit.setOutlineColor(sf::Color::White);
	indicator.setPosition(420, 225);

	int pos = 1;
	bool state = true;
	while (state==true) {



		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) and pos == 1) {
			pos = 2;
			indicator.setPosition(420, 275);
			resume.setFillColor(sf::Color::Transparent);
			exit.setFillColor(sf::Color::Red);
			exit.setOutlineThickness(2);
			resume.setOutlineColor(sf::Color::White);
			resume.setOutlineThickness(1);
			exit.setOutlineColor(sf::Color::Black);
			
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and pos == 2) {
			pos = 1;
			indicator.setPosition(420, 225);
			exit.setFillColor(sf::Color::Transparent);
			resume.setFillColor(sf::Color::White);
			resume.setOutlineThickness(2);
			exit.setOutlineColor(sf::Color::White);
			exit.setOutlineThickness(1);
			resume.setOutlineColor(sf::Color::Black);
			
			}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {

			switch (pos)
			{
			case 1:
				return true; //continua el juego
				break;
			case 2:
				return false;
				break;
			default:
				break;
			}
		}
		window.draw(img);
		window.draw(pause);
		window.draw(exit);
		window.draw(resume);
		window.draw(indicator);
		window.display();

	}

}
