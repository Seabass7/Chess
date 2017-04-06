#include "Headers.h"

bool Pieces::check(const bool player, const std::vector<Pieces*>& board, const std::vector<History*>& history, const Position & position, Pieces ** garbage)
{
	Pieces* tempGarbage;
	Position temp = this->position;
	if (*garbage != nullptr) {
		(*garbage)->position.x += 10;
	}
	this->position = position;
	for each (Pieces* king in board) {
		if (king->type == Pieces::King && king->getOwner() == player) {
			for each (Pieces* piece in board) {
				if (piece->getOwner() != player && !(piece->getPosition() == this->position) && piece->getPosition().isValid()) {
					if (piece->testMove(!player, board, history, king->getPosition(), &tempGarbage)) {
						this->position = temp;
						if (*garbage != nullptr) {
							(*garbage)->position.x -= 10;
						}
						return true;
					}
				}
			}
		}
	}
	this->position = temp;
	if (*garbage != nullptr) {
		(*garbage)->position.x -= 10;
	}
	return false;
}

void Pieces::draw(sf::RenderWindow & window)
{
	sprite.setPosition(position.x * TILESIZE + 27.f, position.y * TILESIZE - 2.f);
	sprite.setScale(sf::Vector2f(0.385f, 0.385f));
	window.draw(sprite);
}

void Pieces::drawSide(sf::RenderWindow & window, const int x, const int y)
{
	sprite.setPosition(x * 31.f + 1029.f, y * 65.f + 10.f);
	sprite.setScale(sf::Vector2f(0.25f, 0.25f));
	window.draw(sprite);
}

bool Pieces::move(const bool player, const std::vector<Pieces*>& board, const std::vector<History*>& history, const Position & position, Pieces ** garbage)
{
	if (testMove(player, board, history, position, garbage)) {
		if (!check(player, board, history, position, garbage)) {
			this->position = position;
			return true;
		}
	}
	return false;
}

void Pieces::stats(Pieces * taken)
{
	moves++;
	if (taken != nullptr)
		this->taken++;
}
