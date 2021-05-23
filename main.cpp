#include <SFML/Graphics.hpp>

#include <iostream>
#include <exception>

#include "game.h"
#include "snake.h"
#include "context.h"

const auto timePerFrame = sf::seconds(1.f / 100.f);


int main() {
    Game game;
    Snake snake;
    sf::RenderWindow window (sf::VideoMode(1000, 1000), "My Snake Game");
    sf::Clock clock;
    sf::Time deltaTime = sf::Time::Zero;
    try {
        while (window.isOpen()) {

            sf::Time delta = clock.restart();
            deltaTime += delta;
            while (deltaTime > timePerFrame) {
                deltaTime -= timePerFrame;
                sf::Event event;
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
                }
                Context ctx(window, timePerFrame);
                snake.update(ctx);
                window.clear();             
                snake.render(window);
                window.display();
            }

        }
    } catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}