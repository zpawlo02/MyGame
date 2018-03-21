#include "TGame.h"
#include "TBlocks.h"
#include "Menu.h"
#include <iostream>
#include <SFML\Graphics.hpp>\

#define WIDTH 900
#define HEIGTH 950

//DODAJ NALICZANIE PUNKTOW UŻYWAJAC CZASU 


TGame::TGame(TPlayer * player_, TBlocks * block_) : player(player_), block(block_), mWindow(sf::VideoMode(WIDTH, HEIGTH), "GAME") 
{
	mWindow.setFramerateLimit(60);
	
}


void TGame::run()
{
	sf::Clock clock;

	while (mWindow.isOpen())
	{
		
		processEvents();
		update_game();
		sf::Time elapsed = clock.getElapsedTime();
		std::cout << elapsed.asSeconds() << std::endl;
		render();
		
	}
}

void TGame::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			mWindow.close();
		

		break;
	}
}


void TGame::render()
{
	
	mWindow.clear();

	mWindow.draw(*block);
	mWindow.draw(*player);
	block->update_block();
	player->update();


	mWindow.display();
}

void TGame::update_game()
{
	
	

}

/*

bool TGame::PixelPerfectTest( ) 
{
	sf::FloatRect Intersection;
	if (Object1.getGlobalBounds().intersects(Object2.getGlobalBounds(), Intersection)) {
		sf::IntRect O1SubRect = Object1.getTextureRect();
		sf::IntRect O2SubRect = Object2.getTextureRect();

		sf::Uint8* mask1 = Bitmasks.GetMask(Object1.getTexture());
		sf::Uint8* mask2 = Bitmasks.GetMask(Object2.getTexture());

		for (int i = Intersection.left; i < Intersection.left + Intersection.width; i++) {
			for (int j = Intersection.top; j < Intersection.top + Intersection.height; j++) {

				sf::Vector2f o1v = Object1.getInverseTransform().transformPoint(i, j);
				sf::Vector2f o2v = Object2.getInverseTransform().transformPoint(i, j);

				if (o1v.x > 0 && o1v.y > 0 && o2v.x > 0 && o2v.y > 0 &&
					o1v.x < O1SubRect.width && o1v.y < O1SubRect.height &&
					o2v.x < O2SubRect.width && o2v.y < O2SubRect.height) {

					if (Bitmasks.GetPixel(mask1, Object1.getTexture(), (int)(o1v.x) + O1SubRect.left, (int)(o1v.y) + O1SubRect.top) > AlphaLimit &&
						Bitmasks.GetPixel(mask2, Object2.getTexture(), (int)(o2v.x) + O2SubRect.left, (int)(o2v.y) + O2SubRect.top) > AlphaLimit)
						return true;

				}
			}
		}
	}
	return false;
}
*/
