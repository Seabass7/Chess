#include "Headers.h"

sf::View calcView(const sf::Vector2u &windowsize, const sf::Vector2u &designedsize)
{
	sf::FloatRect viewport(0.f, 0.f, 1.f, 1.f);

	float screenwidth = windowsize.x / static_cast<float>(designedsize.x);
	float screenheight = windowsize.y / static_cast<float>(designedsize.y);

	if (screenwidth > screenheight)
	{
		viewport.width = screenheight / screenwidth;
		viewport.left = (1.f - viewport.width) / 2.f;
	}
	else if (screenwidth < screenheight)
	{
		viewport.height = screenwidth / screenheight;
		viewport.top = (1.f - viewport.height) / 2.f;
	}

	sf::View view(sf::FloatRect(0, 0, designedsize.x, designedsize.y));
	view.setViewport(viewport);

	return view;
}

int main()
{
	Board board;

	const sf::Vector2u designedsize(800, 600);

	sf::RenderWindow window(sf::VideoMode(800, 600), "Chess");
	window.setView(calcView(window.getSize(), designedsize));
	//window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(10);

	sf::Clock clock;
	int lastTime = 0;
	unsigned int fps = 0;

	Position selected = Position(9, 9);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::Resized)
				window.setView(calcView(sf::Vector2u(event.size.width, event.size.height), designedsize));
		}

		window.clear();
		sf::RectangleShape tile(sf::Vector2f(TILESIZE, TILESIZE));
		for (int y = 0; y < 8; ++y)
		{
			for (int x = 0; x < 8; ++x)
			{
				tile.setPosition(x * TILESIZE, y * TILESIZE);
				tile.setFillColor((x + y) & 1 ? sf::Color::Blue : sf::Color::Green);
				window.draw(tile);
			}
		}

		//sf::RectangleShape tablesideLeft(sf::Vector2f(25, 600));
		//tablesideLeft.setPosition(0, 25);
		//tablesideLeft.setFillColor(sf::Color::Yellow);
		//window.draw(tablesideLeft);

		//sf::RectangleShape tablesideRight(sf::Vector2f(25, 600));
		//tablesideRight.setPosition(625, 25);
		//tablesideRight.setFillColor(sf::Color::Yellow);
		//window.draw(tablesideRight);

		//sf::RectangleShape tablesideTop(sf::Vector2f(600, 25));
		//tablesideTop.setPosition(25, 0);
		//tablesideTop.setFillColor(sf::Color::Yellow);
		//window.draw(tablesideTop);

		//sf::RectangleShape tablesideBottom(sf::Vector2f(600, 25));
		//tablesideBottom.setPosition(25, 625);
		//tablesideBottom.setFillColor(sf::Color::Yellow);
		//window.draw(tablesideBottom);

		sf::RectangleShape sidebar(sf::Vector2f(150, 650));
		sidebar.setPosition(650, 0);
		sidebar.setFillColor(sf::Color::Magenta);
		window.draw(sidebar);

		sf::RectangleShape history(sf::Vector2f(130, 400));
		history.setPosition(660, 10);
		history.setFillColor(sf::Color::Red);
		window.draw(history);

		sf::RectangleShape timerLabel(sf::Vector2f(60, 50));
		timerLabel.setPosition(660, 540);
		timerLabel.setFillColor(sf::Color::Red);
		window.draw(timerLabel);

		sf::RectangleShape exitButton(sf::Vector2f(60, 50));
		exitButton.setPosition(730, 540);
		exitButton.setFillColor(sf::Color::Red);
		window.draw(exitButton);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2f localPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			if (localPosition.x <= TILESIZE * 8 || localPosition.y <= TILESIZE * 8) {
				if (board.validPiece(selected)) {
					if (!board.move(selected, Position(localPosition.x / TILESIZE, localPosition.y / TILESIZE)))
						selected = Position(localPosition.x / TILESIZE, localPosition.y / TILESIZE);
				}
				else {
					selected = Position(localPosition.x / TILESIZE, localPosition.y / TILESIZE);
				}
			}
		}

		board.draw(window, selected);

		window.display();

		if (clock.getElapsedTime().asMilliseconds() > lastTime + 999) {
			std::cout << fps << std::endl;
			fps = 0;
			lastTime = clock.getElapsedTime().asMilliseconds();
		} else {
			fps++;
		}

	}
	return 0;
}