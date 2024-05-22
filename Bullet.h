#pragma once
#include <SFML/Graphics.hpp>

class Bullet : public sf::Drawable {
private:
    sf::RectangleShape shape;
    float x; // Posición en el eje x
    float y; // Posición en el eje y
    float speed; // Velocidad de la bala

public:


    Bullet(float startX, float startY, float bulletSpeed);


    // Actualizar posición de la bala
    void update();

    // Obtener posición en el eje x
    float getX() const;

    // Obtener posición en el eje y
    float getY() const;

    // Sobrecarga de la función draw para permitir dibujar la bala en la ventana
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


};
