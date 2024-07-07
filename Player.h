#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Collisionable.h"
#include "Bullet.h"
#include <list>

class Player : public Collisionable{
private:
    sf::Sprite _sprite, _spriteMove, _spriteDead, _spriteShield;
    sf::Texture _texture, _textureMove, _textureDead, _textureShield;
    int _life = 40;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    float _speed;
    int _stateMove, _stateDead, _stateShield;
    sf::Clock _clockMove, _clockDead, shootClock, _clockShield;
    bool _shield;

public:
    bool getShield();
    void setShield(bool state);
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
