#include <SFML/Graphics.hpp>

#include "snake.h"
#include "util.h"

sf::Vector2<float> generatePosition(){
    float x = util::random_range(0, 1000);
    float y = util::random_range(0, 1000);
    return {x, y};
}

void Snake::putFruit() {
    fruitPosition = generatePosition();
    fruit.setPosition(fruitPosition);
}

Snake::Snake() : background({1000, 1000}), sprite(10), fruit(10) {

    texture.loadFromFile("polka.jpg");
    background.setTexture(&texture);

    sprite.setRadius(10);
    sprite.setOrigin(10, 10);
    sprite.setFillColor(sf::Color::Red);

    fruit.setRadius(10);
    fruit.setOrigin(10, 10);
    fruit.setFillColor(sf::Color::Green);

    for(int i = 0; i < initialSize; ++i) {
        nodes.push_back(
            Transform(sf::Vector2<float>(0.0, 20.0 * i), 0)
        );
    }

    putFruit();
}


Transform& Snake::head() {
    return nodes.front();
}

void Snake::move(Context& ctx) {
    auto& snakehead = head();
    auto direction = sf::Vector2<float>(sf::Mouse::getPosition(ctx.window)) -snakehead.position;
    auto velocity = util::normalize(direction) * speed(util::magnitude(direction));
    snakehead.position += velocity;

    for(auto it = nodes.begin() + 1; it != nodes.end(); ++it) {
        auto& curr = *it;
        auto& next = *(it - 1);
        auto direction = next.position - curr.position;
        auto velocity = util::normalize(direction) * speed(util::magnitude(direction));
        curr.position += velocity;
    }
}

void Snake::grow(int length = 1) {
    auto& snaketail = nodes.back();
    nodes.push_back(
        Transform(snaketail.position + sf::Vector2<float>(0.0, 20.0f), 0)
    );
}



void Snake::update(Context& ctx) {
    if (util::contain(head().position, fruitPosition, 25.0f)) {
        putFruit();
        nodes.push_back(
            Transform(nodes.back().position + sf::Vector2<float>(0, 20.0f), 0)
        );
    }
    move(ctx);
}

void Snake::render(sf::RenderWindow& window) {
    window.draw(background);
    window.draw(fruit);
    for(auto node: nodes) {
        sprite.setPosition(node.position);
        window.draw(sprite);
    }
}   



