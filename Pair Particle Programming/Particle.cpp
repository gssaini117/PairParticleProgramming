#include "Particle.h"

Particle::Particle() {
	shape = sf::CircleShape(0);
	position = sf::Vector2f(0, 0);
	velocity = sf::Vector2f(0, 0);
	color = sf::Color::Black;
	lifespan = 0;
	life = 0;
	valid = false;
}

// Destructor
Particle::~Particle() {
	
}

void Particle::Initialize(const sf::Vector2f& origin, const sf::Vector2f& vel) {
	shape = sf::CircleShape(8);
	position = origin;
	srand(time(NULL));
	velocity = vel;
	color = sf::Color(rand() % 255, rand() % 255, rand() % 255);
	lifespan = rand() % 3 + 2;
	life = lifespan;
	valid = true;
}

// Returns the Position of the Particle based on its Velocity
sf::Vector2f Particle::GetPosition() const {
	return position;
}

// Returns whether the Particle has lived out its Lifespan or not
bool Particle::IsAlive() const {
	return life > 0;
}

// Updates Particle based on Time
void Particle::Update(const sf::Time& time) {
	if (!valid) return;
	position += velocity;
	shape.setPosition(position);
	life -= time.asSeconds();
	color.a = life / lifespan * 255;
}

// Renders Particle to the window
void Particle::Render(sf::RenderWindow& canvas) {
	canvas.draw(shape);
}