#include "../Headers.h"

bool Queen::testMove(const bool player, const std::vector<Pieces*>& board, const std::vector<History*>& history, const Position & position, Pieces ** garbage)
{
	std::cout << "test" << std::endl;
	if (!(this->position == position)) {
		if (this->position.x == position.x || this->position.y == position.y) {
			int start, stop, mod = 1, comp, dir, constant;
			int* original;
			if (this->position.x == position.x) {
				constant = this->position.x;
				original = &this->position.y;
				comp = position.y;
				dir = 0;
			} else {
				constant = this->position.y;
				original = &this->position.x;
				comp = position.x;
				dir = 1;
			}
			start = *original;
			stop = comp;
			if (*original > comp)
				mod = -1;
			for (int i = start + mod; i != stop + mod; i += mod) {
				for each (Pieces* piece in board) {
					if ((piece->getPosition() == Position(constant, i) && dir == 0) || (piece->getPosition() == Position(i, constant) && dir == 1)) {
						if (i == stop && piece->getOwner() != player) {
							*garbage = piece;
							return true;
						} else {
							return false;
						}
					}
				}
			}
			return true;
		}
		else if (std::abs(this->position.x - position.x) == std::abs(this->position.y - position.y)) {
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
