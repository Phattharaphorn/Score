#pragma once
#include "SFML/Graphics.hpp"
#define SCORE_ITEMS 2 //back exit 
class Score
{
public:
	 Score(float width, float height);
	~Score();

	void draw(sf::RenderWindow& window);
	void MoveLeft();
	void MoveRight();

private:
	int selectedItem;
	sf::Vector2f size;
	sf::Vector2f position;
	sf::Font font;
	sf::Text score[SCORE_ITEMS]; //back exit 
	sf::Texture scoreTexture;
	sf::Sprite scoreSprite;

};

