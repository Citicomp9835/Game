#includ "Gameh.h"

Game::Game(const std::string & config)
{
	init(config);
}

void Game::init(const std::string & path)
{
	// TODO: read in config file her
	//		 use the premade PlayerConfig, EnemyConfig, BulletConfig variables

	// std::ifstream fin(path);
	// fin >> m_playerConfig.SR >> m_playerConfig.CR .....
			 
	// set up default window parameters
	m_window.create(sf::VideMode(1280, 720), "Assignment 2");
	m_window.setFramerateLimit(60);
	
	spawnPlayer();
}

void Game::run()
{
		// TODO: 	add pause functionality in here
		//			some systems should function while paused (rendering)
		//			some systems shouldn't (movement / input)
		while (m_running)
		{
			m_entities.update();
			sEnemySpawner();
			if (!m_paused)
			{	
				sMovement(();
				sCollision();
			};
			sUserInput();
			sRender();
			m_currentFrame++;
		}
}

void Game::setPaused(bool paused)
{
	// TODO
}

// respawn the player in the middle of the screen

void Game::spawnPlayer()
{
	// TODO: Finish adding all properties of the player with the correct values from the config

	// We create every entity by calling EntityManager.addEntity(tag)
	//This returns a std::shared_ptr<Entity>, so we use 'auto' to save typing
	auto entity = m_entities.addEntity("player");
	
	// Give this entity a Transform so it spams at (200,200) with velocity (1,1) and angle 0
	entity-cTransform = std::make_shared<CTransform>(Vec2(200.0f, 200.0f), Vec2(1.0f, 1.0f), 0.0f);
	
	//The entity's shape will have radius 32, 8 sides, dark grey fill, and red outline of thickness 4
	//Replace hard code parameters with config file value for player.
	// entity-cShape = std::make_shared<CShape>(m_playerConfig.SR,0f, 8, sf::Color(10, 10, 10), sf::Color(255, 0, 0), 4.0f);
	entity-cShape = std::make_shared<CShape>(32,0f, 8, sf::Color(10, 10, 10), sf::Color(255, 0, 0), 4.0f);
	
	// Add an input component to the player
	entity->cInput = std::make_shared<CInput>();
	
	// Since we want this Entity to be our player, set our Game's player variable to be this Entity
	// This goes slightly against the EntityManager paradigm, but we use the player so much it's worth it
	m_player = entity;
	
}

// spawn an enemy at a random position
void Game::spawnEnemy()
{
	
	// TODO: make sure the enemy is spawned properly with the m_enemyConfig variables
	//		 the enemy must be sapwned completely within the bounds of the window
	
	// position x = random number between calculated bounds
	// position y = radom number between calculatged bounds
	//vec initialPos(x,y);
	// m_enemyConfig.VMIN, m_enemyConfig.VMAX <- spawn random number in this range
	
	
	// transform
	// shape
	// collision
	
}

// spawns the smal enemies when a big on (input entity e) explodes
void Game::spawnSmallEnemies(std::shared_prt<Entity> e)
{
	// TODO
	
	// auto entity = m_entities.addEntity("smallenemy")
	// when we create the smaller enemy, we have to read the values of the original enemy
	// - we have to set each small enemy to the same color as the original
	// - we have to spawn a number of small enemies equal to the vertices of the original
	
	// for example, say entity e had 6 points
	// so we are going to spawn 6 small enemies
	
	for (int i = 0; i < e->cShape->circle.getPointCount();i++)
	{
		auto entity = m_entities.addEntity("smallenemy");
		// set the parameters of the small entity
	}
}

// spaws abullet from a given entity to a target location
void Game::spawnBullet(std::shared_prt<Entity> entity, const Vec2 & target)
{
	// TODO
}	
	
	
	
	// when we create the smaller enemy, we have to read the values of the original enemy
	// we have to set each small enemy to the same color as original
	// we have to spawn a number of small enemies equal to the vertices of the original enemy
	
	// for example, say entitye e had 6 points
	// so we going to spawn 6 small enemies
	float angle = 360.0 /e->cShape->circle.getPointCount();
	
	for (int i=0; i< e->cShape->circle.getPointCount(); i++)
	{
		auto entity = m_entities.addEntity("smallenemy");
		//set the parameters of the small entity
	};
}

