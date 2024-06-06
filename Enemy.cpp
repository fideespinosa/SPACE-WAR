#include "Enemy.h"
#include <iostream>


Enemy::Enemy(sf::Vector2f position, Direction direction)
{
    _texture.loadFromFile("img/enemy.png");
    _sprite.setTexture(_texture);
    _sprite.setScale(1, 1);
    _direction = direction;
    setPosition(position);
    _states.texture = &_texture;
}

Enemy::Enemy()
{
    _texture.loadFromFile("img/enemy.png");
    _sprite.setTexture(_texture);
    _sprite.setScale(1, 1);
}

void Enemy::update()
{
    _velocity.x = 0.2f;
    _velocity.y = 0.2f;
    switch (_direction)
    {
    case Enemy::Direction::Left:
        move(-_velocity.x, 0);
        break;
    case Enemy::Direction::Right:
        move(_velocity.x, 0);
        break;
    case Enemy::Direction::Up:
        move(0, -_velocity.y);
        break;
    case Enemy::Direction::Down:
        move(0, _velocity.y);
        break;
    default:
        break;
    }
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
	target.draw(_sprite, states);
}

void Enemy::respawn()
{
	//_sprite.setPosition(std::rand() % 1023, std::rand() % 287);
    _sprite.setPosition(200, 200);
    std::cout << "Nuevo enemigo" << std::endl;
}

sf::FloatRect Enemy::getGlobalBounds() const
{
	return _sprite.getGlobalBounds();
}



