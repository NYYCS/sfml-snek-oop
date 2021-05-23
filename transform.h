#ifndef SHAKENODE_H
#define SNAKENODE_H
#pragma once
#include <SFML/Graphics.hpp>

class Transform {
    
    public:
        Transform(const sf::Vector2<float> position_, float rotation_) {
            position = position_;
            rotation = rotation_;
        };
        sf::Vector2<float> position;
        float rotation;

};

#endif