// spawns a bullet from a given entity to a target location
void Game::spawnBullet(std::shared_ptr<Entity> entity, const Vec2 & target)
{
	//TODO
	auto bullet = m_entities.addEntity(:bullet");
	
}

void Game::spawnSpecialWeapon(std::shared_ptr<Entity> entituy)
{
	// TODO: implement your special weapon
}

void Game::sMovement()
{
	// TODO: implement all entity movement in this function
	//		 you should read the m_player->cInput component to determine if the player is moving
	
	// Sample movement speed update
	m_player->cTransform->pos.x += m_player->cTransform->velocity.x;
	m_player->cTransform->pos.y += m_player->cTransform->velocity.y;
}

void Game::sLifespan()
{
	// TODO: implement all lifespan functionality
	//
	// for all entities
	// 		if it has lifespan and is alive
	//			scale its alpha channel properly
	//		if it has lifespan and its time is up
	//			destroy the entity
	for (auto e : m_entities.getEntities())
	{
		if (e->cLifespan)
		{
			int remaining = e->cLifespan->lifespan - (m_currentFrame - e->cLifespan->frameCreated);
		};
		
		if (remaining <= 0)
		{
			e->destroy();
		};
	};
	
}

void Game::sCollision()
{
	// TODO: implement all proper collisions between entities
	//		 be sure to use the collision radius, NOT the shape radius
	
	// check collisions between player and entities
	for (auto e : m_entities.getEntities("enemy");
	{
		// if collision between e and player, spawnPlayer and destroy enemy
	}
	
	for (auto e : m_entities.getEntities("smallenemy");
	{
		// if collision between e and player, spawnPlayer and destroy enemy
	}	
	
	for (auto b : m_entities.getEntities("bullet");
	{	
		for (auto e : m_entities.getEntities("enemy");
		{
			// if collision between e and b, kill both b and e
			
		}
	}
}

void Game::sEnemySpawner()
{
	// TODO: code which implements enemy spawning should go here
	/*
	if (enemy spawn timer elapsed)
		spawEnemy();
	*/
}

void Game::sRender()
{
	// TODO: change the code below to draw ALL of the entities
	//		 sample drawing of the player Entity that we have created
	m_window.clear();
	
	// set the position of the shape based on the entity's transform->pos
	m_player->cShape->circle.setPosition(m_player->cTransform->pos.x, m_player->cTransform->pos.y);
	
	// set the rotation of the shape based on the entity's transform->angle
	m_player->cTransform->angle += 1.0f;
	m_player->cShape->circle.setRotation(m_player->cTransform->angle);
	
	// draw the entity's sf::CircleShape
	m_window.draw(m_player->cShape->circle);
	
	m_windo.display();
	
}

void Game::sUserInput()
{
	// TODO: handle user input here
	//		 note that you should only be setting the player's input component variables 
	//		 you should not implement the player's movement logic here
	//		 the movement system will read the variables you set in this function

	sf::Event event;
	while (m_window.pollEvent(event))
	{
		// thie event triggers when the window is close
		if (event.type == sf::Event::Closed)
		{
			m_running = false;
		}	
		
		// this event is triggered when a key is pressed
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::W:
				std::cout << "Wl Key pressed\n";
				// TODO: set player's input component "up" to true
				break;
			}
		}

		if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::W:
				std::cout << "Wl Key released\n";
				// TODO: set player's input component "up" to false
				break;
			}
		}
		
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{	
				std::cout << "Left Mouse Button Clicked at(" << "," << event.mouseButton.y << ")\n"'
				// call spawnBullet here
			}
			
			if (event.mouseButton.button == sf::Mouse::Right)
			{	
				std::cout << "Right Mouse Button Clicked at(" << "," << event.mouseButton.y << ")\n"'
				// call spawnSpecialWeapon here
			}
			
		}
		
	}
}


