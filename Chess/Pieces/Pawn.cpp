#include "../Headers.h"

void Pawn::draw() //TODO
{
	if (owner == 0)
		std::cout << " P ";
	else
		std::cout << "-p ";
}

bool Pawn::move(const bool player, const std::vector<Pieces*>& board, const Position & position, Pieces** garbage)
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
		if (this->position.y == 1 || this->position.y == 8) {
			std::cout << "Choose a new piece :)\n...not implemented... :(" << std::endl; //TODO
		}
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
			if (piece->getOwner() != player) {
				if (piece->getPosition() == position) {
					this->position.x = position.x;
					this->position.y = position.y;
					*garbage = piece;
					return true;
				} else if ((piece->getPosition().y == 4 || piece->getPosition().y == 5) && (piece->getPosition().y + 1 == position.y || piece->getPosition().y - 1 == position.y)) {
					//en passant (https://en.wikipedia.org/wiki/En_passant)
					std::cout << "En passant? Sorry, not implemented yet..." << std::endl; //TODO
					return false;
				}
			}
		}
		return false;
	}
	return false;
}
