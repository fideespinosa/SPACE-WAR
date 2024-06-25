#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Collisionable.h"
#include "Bullet.h"
#include <list>

class Player : public Collisionable{
private:
    sf::Sprite _sprite;
    sf::Texture _texture;
    int life = 5;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    float _speed;

public:
    Player();
    void handleInput(std::list<Bullet>& bullets);
    void update();
    void draw(sf::RenderWindow& window) override;
    sf::FloatRect getBounds() const override;
    sf::Vector2f getPosition() const;
    Bullet shoot();
};
