#ifndef GAME_H
#define GAME_H

#include "ParticleEffect.h"

class Game
{

private:

	// Manages the current set of Particle Effects
	std::vector<ParticleEffect> effects;

public:

	void Start(int width, int height, const std::string& name);

	void OnInput(const sf::Event& event, sf::RenderWindow& window);

	void OnUpdate(const sf::Time& delta, sf::RenderWindow& window);

	void OnRender(sf::RenderWindow& canvas);

};

#endif