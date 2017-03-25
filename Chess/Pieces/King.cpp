#include "../Headers.h"

bool King::testMove(const bool player, const std::vector<Pieces*>& board, const std::vector<History*>& history, const Position & position, Pieces ** garbage)
{
	if (!(this->getPosition() == position) &&
		(this->getPosition().x - 1 == position.x || this->getPosition().x == position.x || this->getPosition().x + 1 == position.x) &&
		(this->getPosition().y - 1 == position.y || this->getPosition().y == position.y || this->getPosition().y + 1 == position.y)) {
		for each (Pieces* piece in board) {
			if (piece->getPosition() == position && piece->getOwner() != player) {
				if (!check(player, board, history, position, garbage)) {
					*garbage = piece;
					return true;
				} else {
					return false;
				}
			} else if (piece->getPosition() == position && piece->getOwner() == player) {
				return false;
			}
		}
		if (!check(player, board, history, position, garbage)) {
			return true;
		} else {
			return false;
		}
	} else if ((position.x == 2 || position.x == 6) && (position.y == 0 || position.y == 7) && moves == 0 && !check(player, board, history, position, garbage)) {
		for each (Pieces* piece in board) {
			if (piece->getPosition().x + 2 == position.x && piece->getType() == Pieces::Rook) {
				if ((piece->getPosition().y == 0 && piece->getOwner() == 1) || (piece->getPosition().y == 7 && piece->getOwner() == 0)) {
					if (piece->getMoves() == 0) {
						if (piece->move(player, board, history, Position(3, position.y), garbage)) {
							piece->stats(nullptr);
							return true;
						}
					}
				}
			} else if (piece->getPosition().x - 1 == position.x && piece->getType() == Pieces::Rook) {
				if ((piece->getPosition().y == 0 && piece->getOwner() == 1) || (piece->getPosition().y == 7 && piece->getOwner() == 0)) {
					if (piece->getMoves() == 0) {
						if (piece->move(player, board, history, Position(5, position.y), garbage)) {
							piece->stats(nullptr);
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}