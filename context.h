#ifndef CONTEXT_H
#define CONTEXT_H

#include <SFML/Graphics.hpp>


#include "game.h"
#include "scene.h"


class Context {
    public:
        Context(sf::RenderWindow&, sf::Time);
        sf::RenderWindow& window;
        sf::Time deltaTime;
        Scene* scene;
        void bindScene(const Scene* scene_) const {
            scene = scene_;
        }
};

#endif