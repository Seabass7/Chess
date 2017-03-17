#include "../Headers.h"

void Rook::draw()
{
	if (owner == 0)
		std::cout << " R ";
	else
		std::cout << " r ";
}

bool Rook::move(const bool player, const std::vector<Pieces*>& board, const Position & position, Pieces ** garbage)
{
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
		for (int i = start + mod; i <= stop; i += mod) {
			for each (Pieces* piece in board) {
				if ((piece->getPosition() == Position(constant, i) && dir == 0) || (piece->getPosition() == Position(i, constant) && dir == 1)) {
					if (i == stop && piece->getOwner() != player) {
						*original = comp;
						*garbage = piece;
						return true;
					} else {
						return false;
					}
				}
			}
		}
		*original = comp;
		return true;
	}
	return false;
}
