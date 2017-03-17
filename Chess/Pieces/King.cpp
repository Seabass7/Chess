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
	//move
	//castling
	return false;
}
