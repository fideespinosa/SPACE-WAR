#include <SFML\Graphics.hpp>
#include "Collisionable.h"
#include "Bullet.h"

class Enemy : public Collisionable {
private:
    sf::Sprite _sprite;
    sf::Texture _texture;
    float _speed;
    int _life=5;

public:
    int getLife();
    void setLife(int life);
    Enemy(float x, float y);
    void update();
    void draw(sf::RenderWindow& window) override;
    sf::FloatRect getBounds() const override;
    Bullet shoot();
};

