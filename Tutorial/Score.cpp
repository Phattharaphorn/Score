#include "Score.h"

Score::Score(float width, float height)
{
	this->size = sf::Vector2f(800.0f, 600.0f);
	selectedItem = 0;

	scoreTexture.loadFromFile("score.jpg");
	scoreSprite.setTexture(scoreTexture);

	if (!font.loadFromFile("SDfont.ttf"))
	{
		//handle error
	}
	score[0].setFont(font);
	score[0].setCharacterSize(60);
	score[0].setFillColor(sf::Color::Yellow);
	score[0].setString("Back");
	score[0].setOrigin(score[0].getGlobalBounds().width / 2, score[0].getGlobalBounds().height / 2);
	score[0].setPosition(sf::Vector2f(width / 2.6, height / (SCORE_ITEMS + 1) * 2.5));

	score[1].setFont(font);
	score[1].setCharacterSize(60);
	score[1].setFillColor(sf::Color::Black);
	score[1].setString("Exit");
	score[1].setOrigin(score[1].getGlobalBounds().width / 2, score[1].getGlobalBounds().height / 2);
	score[1].setPosition(sf::Vector2f(width / 1.58, height / (SCORE_ITEMS + 1.60) * 3));

}

Score::~Score()
{

}

void Score::draw(sf::RenderWindow& window)
{
	window.draw(scoreSprite);
	for (int i = 0; i < SCORE_ITEMS; i++)
	{
		window.draw(score[i]);
	}
}

void Score::MoveLeft()
{
	if (selectedItem - 1 >= 0)
	{
		score[selectedItem].setFillColor(sf::Color::Black);
		selectedItem--;
		score[selectedItem].setFillColor(sf::Color::Yellow);

	}
}

void Score::MoveRight()
{
	if (selectedItem + 1 < SCORE_ITEMS)
	{

		score[selectedItem].setFillColor(sf::Color::Black);
		selectedItem++;
		score[selectedItem].setFillColor(sf::Color::Yellow);

	}
}
