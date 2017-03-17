#include "../Headers.h"

void Bishop::draw()
{
	if (owner == 0)
		std::cout << " B ";
	else
		std::cout << " b ";
}

bool Bishop::move(const bool player, const std::vector<Pieces*>& board, const Position & position, Pieces ** garbage)
{
	if (std::abs(this->position.x - position.x) == std::abs(this->position.y - position.y)) {
		int mX = -1, mY = -1;
		if (position.x > this->position.x) mX = 1;
		if (position.y > this->position.y) mY = 1;
		int tY = this->position.y + mY;
		for (int i = this->position.x + mX; i != position.x + mX; i += mX) {
			for each (Pieces* piece in board) {
				if (piece->getPosition() == Position(i, tY)) {
					if (i == position.x && piece->getOwner() != player) {
						this->position.x = position.x;
						this->position.y = position.y;
						*garbage = piece;
						return true;
					}
					return false;
				}
			}
			tY += mY;
		}
		this->position.x = position.x;
		this->position.y = position.y;
		return true;
	}
	return false;
}
