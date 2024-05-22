#pragma once
#include <SFML/Graphics.hpp>

class Bullet : public sf::Drawable {
private:
    sf::RectangleShape shape;
    float x; // Posici�n en el eje x
    float y; // Posici�n en el eje y
    float speed; // Velocidad de la bala

public:


    Bullet(float startX, float startY, float bulletSpeed);


    // Actualizar posici�n de la bala
    void update();

    // Obtener posici�n en el eje x
    float getX() const;

    // Obtener posici�n en el eje y
    float getY() const;

    // Sobrecarga de la funci�n draw para permitir dibujar la bala en la ventana
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


};
