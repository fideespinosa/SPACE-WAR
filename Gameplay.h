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
    //Variables
    static Gameplay* _currentInstance;
    int _score = 0;
//Game Clases
    Player _player;
    std::list < std::unique_ptr< Enemy >> _enemies;
    std::list<Bullet> _playerBullets;
    std::list<Bullet> _enemyBullets;
    sf::Clock _enemySpawnClock;
//Windows

//Mouse Posicion

//Resources
    sf::Music music;
    sf::SoundBuffer buffer, buffer2, buffer3;
    sf::Sound sound, gameOverSound;
//Text
    sf::Font _font;
    sf::Text showScore(int _score);
    sf::Text pause, life, Menu;
    sf::Sprite img, img2;
    sf::Texture texture, heart;


public:
   // bool checkSuperpotition(Enemy& enemy, std::list<Enemy>& _enemies);
    Gameplay& getInstance();
    Gameplay();

    void run(sf::RenderWindow& window);
    void drawLife(sf::RenderWindow& window, int life);
    bool gameOver(sf::RenderWindow& window);
protected:
    void handleCollisions();
    void spawnEnemies();
    void checkPlayerCollisions();
};
