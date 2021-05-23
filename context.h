#ifndef CONTEXT_H
#define CONTEXT_H

#include <SFML/Graphics.hpp>
#include "game.h"


class Context {
    public:
        Context(sf::RenderWindow&, sf::Time);
        sf::RenderWindow& window;
        sf::Time deltaTime;

};

#endif