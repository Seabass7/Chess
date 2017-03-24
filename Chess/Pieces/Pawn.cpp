#include "../Headers.h"

bool Pawn::testMove(const bool player, const std::vector<Pieces*>& board, const std::vector<History*>& history, const Position& position, Pieces** garbage)
{
	//One step forward
	if (((this->position.y - 1 == position.y && player == 0) || (this->position.y + 1 == position.y && player == 1)) && this->position.x == position.x) {
		for each (Pieces* piece in board)
		{
			if (piece->getPosition() == position) {
				return false;
			}
		}
		/*if (position.y == 0 || position.y == 7) {
			*garbage = this;
		}*/
		return true;

		//Two steps forward
	} else if (((this->position.y == 6 && position.y == 4 && player == 0) || (this->position.y == 1 && position.y == 3 && player == 1)) && this->position.x == position.x) {
		for each (Pieces* piece in board)
		{
			if (piece->getPosition() == position || (piece->getPosition() == Position(this->position.x, this->position.y - 1) && player == 0)
				|| (piece->getPosition() == Position(this->position.x, this->position.y + 1) && player == 1)) {
				return false;
			}
		}
		return true;

		//Take another piece
	} else if (((this->position.y - 1 == position.y && player == 0) || (this->position.y + 1 == position.y && player == 1))
		&& (this->position.x - 1 == position.x || this->position.x + 1 == position.x)) {
		for each (Pieces* piece in board)
		{
			if (piece->getOwner() != player) {
				if (piece->getPosition() == position) {
					*garbage = piece;
					return true;
				} else if ((piece->getPosition().y == 3 || piece->getPosition().y == 4) && (piece->getPosition().y + 1 == position.y || piece->getPosition().y - 1 == position.y)) { //En passant
					if (history.back()->getDestination() == piece->getPosition()
						&& (history.back()->getPosition().y == position.y + 1 || history.back()->getPosition().y == position.y - 1)
						&& piece->getPosition().x == position.x && piece->getOwner() != player) {
						*garbage = piece;
						return true;
					}
				}
			}
		}
		return false;
	}
	return false;
}
