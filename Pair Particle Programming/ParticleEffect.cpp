#include "ParticleEffect.h"

ParticleEffect::ParticleEffect(const sf::Vector2f& origin, int count)
{
	// Copy members.
	this->origin = origin;
	this->count = count;

	// Allocate memory for the particles.
	this->particles = new Particle[count];

	// Distribute the particles radially.
	for (int i = 0; i < this->count; i++)
	{
		// I could have used a constant, but macros are cooler and global.
		float magnitude = rand() % (VELOCITY_MAX - VELOCITY_MIN) + VELOCITY_MIN;

		// We need this for random range.
		float range = M_PI / this->count;

		// I hate rand so much why did they remove SFML Randomizer
		float offset = (rand() % 100) / 100.0f * range - (range / 2);

		// Assemble velocity.
		float angle = range * i + offset;
		float x = std::cos(angle) * magnitude;
		float y = std::sin(angle) * magnitude;

		// Initialize the particle with the randomly-generated velocity.
		this->particles[i].Initialize(this->origin, sf::Vector2f(x, y));
	}
}

ParticleEffect::~ParticleEffect()
{
	delete[] particles;
}

bool ParticleEffect::IsAlive() const
{
	bool flag = false;

	for (int i = 0; i < count; i++)
	{
		flag = flag || particles[i].IsAlive();
	}

	return flag;
}

void ParticleEffect::Update(const sf::Time& delta)
{
	for (int i = 0; i < count; i++)
	{
		particles[i].Update(delta);
	}
}

void ParticleEffect::Render(sf::RenderWindow& canvas)
{
	for (int i = 0; i < count; i++)
	{
		if (particles[i].IsAlive())
			particles[i].Render(canvas);
	}
}