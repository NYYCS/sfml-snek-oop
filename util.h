#ifndef UTIL_H
#define UTIL_H

#include <SFML/Graphics.hpp>
#include <random>
#include <chrono>
#include <math.h>


namespace util {

    static std::default_random_engine rng;
    static std::uniform_real_distribution<float> dist(0.0f, 1.0f);

    inline float random_range(float a, float b) {
        rng.seed(std::chrono::system_clock::now().time_since_epoch().count());
        return a + ((b - a) * dist(rng));
    }

    template <typename T>
    inline float magnitude(sf::Vector2<T> v){
        return std::sqrt( v.x * v.x + v.y * v.y );
    }
    
    template <typename T>
    inline sf::Vector2<float> normalize(sf::Vector2<T> v){
        return v / magnitude<T>(v);
    }

    inline bool contain(sf::Vector2<float> a, sf::Vector2<float> b, float hw){
        return (a.x > b.x - hw && a.x < b.x + hw ) && (a.y > b.y - hw && a.y < b.y + hw);
    }

};

#endif