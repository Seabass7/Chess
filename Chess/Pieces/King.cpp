#include "../Headers.h"

bool King::testMove(const bool player, const std::vector<Pieces*>& board, const std::vector<History*>& history, const Position & position, Pieces ** garbage)
{
	if (!(this->getPosition() == position) &&
		(this->getPosition().x - 1 == position.x || this->getPosition().x == position.x || this->getPosition().x + 1 == position.x) &&
		(this->getPosition().y - 1 == position.y || this->getPosition().y == position.y || this->getPosition().y + 1 == position.y)) {
		for each (Pieces* piece in board) {
			if (piece->getPosition() == position && piece->getOwner() != player) {
				if (!check(board, position)) {
					*garbage = piece;
					return true;
				} else {
					return false;
				}
			} else if (piece->getPosition() == position && piece->getOwner() == player) {
				return false;
			}
		}
		if (!check(board, position)) {
			return true;
		} else {
			return false;
		}
	} else if ((position.x == 2 || position.x == 6) && moves == 0 && !check(board, this->position)) { //Castling
		for each (Pieces* piece in board) {
			if (piece->getPosition().x + 2 == position.x) {
				if ((piece->getPosition().y == 0 && piece->getOwner() == 1) || (piece->getPosition().y == 7 && piece->getOwner() == 0)) {
					if (piece->getMoves() == 0) {
						if (!check(board, position)) {
							if (piece->move(player, board, history, Position(3, position.y), garbage)) {
								return true;
							}
						}
					}
				}
			} else if (piece->getPosition().x - 1 == position.x) {
				if ((piece->getPosition().y == 0 && piece->getOwner() == 1) || (piece->getPosition().y == 7 && piece->getOwner() == 0)) {
					if (piece->getMoves() == 0) {
						if (!check(board, position)) {
							if (piece->move(player, board, history, Position(5, position.y), garbage)) {
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}

bool King::check(const std::vector<Pieces*>& board, const Position & position)
{
	std::vector<History*> tempHistory;
	Pieces* tempGarbage;
	Position temp = this->position;
	this->position = position;
	for each (Pieces* piece in board) {
		if (piece->getOwner() != this->owner) {
			std::cout << !owner << std::endl;
			if (piece->testMove(!owner, board, tempHistory, position, &tempGarbage)) {
				this->position = temp;
				return true;
			}
		}
	}
	this->position = temp;
	return false;
}
