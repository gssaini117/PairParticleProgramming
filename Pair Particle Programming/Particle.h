#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>

class Particle
{

private:

	sf::Shape* shape;

	sf::Vector2f* velocity;

	float lifespan;

public:

	Particle(int x, int y);

	~Particle();

	sf::Vector2f GetPosition() const;

	bool IsAlive() const;

	void Update(sf::Time& time);

	void Render(sf::RenderWindow& canvas);

};

#endif
