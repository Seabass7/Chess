#include "Headers.h"

sf::View calcView(const sf::Vector2u &windowsize, const sf::Vector2u &designedsize, const sf::Vector2u &maxsize, const sf::FloatRect &designedview)
{
	sf::FloatRect viewport = designedview;

	float screenwidth = windowsize.x / static_cast<float>(maxsize.x);
	float screenheight = windowsize.y / static_cast<float>(maxsize.y);

	if (screenwidth > screenheight)
	{
		viewport.width = (screenheight / screenwidth) * designedview.width;
		viewport.left = ((designedview.width - viewport.width) / (designedview.width * 2)) + ((designedview.left / designedview.width) * viewport.width);
	}
	else if (screenwidth < screenheight)
	{
		viewport.height = (screenwidth / screenheight) * designedview.height;
		//viewport.top = ((designedview.height - viewport.height) / (designedview.height * 2)) + ((designedview.top / designedview.height) * viewport.height);
		viewport.top = (1.f - viewport.height) / 2.f;
	}

	sf::View view(sf::FloatRect(0, 0, designedsize.x, designedsize.y));
	view.setViewport(viewport);

	return view;
}

int main()
{
	Board* board = new Board;

	static sf::Vector2u backSize(1280, 1024);
	static sf::Vector2u boardSize(800, 800);
	static sf::FloatRect defaultBackView(0.f, 0.f, 1.f, 1.f);
	static sf::FloatRect defaultBoardView(0.0875f, 0.109375f, 0.625f, 0.78125f);

	sf::RenderWindow window(sf::VideoMode(800, 640), "Chess");
	sf::View backView = calcView(window.getSize(), backSize, backSize, defaultBackView);
	sf::View boardView = calcView(window.getSize(), boardSize, backSize, defaultBoardView);
	//window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(30);

	sf::Font font;
	if (!font.loadFromFile("Textures/arialbd.ttf"))
	{
		std::cout << "Error loading font" << std::endl;
	}

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
				backView = calcView(sf::Vector2u(event.size.width, event.size.height), backSize, backSize, defaultBackView);
				boardView = calcView(sf::Vector2u(event.size.width, event.size.height), boardSize, backSize, defaultBoardView);
			}
		}

		window.clear();

		//START BACK
		window.setView(backView);
		board->drawBackground(window);

		sf::RectangleShape sidebar(sf::Vector2f(256, 1024));
		sidebar.setPosition(1024, 0);
		sidebar.setFillColor(sf::Color::Color(178, 178, 178));
		window.draw(sidebar);

		sf::RectangleShape restartButton(sf::Vector2f(246, 70));
		restartButton.setPosition(1029, 874);
		restartButton.setFillColor(sf::Color::Color(170, 114, 67));
		window.draw(restartButton);

		sf::Text restartButtonText;
		restartButtonText.setFont(font);
		restartButtonText.setString("Restart");
		restartButtonText.setCharacterSize(36);
		restartButtonText.setStyle(sf::Text::Bold);
		restartButtonText.setPosition(1082, 891);
		window.draw(restartButtonText);

		sf::RectangleShape quitButton(sf::Vector2f(246, 70));
		quitButton.setPosition(1029, 949);
		quitButton.setFillColor(sf::Color::Color(170, 114, 67));
		window.draw(quitButton);

		sf::Text quitButtonText;
		quitButtonText.setFont(font);
		quitButtonText.setString("Quit");
		quitButtonText.setCharacterSize(36);
		quitButtonText.setStyle(sf::Text::Bold);
		quitButtonText.setPosition(1112, 966);
		window.draw(quitButtonText);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2f localPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			if ((localPosition.x >= 1029 && localPosition.x <= 1275) && (localPosition.y >= 874 && localPosition.y <= 944)) {
				delete board;
				board = new Board();
			} else if ((localPosition.x >= 1029 && localPosition.x <= 1275) && (localPosition.y >= 949 && localPosition.y <= 1019)) {
				delete board;
				return 0;
			}
		}
		//END BACK

		//START BOARD
		window.setView(boardView);
		sf::RectangleShape tile(sf::Vector2f(TILESIZE, TILESIZE));
		for (int y = 0; y < 8; ++y)
		{
			for (int x = 0; x < 8; ++x)
			{
				tile.setPosition(x * TILESIZE, y * TILESIZE);
				tile.setFillColor((x + y) & 1 ? sf::Color::Color(229, 229, 229) : sf::Color::Color(178, 178, 178));
				window.draw(tile);
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2f localPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			if (localPosition.x <= TILESIZE * 8 || localPosition.y <= TILESIZE * 8) {
				if (board->validPiece(selected)) {
					if (!board->move(selected, Position(localPosition.x / TILESIZE, localPosition.y / TILESIZE))) {
						selected = Position(localPosition.x / TILESIZE, localPosition.y / TILESIZE);
					} else {
						if (board->gameOver()) {
							std::cout << "Checkmate!" << std::endl;

							sf::Text checkmateText;
							checkmateText.setFont(font);
							checkmateText.setString("Checkmate!");
							checkmateText.setCharacterSize(36);
							checkmateText.setStyle(sf::Text::Bold);
							checkmateText.setPosition(410, 20);
							window.draw(checkmateText);
						}
					}
				} else {
					selected = Position(localPosition.x / TILESIZE, localPosition.y / TILESIZE);
				}
			}
		}

		board->draw(window, selected, boardView, backView);
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