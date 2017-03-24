#include "../Headers.h"

bool Bishop::testMove(const bool player, const std::vector<Pieces*>& board, const std::vector<History*>& history, const Position & position, Pieces ** garbage)
{
	if (!(this->position == position)) {
		if (std::abs(this->position.x - position.x) == std::abs(this->position.y - position.y)) {
			int mX = -1, mY = -1;
			if (position.x > this->position.x) mX = 1;
			if (position.y > this->position.y) mY = 1;
			int tY = this->position.y + mY;
			for (int i = this->position.x + mX; i != position.x + mX; i += mX) {
				for each (Pieces* piece in board) {
					if (piece->getPosition() == Position(i, tY)) {
						if (i == position.x && piece->getOwner() != player) {
							*garbage = piece;
							return true;
						}
						return false;
					}
				}
				tY += mY;
			}
			return true;
		}
	}
	return false;
}
