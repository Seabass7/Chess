#include "../Headers.h"

void King::draw()
{
	if (owner == 0)
		std::cout << "KIN";
	else
		std::cout << "kin";
}

bool King::move(const bool player, const std::vector<Pieces*>& board, const Position & position, Pieces ** garbage)
{
	if ((this->getPosition().x - 1 == position.x || this->getPosition().x + 1 == position.x) &&
		(this->getPosition().y - 1 == position.y || this->getPosition().y + 1 == position.y)) {
		for each (Pieces* piece in board) {
			if (piece->getPosition() == position && piece->getOwner() != player) {
				if (!check(board, position)) {
					this->position = position; //Add to check?
					*garbage = piece;
					return true;
				} else {
					return false;
				}
			}
		}
		if (!check(board, position)) {
			this->position = position; //Add to check?
			return true;
		} else {
			return false;
		}
	} else if ( false ) {
		//castling
		//The king and the chosen rook are on the player's first rank.
		//Neither the king nor the chosen rook has previously moved. (moves == 0)
		//There are no pieces between the king and the chosen rook.
		//The king is not currently in check.
		//The king does not pass through a square that is attacked by an enemy piece.
		//The king does not end up in check. (True of any legal move.)
	}
	return false;
}

bool King::check(const std::vector<Pieces*>& board, const Position & position)
{
	//TODO
	return false;
}
