#include "../Headers.h"

bool Knight::testMove(const bool player, const std::vector<Pieces*>& board, const std::vector<History*>& history, const Position & position, Pieces ** garbage)
{
	if ((this->position.y - 2 == position.y && (this->position.x + 1 == position.x || this->position.x - 1 == position.x))
		|| (this->position.y + 2 == position.y && (this->position.x + 1 == position.x || this->position.x - 1 == position.x))
		|| (this->position.x - 2 == position.x && (this->position.y + 1 == position.y || this->position.y - 1 == position.y))
		|| (this->position.x + 2 == position.x && (this->position.y + 1 == position.y || this->position.y - 1 == position.y))) {
		for each (Pieces* piece in board)
		{
			if (piece->getPosition() == position) {
				if (piece->getOwner() == player) {
					return false;
				} else {
					*garbage = piece;
					return true;
				}
			}
		}
		return true;
	}
	return false;
}
