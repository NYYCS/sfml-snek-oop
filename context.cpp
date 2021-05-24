#include "context.h"
#include "game.h"
#include "scene.h"

Context::Context(sf::RenderWindow& window_, sf::Time deltaTime_)
 : window(window_)
 , deltaTime(deltaTime_)
{
}
