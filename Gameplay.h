#include <SFML/Graphics.hpp>
#include <list>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

class Gameplay{
private:
    static Gameplay* _currentInstance;
    Player _player;
    std::list<Enemy> _enemies;
    std::list<Bullet> _playerBullets;
    std::list<Bullet> _enemyBullets;
    sf::Clock _enemySpawnClock;
    int _score = 0;
    void handleCollisions();
    void spawnEnemies();
    sf::Text showScore(int _score);


public:
    Gameplay& getInstance();
    Gameplay();
    void run(sf::RenderWindow& window);
    sf::Font _font;
    void drawLife(sf::RenderWindow& window, int life);
};
