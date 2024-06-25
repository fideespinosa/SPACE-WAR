#pragma once
#include <SFML\Graphics.hpp>
#include "Collisionable.h"
#include "Bullet.h"

class Enemy : public Collisionable {
protected:
    sf::Sprite _sprite;
    sf::Texture _texture;
    float _speed = 0;
    int _life = 0;
    int _type = 0;

public:
    int getType();
    virtual int getLife();
    void setLife(int life);
    Enemy() {};
    Enemy(float x, float y);
    virtual void update();
    virtual void draw(sf::RenderWindow& window) override;
    sf::FloatRect getBounds() const override;
    Bullet shoot();
    virtual ~Enemy() = default;
};

