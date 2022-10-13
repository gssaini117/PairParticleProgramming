#ifndef PARTICLE_EFFECT_H
#define PARTICLE_EFFECT_H

#include "Particle.h"

class ParticleEffect
{

private:

	sf::Vector2f origin;

	Particle* particles;

	int count;

public:

	ParticleEffect(const sf::Vector2f& origin, int count);

	~ParticleEffect();

	bool IsAlive() const;

	void Update(const sf::Time& delta);

	void Render(sf::RenderWindow& canvas);

};

#endif
