#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>

#include <string>
#include <map>

#include "entity.h"

#define ENTITY_NOT_FOUND 

class Scene {
    public:

        void update(const Context& ctx) {

            ctx.bindScene(this);

            for (const auto& pair: entities){
                Entity* entity = pair.second;
                entity->update(ctx);
            }
            
        }
        
        void render(sf::RenderWindow& window){

            for (const auto& pair: entities){
                Entity* entity = pair.second;
                entity->render(window);
            }
        }

        void bindEntity(Entity* entity, std::string entityName){
            entities[entityName] = entity;
        }

        Entity* findEntity(const std::string& entityName){
            auto it = entities.find(entityName);
            if(it == entities.end()){
                return ENTITY_NOT_FOUND;
            }
            auto& pair = *it;
            return pair.second;
        }

    private:
        std::map<std::string, Entity*> entities;

};


#endif