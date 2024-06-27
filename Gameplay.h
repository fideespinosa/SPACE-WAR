#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include <list>
#include <memory>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Enemy4.h"

class Gameplay{
private:
    static Gameplay* _currentInstance;
    Player _player;
    std::list < std::unique_ptr< Enemy >> _enemies;
    std::list<Bullet> _playerBullets;
    std::list<Bullet> _enemyBullets;
    sf::Clock _enemySpawnClock;
    int _score = 0;
    void handleCollisions();
    void spawnEnemies();
    sf::Text showScore(int _score);
    sf::Music music;
    sf::SoundBuffer buffer;
    void checkPlayerCollisions();

public:
   // bool checkSuperpotition(Enemy& enemy, std::list<Enemy>& _enemies);
    Gameplay& getInstance();
    Gameplay();
    void run(sf::RenderWindow& window);
    sf::Font _font;
    void drawLife(sf::RenderWindow& window, int life);
};
