#ifndef PARTICLE_EFFECT_H
#define PARTICLE_EFFECT_H

#include "Particle.h"

class ParticleEffect
{

private:

	sf::Vector2u origin;

	Particle* particles;

	int count;

public:

	ParticleEffect(sf::Vector2u& origin, int count);

	~ParticleEffect();

};

#endif
