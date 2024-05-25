#pragma once
#include "Player.h"
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
    std::vector<Enemy> _enemys;
    std::vector<Bullet> _bullets;
    sf::Clock shootTimer;

    Gameplay();
    Player _spaceship;
public:
    static Gameplay& getInstance();
    void update();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void shoot(sf::Vector2f position, Bullet::Direction direction);
    
};



