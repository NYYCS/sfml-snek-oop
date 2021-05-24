#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

#include "context.h"

class Entity {
    public:
        virtual void update(const Context&) = 0;
        virtual void render(sf::RenderWindow&) = 0;
};


#endif