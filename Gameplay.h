#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "windows.h"
#include "clsPlayer.h"
#include "Enemy.h"
#include "Bullet.h"
#include <vector>

class Gameplay: public sf::Drawable
{
private:
    static Gameplay* _currentInstance;
    clsPlayer Spaceship;
    std::vector<Enemy> _enemys;
    std::vector<Bullet> _bullets;
    Gameplay();
public:
    static Gameplay& getInstance();
    void update();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void shoot(sf::Vector2f position, Bullet::Direction direction);
};

