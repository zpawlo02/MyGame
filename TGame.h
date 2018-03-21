#ifndef TPLAYER_H
#define TPLAYER_H
#include <SFML/Graphics.hpp>


class TPlayer : public sf::Drawable
{
public:

	TPlayer(float t_X, float t_Y);
	TPlayer() = delete;
	virtual ~TPlayer() = default;
	void update();

	float moveRight();
	float moveLeft();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	sf::Texture *pTexture = &playerTexture;


private:
	
	


	const double playerVelocity{4};
	sf::Vector2f velocity{ playerVelocity, 0.f };




};

#endif // TPLAYER_H
