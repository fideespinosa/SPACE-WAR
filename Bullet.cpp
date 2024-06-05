#include "Bullet.h"
#include "Player.h"
#include <SFML\Graphics.hpp>

Bullet::Bullet(sf::Vector2f position, Direction direction)
{
    _texture.loadFromFile("img/bala.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin({ -46.0f,0.0f});
    _sprite.setScale(0.2f, 0.02f);
    _direction = direction;
    setPosition(position);
    _velocity={ 2.0f, 2.0f };
}


void Bullet::update()
{
    

    switch (_direction) 
    {
    case Bullet::Direction::Left:
        move(-_velocity.x, 0);
        break;
    case Bullet::Direction::Right:
        move(_velocity.x, 0);
        break;
    case Bullet::Direction::Up:
        move(0, -_velocity.y);
        break;
    case Bullet::Direction::Down:
        move(0 , _velocity.y);
        break;
    default:
        break;
    }

}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(_sprite, states);
}

sf::FloatRect Bullet::getGlobalBounds() const
{
    return _sprite.getGlobalBounds();
}





/*
Bullet::Bullet( int x, int y)
{
    speed = 0.4f;
    _texture.loadFromFile("img/bala.png");
    _sprite.setTexture(_texture);
    //_vel = 10;
    _sprite.setPosition(x,y);
}


Bullet::Bullet(float startX, float startY, float bulletSpeed){}

        //Mover Bala
        //_sprite.move(0,-1);

float Bullet::getX() const
{
    return 0.0f;
}

float Bullet::getY() const
{
    return 0.0f;
}

/*
void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const {

    target.draw(_sprite, states);
}
*/