#include "EntityManager.h"

EntityManager::EntityManager()
{}
	
void EntityManager::update()
{
	// TODO:	add entities from m_entitiesToAdd the proper location(s)
	// TODO:	clean up dead entities from all entities as well as the map vectors
	for (auto e: vec)
	// remove dead entities from m_entitiesToAdd
	// remove dead entities from their vectors in map
	
}

// helper function to remove dead entities from a given vcetor
void EntityManager::removeDeadEntities(EntityVec & vec)
{
	// TODO
	for (auto e: vec)
	{
		// this is the sign of an entity we want to remove
		if (!e->isActive())
		{
			// remove e from vec
		}
	}
}

std::shared_ptr<Entity> Entitymanager::addEntity(const std::string & tag)
{
	// TODO: implement this function so that entities are added to the
	//		 m_entitiesToAdd vector here, and then added to the proper
	//		 locations in the update() function
	
	// creat the entity shared pointer
	auto entity = std::shared_ptr<Entity>(new Entity(m_totalEntities++,tag));
	
	//TODO: this adds directly to the main vector, change this!
	m_entities.push_back(entity);
	
	return entity;
}