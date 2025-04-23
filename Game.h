#pragma once
#include "Common.h"
#include "Entity.h"
#include "EntityManager.h"

struct PlayerConfig  {int SR, CR, FR, FG, FB, OR, OG, OB, OT, V; float S; };
struct EnemyConfig   {int SR, CR, OR, OG, OB, OT, VMIN, VMAX, L; float SMIN, SMZX; };
struct BullectConfig {int SR, CR, FR, FG, FB, OR, OG, OB, OT, V, L; float S; };

class Game
{
	sf::RenderWindow	m_window;
	bool				m_paused = false;
	bool				m_running = true;
	EntityManager		m_entities;
	sf::Font			m_font;
	sf::Text			m_text;
	PlayerConfig		m_playerConfig;
	EnemyConfig			m_enemyConfig;
	BulletConfig		m_bulletConfig;
	int					m_score = 0;
	int					m_spawnInterval = 1000;
	int					m_currentFrame = 0;
	sf::Clock			m_clock;
	
	std::shared_ptr<Entity>	m_player;
	
	void init(const std::string & config)
	void setPaused(bool paused);
	
	void sMovement();
	void sLifespan();
	void sUserInput();
	void sRender();
	void sEnemySpawner();
	void sCollision();

	void spawnPlayer();
	void spawnEnemy();
	void spawnSmallEnemies(std::shared_ptr<Entity> entity);
	void spawnBullet(std::shared_ptr<Entity> entity, const Vec2 & mousePos);
	void spawnSpecialWeapon(std::shared_ptr<Entity> entity);

public:

	Game(const std::string & config);
	
	void run();
}
