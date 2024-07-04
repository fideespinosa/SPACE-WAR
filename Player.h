#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Collisionable.h"
#include "Bullet.h"
#include <list>

class Player : public Collisionable{
private:
    sf::Sprite _sprite, _spriteMove, _spriteDead;
    sf::Texture _texture, _textureMove, _textureDead;
    int _life = 50;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    float _speed;
    int _stateMove, _stateDead;
    sf::Clock _clockMove, _clockDead, shootClock;

public:

    int getLife();
    void setLife(int life);
    Player();
    void handleInput(std::list<Bullet>& bullets);
    void update();
    void draw(sf::RenderWindow& window) override;
    sf::FloatRect getBounds() const override;
    sf::Vector2f getPosition() const;
    Bullet shoot();
};
