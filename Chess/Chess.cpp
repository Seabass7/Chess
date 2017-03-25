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

sf::View calcBoardView(const sf::Vector2u &windowsize, const sf::Vector2u &boardsize, const sf::Vector2u &designedsize)
{
	sf::FloatRect viewport(0.0875f, 0.109375f, 0.625f, 0.78125f);

	float screenwidth = windowsize.x / static_cast<float>(designedsize.x);
	float screenheight = windowsize.y / static_cast<float>(designedsize.y);

	if (screenwidth > screenheight)
	{
		viewport.width *= screenheight / screenwidth;
		viewport.left = (0.7125f - viewport.width) / 1.425f;
	}
	else if (screenwidth < screenheight)
	{
		viewport.height *= screenwidth / screenheight;
		viewport.top = (1.f - viewport.height) / 2.f;
	}

	sf::View view(sf::FloatRect(0, 0, boardsize.x, boardsize.y));
	view.setViewport(viewport);

	return view;
}

int main()
{
	Board board;

	const sf::Vector2u boardSize(800, 800);
	const sf::Vector2u backSize(1280, 1024);

	sf::RenderWindow window(sf::VideoMode(800, 600), "Chess");
	sf::View backView = calcView(window.getSize(), backSize);
	sf::View boardView = calcBoardView(window.getSize(), boardSize, backSize);
	//boardView.setViewport(sf::FloatRect(0.0875f, 0.109375f, 0.625f, 0.78125f)); //add to calcview?
	//backView.setViewport(sf::FloatRect(0, 0, 1, 1));
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
			if (event.type == sf::Event::Resized) {
				backView = calcView(sf::Vector2u(event.size.width, event.size.height), backSize);
				boardView = calcBoardView(sf::Vector2u(event.size.width, event.size.height), boardSize, backSize);
			}
		}

		window.clear();

		//START BACK
		window.setView(backView);
		sf::RectangleShape sidebar(sf::Vector2f(256, 1280));
		sidebar.setPosition(1024, 0);
		sidebar.setFillColor(sf::Color::White);
		window.draw(sidebar);
		//END BACK

		//START BOARD
		window.setView(boardView);
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

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2f localPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			if (localPosition.x <= TILESIZE * 8 || localPosition.y <= TILESIZE * 8) {
				if (board.validPiece(selected)) {
					if (!board.move(selected, Position(localPosition.x / TILESIZE, localPosition.y / TILESIZE))) {
						selected = Position(localPosition.x / TILESIZE, localPosition.y / TILESIZE);
					}
					else {
						if (board.gameOver()) {
							std::cout << "Check mate!" << std::endl;
						}
					}
				}
				else {
					selected = Position(localPosition.x / TILESIZE, localPosition.y / TILESIZE);
				}
			}
		}

		board.draw(window, selected, boardView, backView);
		//END BOARD

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