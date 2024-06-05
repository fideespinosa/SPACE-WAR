#pragma once
#include "Collisionable.h"
#include <SFML/Graphics.hpp>


class Bullet : public sf::Drawable ,public sf::Transformable, public Collisionable {

public:
    enum class Direction {
        Left = 0,
        Right = 1,
        Up = 2,
        Down = 3
    };
public:
    Bullet(sf::Vector2f position, Direction direction);
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getGlobalBounds() const override;
    
private:

    sf::Sprite _sprite;
    sf::Texture _texture;
    Direction _direction;
    sf::Vector2f _velocity;

};


/*

private:
    sf::RectangleShape shape;
    int x; // Posición en el eje x
    int y; // Posición en el eje y
    float speed; // Velocidad de la bala
    sf::Sprite _sprite;
    sf::Texture _texture;

public:

    Bullet(int x, int y);
    Bullet(float startX, float startY, float bulletSpeed);


    Bullet upDate(clsPlayer spaceship); //Actualizar

    // Obtener posición en el eje x
    float getX() const;

    // Obtener posición en el eje y
    float getY() const;


    // Sobrecarga de la función draw para permitir dibujar la bala en la ventana
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

*/