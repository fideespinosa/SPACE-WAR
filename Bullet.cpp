#include "Bullet.h"

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Dibujar la bala
    sf::RectangleShape bulletShape(sf::Vector2f(3, 8)); // Tamaño de la bala
    bulletShape.setFillColor(sf::Color::White); // Color Blanco
    bulletShape.setPosition(x, y); // Posición de la bala
    target.draw(bulletShape, states); // Dibujar la forma en el render target
}

