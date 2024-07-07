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
#include "Consumable.h"
#include "Shield.h"
#include "Score.h"
#include "MainMenu.h"
#include "BackgroundAnimation.h"

class Gameplay{
private:
    //Variables
    static Gameplay* _currentInstance;
    int _score = 0;
    bool _spawnCheck;
    float _spawnTime = 4.0f;
    int _minute = 0;
    Score scoreCls;
    ArchivoRanking file;
   // score score;
//Game Clases
    BackgroundAnimation _background;
    Player _player;
    std::list < std::unique_ptr< Enemy >> _enemies;
    std::list<Bullet> _playerBullets;
    std::list<Consumable> _consumable;
    std::list<BulletEnemy> _enemyBullets;
    std::list<Explosion> _enemyExplosion;
    sf::Clock _enemySpawnClock, _gameClock, _clockAnimationPlayer, _shieldClock;
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
    void run(sf::RenderWindow& window, const char* name);
    void drawLife(sf::RenderWindow& window, int life);
    bool gameOver(sf::RenderWindow& window);
    void cleanGame();
    bool youWin(sf::RenderWindow& window, int _score);
protected:
    void handleCollisions();
    void spawnEnemies(float _spawnTime);
    void checkPlayerCollisions();

};
