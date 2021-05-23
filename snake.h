#ifndef SHAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <math.h>

#include "transform.h"
#include "context.h"


class Snake {
    
    public:

        Snake();

        Transform& head();
        void render(sf::RenderWindow&);
        void update(Context&);

        void putFruit();

        void grow(int length);

        static const auto initialSize = 5;
        static constexpr auto maxSpeed = 5.0f;

    private:
        std::vector<Transform> nodes;
        std::vector<Transform> pastTransforms;

        sf::CircleShape sprite;
        sf::CircleShape fruit;
        sf::RectangleShape background;

        sf::Vector2<float> fruitPosition;

        sf::Texture texture;

        void move(Context&);
        void checkFruitCollision(Context&);

        float speed(float distance) {
            if (distance > 20.0f) {
                auto delta = distance - 20.0f;
                return std::min(delta, maxSpeed);
            } else {
                return 0.0f;
            }
        }

};

#endif