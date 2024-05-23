#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "clsPlayer.h"
class Bullet : public sf::Drawable {
private:
    sf::RectangleShape shape;
    int x; // Posici�n en el eje x
    int y; // Posici�n en el eje y
    float speed; // Velocidad de la bala
    sf::Sprite _sprite;
    sf::Texture _texture;
  
public:

    Bullet(int x, int y);
    Bullet(float startX, float startY, float bulletSpeed);


    Bullet upDate(clsPlayer spaceship); //Actualizar

    // Obtener posici�n en el eje x
    float getX() const;

    // Obtener posici�n en el eje y
    float getY() const;

   
    // Sobrecarga de la funci�n draw para permitir dibujar la bala en la ventana
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


};
