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
#include "Explosion.h"
#include "BulletEnemy.h"
#include "Life.h"
#include "score.h"
#include "MainMenu.h"

class Gameplay{
private:
    //Variables
    static Gameplay* _currentInstance;
    int _score = 0;
    bool _spawnCheck;
    float _spawnTime = 4.0f;
    int _minute = 0;
    score score;
//Game Clases
    Player _player;
    std::list < std::unique_ptr< Enemy >> _enemies;
    std::list<Bullet> _playerBullets;
    std::list<Life> _life;
    std::list<BulletEnemy> _enemyBullets;
    std::list<Explosion> _enemyExplosion;
    sf::Clock _enemySpawnClock, _gameClock, _clockAnimationPlayer;
    MainMenu _menu;
//Resources
    sf::Music music;
    sf::SoundBuffer buffer, buffer2, buffer3, buffer4, buffer5, buffer6;
    sf::Sound sound, gameOverSound, heartEffect, BulletImpact, enemyDie;
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
    void run(sf::RenderWindow& window, std::string name);
    void drawLife(sf::RenderWindow& window, int life);
    bool gameOver(sf::RenderWindow& window);
    void cleanGame();

protected:
    void handleCollisions();
    void spawnEnemies(float _spawnTime);
    void checkPlayerCollisions();

};
