#include "../Headers.h"

void Knight::draw()
{
	if (owner == 0)
		std::cout << " K ";
	else
		std::cout << " k ";
}

bool Knight::move(const bool player, const std::vector<Pieces*>& board, const Position & position, Pieces ** garbage)
{
	if ((this->position.y - 2 == position.y && this->position.x + 1 == position.x || this->position.x - 1 == position.x)
		|| (this->position.y + 2 == position.y && this->position.x + 1 == position.x || this->position.x - 1 == position.x)
		|| (this->position.x - 2 == position.x && this->position.y + 1 == position.y || this->position.y - 1 == position.y)
		|| (this->position.x + 2 == position.x && this->position.y + 1 == position.y || this->position.y - 1 == position.y)) {
		for each (Pieces* piece in board)
		{
			if (piece->getPosition() == position) {
				if (piece->getOwner() == player) {
					return false;
				} else {
					this->position.x = position.x;
					this->position.y = position.y;
					*garbage = piece;
					return true;
				}
			}
		}
		this->position.x = position.x;
		this->position.y = position.y;
		return true;
	}
	return false;
}
