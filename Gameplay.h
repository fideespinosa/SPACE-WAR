#pragma once
#include "Player.h"
#include <list>"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML/System/Clock.hpp>
#include "Enemy.h"
#include "Bullet.h"
#include <vector>

class Gameplay : public sf::Drawable, sf::Transformable
{

private:
    static Gameplay* _currentInstance;
    std::list<Enemy> _enemys;
    std::list<Bullet> _bullets;
    sf::Clock shootTimer;
    float spawnTimer = 0;
    float spawnTimerMax = 3;
    Gameplay();
    Player _spaceship;
public:
    static Gameplay& getInstance();
    void update();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void shoot(sf::Vector2f position, Bullet::Direction direction);
    
};



