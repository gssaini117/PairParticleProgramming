#ifndef PARTICLE_H
#define PARTICLE_H

#define _USE_MATH_DEFINES

#define VELOCITY_MAX 80
#define VELOCITY_MIN 60

#define SIZE_MAX 10
#define SIZE_MIN 6

#define LIFE_MAX 1.0f
#define LIFE_MIN 0.8f

#include <SFML/Graphics.hpp>

class Particle
{

private:

	sf::CircleShape shape;
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Color color;
	float lifespan;
	float life;
	bool valid;

public:

	Particle();
	//~Particle();
	void Initialize(const sf::Vector2f& origin, const sf::Vector2f& vel);
	sf::Vector2f GetPosition() const;
	bool IsAlive() const;
	void Update(const sf::Time& time);
	void Render(sf::RenderWindow& canvas);
};

#endif
