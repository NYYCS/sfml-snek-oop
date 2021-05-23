#include <SFML/Graphics.hpp>

#include "game.h"
#include "util.h"

Game::Game() : fruitSprite(10) {
    fruitSprite.setFillColor(sf::Color::Green);
    generateFruit();
}

void Game::generateFruit() {
    float x = util::random_range(0, 1000);
    float y = util::random_range(0, 1000);
    fruits.push_back(
        Transform(sf::Vector2<float>(x, y), 0)
    );
}

void Game::render(sf::RenderWindow& window){
    for (auto fruit: fruits){
        fruitSprite.setPosition(fruit.position);
    }
}