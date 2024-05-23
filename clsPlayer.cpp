#include "clsPlayer.h"
#include "Bullet.h"
sf::Sprite clsPlayer::getSprite() const 
{
	return _sprite;
}

clsPlayer::clsPlayer()
{
	_texture.loadFromFile("nave.png");
	_sprite.setTexture(_texture);
	_vel = 10;
}



clsPlayer::clsPlayer(int x, int y)
{
	_texture.loadFromFile("nave.png");
	_sprite.setTexture(_texture);
	_vel = 10;
	_sprite.setPosition(x, y);
}



void clsPlayer::upDate()
{
	//Teclado
	isPress();
	//Controlar los extremos
	controlExtreme();

}
//DIBUJA el SPRITE
void clsPlayer::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	target.draw(_sprite, states);
}
/*
Bullet clsPlayer::shoot(clsPlayer spaceship, Bullet bullet)
{
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shootTimer.getElapsedTime() >= shootCooldown) {
			// Obtener la posición de la nave
			sf::Vector2f playerPosition = spaceship.getPosition();
			// Ajustar la posición de la bala para que esté por encima de la nave
			float bulletSpawnOffset = 130.0f; // Ajusta la posicion de la bala respecto a la nave
			sf::Vector2f bulletPosition(playerPosition.x, playerPosition.y - bulletSpawnOffset);
			Bullet bullet(bulletPosition.x, bulletPosition.y, 4.f);
			// Agregar la bala al vector
			bullets.push_back(bullet);
			// Reiniciar el temporizador
			shootTimer.restart();
			return bullet;
		}
}
*/
void clsPlayer::isPress()
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
}

void clsPlayer::controlExtreme()
{
	//EJE X
	if (_sprite.getPosition().x < 0) {
		_sprite.setPosition(0, _sprite.getPosition().y);
	}
	if (_sprite.getPosition().x + _sprite.getGlobalBounds().width > 1024) {
		_sprite.setPosition(1024 - _sprite.getGlobalBounds().width, _sprite.getPosition().y);
	}
	//EJE Y
	if (_sprite.getPosition().y < 382) {
		_sprite.setPosition(_sprite.getPosition().x, 382);
	}
	if (_sprite.getPosition().y + _sprite.getGlobalBounds().height > 573) {
		_sprite.setPosition(_sprite.getPosition().x, 573 - _sprite.getGlobalBounds().height);
	}
}

sf::FloatRect clsPlayer::getBounds() const
{
	return _sprite.getGlobalBounds();
}

