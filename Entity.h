#pragma once
#include <memory>
#include <SFML/Graphics.hpp>


class Entity
{
	bool		m_active	= true;
	size_t		m_id		= 0;
	std::string	m_tag		= "default";

public:

	//component pointers
	std::shared_ptr<CTransform>	cTransform;
	std::shared_ptr<CShape>		cShape;
	std::shared_ptr<CCollision>	cCollision;
	std::shared_ptr<CInput>		cInput;
	std::shared_ptr<CScore>		cScore;
	std::shared_ptr<CLifespan>	cLifespan;
	
	// constructor and destructor
	Entity(const size_t & id, const std::string & tag);
	
	// private member access functions
	bool 	isActive() 			const;
	const 	std::string & tag() const;
	const	size_t id() 		const;
	void 	destroy();
};

