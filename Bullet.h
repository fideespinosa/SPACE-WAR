#pragma once
#include <SFML/Graphics.hpp>

class Bullet : public sf::Drawable {
private:
    sf::RectangleShape shape;
    int x; // Posición en el eje x
    int y; // Posición en el eje y
    float speed; // Velocidad de la bala
    sf::Sprite _sprite;
    sf::Texture _texture;

public:

    Bullet(int x, int y);
    //Bullet(sf::FloatRect startX, sf::FloatRect startY, float bulletSpeed);


    void upDate(); //Actualizar

    // Obtener posición en el eje x
    float getX() const;

    // Obtener posición en el eje y
    float getY() const;

   
    // Sobrecarga de la función draw para permitir dibujar la bala en la ventana
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


};
