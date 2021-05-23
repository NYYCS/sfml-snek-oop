#ifndef GAME_H
#define GAME_H

#include <vector>

#include "util.h"
class Context;
#include "context.h"
#include "transform.h"

class Game {
    public:
        Game();
        std::vector<Transform> fruits;
        void generateFruit();
        void update(Context&);
        void render(sf::RenderWindow&);

    private:
        sf::CircleShape fruitSprite;

};


#endif