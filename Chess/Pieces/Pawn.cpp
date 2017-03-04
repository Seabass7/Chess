#include "../Headers.h"

void Pawn::draw()
{
	if (owner == 0)
		std::cout << " P ";
	else
		std::cout << " q ";
}

bool Pawn::move(const bool player, const std::vector<Pieces*>& board, const Position & position)
{
	//One step forward
	if (((this->position.y - 1 == position.y && player == 0) || (this->position.y + 1 == position.y && player == 1)) && this->position.x == position.x) {
		for each (Pieces* piece in board)
		{
			if (piece->getPosition() == position) {
				return false;
			}
		}
		this->position.x = position.x;
		this->position.y = position.y;
		return true;

	//Two steps forward
	} else if (((this->position.y == 7 && position.y == 5 && player == 0)
		|| (this->position.y == 2 && position.y == 4 && player == 1)) && this->position.x == position.x) {
		for each (Pieces* piece in board)
		{
			if (piece->getPosition() == position || (piece->getPosition() == Position(this->position.x - 1, position.x) && player == 0)
				|| (piece->getPosition() == Position(this->position.x + 1, position.x) && player == 1)) {
				return false;
			}
		}
		this->position.x = position.x;
		this->position.y = position.y;
		return true;

	//Take another piece
	} else if (((this->position.y - 1 == position.y && player == 0) || (this->position.y + 1 == position.y && player == 1))
		&& (this->position.x - 1 == position.x || this->position.x + 1 == position.x)) {
		for each (Pieces* piece in board)
		{
			if (piece->getOwner() == 1) {
				if (piece->getPosition() == position) {
					this->position.x = position.x;
					this->position.y = position.y;
					//TODO: REMOVE TAKEN PIECE
					return true;
				}
			}
		}
		return false;
	}
	return false;
}
