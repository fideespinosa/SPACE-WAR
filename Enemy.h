#include <SFML\Graphics.hpp>
#include "Collisionable.h"
#include "Bullet.h"

class Enemy : public Collisionable{
private:
    sf::Sprite _sprite;
    sf::Texture _texture;
    float _speed = 0;
    int _life=0;
    int _type =0;

public:
    int getType();
    int getLife();
    void setLife(int life);
    Enemy(float x, float y, int type);
    void update();
    void draw(sf::RenderWindow& window) override;
    sf::FloatRect getBounds() const override;
    Bullet shoot();
};

