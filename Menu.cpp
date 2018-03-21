#include "Menu.h"
#include <SFML\Graphics.hpp>

#define WIDTH 900
#define HEIGTH 950

Menu::Menu(float width, float heigth)
{
	if (!font.loadFromFile("font.ttf"))
	{
		
	}
	menu[0].setFont(font);
	menu[0].setString("Play");
	menu[0].setFillColor(sf::Color::Red);
	
	menu[0].setPosition(sf::Vector2f(WIDTH / 2, HEIGTH / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setString("Exit");
	menu[1].setFillColor(sf::Color::White);
	menu[1].setPosition(sf::Vector2f(WIDTH / 2, HEIGTH / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	selectedItemIndex = 0;


}


void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS-1)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
