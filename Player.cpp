#include "Player.h"
#include "Bullet.h"
#include "Gameplay.h"


Player::Player()
{
	_texture.loadFromFile("img/nave.png");
	_sprite.setTexture(_texture);
	_sprite.setOrigin({ 0.0f,0.0f });
	_sprite.setScale(0.4, 0.4);
	_vel = 10;
}


void Player::update()
{
	//Teclado
	isPress();
	//Controlar los extremos
	controlExtreme();

}
//DIBUJA el SPRITE
void Player::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	target.draw(_sprite, states);
}
void Player::isPress()


{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		_sprite.move(0, -_vel);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		_sprite.move(-_vel, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		_sprite.move(0, _vel);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		_sprite.move(_vel, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		Gameplay& gm = Gameplay::getInstance();
		gm.shoot(_sprite.getPosition(), Bullet::Direction::Up);
	}
}

void Player::controlExtreme()
{
	sf::Vector2f position = _sprite.getPosition();
	//EJE X
	if (position.x < 0) {
		_sprite.setPosition(0, _sprite.getPosition().y);
	}
	if (position.x + _sprite.getGlobalBounds().width > 1024) {
		_sprite.setPosition(1024 - _sprite.getGlobalBounds().width, _sprite.getPosition().y);
	}
	//EJE Y
	if (position.y < 382) {
		_sprite.setPosition(_sprite.getPosition().x, 382);
	}
	if (position.y + _sprite.getGlobalBounds().height > 573) {
		_sprite.setPosition(_sprite.getPosition().x, 573 - _sprite.getGlobalBounds().height);
	}

}

sf::FloatRect Player::getBounds() const
{
	return _sprite.getGlobalBounds();
}

