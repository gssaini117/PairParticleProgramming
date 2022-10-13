#include "Particle.h"

// Constructor
Particle::Particle(sf::Vector2f& origin, sf::Vector2f& vel) {
	shape = new sf::CircleShape(8);
	position = origin;
	srand(time(NULL));
	velocity = vel;
	color = sf::Color(rand() % 255, rand() % 255, rand() % 255);
	lifespan = rand() % 3 + 2;
	life = lifespan;
}

// Destructor
Particle::~Particle() {
	delete shape;
}

// Returns the Position of the Particle based on its Velocity
sf::Vector2f Particle::GetPosition() const {
	return position;
}

// Returns whether the Particle has lived out its Lifespan or not
bool Particle::IsAlive() const {
	if (life < 0)
		return false;
	return true;
}

// Updates Particle based on Time
void Particle::Update(const sf::Time& time) {
	position += velocity;
	shape->setPosition(position);
	life -= time.asMilliseconds();
	color.a = life / lifespan * 255;
}

// Renders Particle to the window
void Particle::Render(sf::RenderWindow& canvas) {
	canvas.draw(*shape);
}