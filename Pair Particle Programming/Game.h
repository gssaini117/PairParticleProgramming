#ifndef GAME_H
#define GAME_H

#include "ParticleEffect.h"

class Game
{

public:

	void Start(int width, int height, const std::string& name);

	void OnInput(sf::Event& event);

	void OnUpdate(sf::Time& time);

	void OnRender(sf::RenderWindow& canvas);

};

#endif
