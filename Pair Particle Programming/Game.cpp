#include "Game.h"

void Game::Start(int width, int height, const std::string& name)
{
	// We need a randomizer.
	srand(time(NULL));

	// Now back to your regularly scheduled coding.
	sf::RenderWindow window(sf::VideoMode(width, height), name);
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Time delta = clock.restart();
		sf::Event query;

		while (window.pollEvent(query))
		{
			OnInput(query, window);
		}

		OnUpdate(delta, window);
		OnRender(window);
	}
}

void Game::OnInput(const sf::Event& event, sf::RenderWindow& window)
{
	if (event.type == sf::Event::Closed) window.close();

	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		// Extract the mouse position relative to the window.
		sf::Vector2i mouse = sf::Mouse::getPosition(window);

		// We need floats.
		float x = mouse.x;
		float y = mouse.y;

		// Add a new particle effect to the set of all effects.
		effects.push_back(ParticleEffect(sf::Vector2f(x, y), 20));
	}
}

void Game::OnUpdate(const sf::Time& delta, sf::RenderWindow& window)
{
	for (int i = 0; i < effects.size(); i++) {
		effects[i].Update(delta);
		if (!effects[i].IsAlive())
			effects.erase(effects.begin() + i);
	}
}

void Game::OnRender(sf::RenderWindow& canvas)
{
	canvas.clear();
	for (int i = 0; i < effects.size(); i++) {
		effects[i].Render(canvas);
	}
	canvas.display();
}
