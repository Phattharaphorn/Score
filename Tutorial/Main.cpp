#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include <vector>
#include "Score.h"

using namespace std;
using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game", Style::Titlebar | Style::Close);

    Score score(window.getSize().x, window.getSize().y);
    window.setVerticalSyncEnabled(true);
    srand(time(NULL));
    
    float deltaTime = 0;
    Clock clock;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code) {
                case sf::Keyboard::Left:
                    score.MoveLeft();
                    break;

                case sf::Keyboard::Right:
                    score.MoveRight();
                    break;
                }
                break;
            case sf::Event::Closed:
                window.close();
                break;
            }
        }
        window.clear();
        score.draw(window);
        window.display();
    }
    return 0;
}
