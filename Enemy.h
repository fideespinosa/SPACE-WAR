#pragma once
#include <SFML\Graphics.hpp>
#include "Collisionable.h"
#include "Bullet.h"
#include <list>

class Enemy : public Collisionable {
protected:
    sf::Sprite _sprite;
    sf::Texture _texture;
    float _speed = 0;
    int _life = 0;
    int _type = 0;
    

public:
    sf::Vector2f getPosition() const;
    int getType();
    virtual int getLife();
    void setLife(int life);
    Enemy() {};
    Enemy(float x, float y);
    virtual void update();
    virtual void draw(sf::RenderWindow& window) override;
    sf::FloatRect getBounds() const override;
    virtual Bullet shoot();
    sf::Clock shootClock;
    virtual void handleInputEnemy(std::list<Bullet>& bullets);
    virtual ~Enemy();
    virtual bool controlSprite(sf::Sprite& _sprite);
};

