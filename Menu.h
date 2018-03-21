#pragma once
#include <SFML\Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 3


class Menu 
{
public:
	Menu(float width, float heigth);
	~Menu()=default;

	void draw(sf::RenderWindow &widnow);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }



private:
	sf::RenderWindow menuWindow;
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

};

