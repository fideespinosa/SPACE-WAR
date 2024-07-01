#pragma once
#include <SFML\Graphics.hpp>
#include "Collisionable.h"
#include "BulletEnemy.h"
#include <list>

class Enemy : public Collisionable {
protected:
    sf::Sprite _sprite, _spriteMove;
    sf::Texture _texture, _textureMove;
    float _speed = 0;
    int _life = 0;
    int _type = 0;
    int _stateMove = 0;
    

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
    virtual BulletEnemy shoot();
    sf::Clock shootClock, _clockMove;
    virtual void handleInputEnemy(std::list<BulletEnemy>& bullets);
    virtual ~Enemy();
    virtual bool controlSprite(sf::Sprite& _sprite);
};

