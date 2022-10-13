#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>

class Particle
{

private:

	sf::Shape* shape;
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Color color;
	float lifespan;
	float life;

public:

	Particle(sf::Vector2f& origin, sf::Vector2f& vel);
	~Particle();
	sf::Vector2f GetPosition() const;
	bool IsAlive() const;
	void Update(const sf::Time& time);
	void Render(sf::RenderWindow& canvas);
};

#endif
