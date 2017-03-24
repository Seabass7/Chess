#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <SFML/Graphics.hpp>

#define TILESIZE 75

//Pieces
#include "Position.h"
#include "Pieces.h"
#include "Pieces/King.h"
#include "Pieces/Queen.h"
#include "Pieces/Rook.h"
#include "Pieces/Bishop.h"
#include "Pieces/Knight.h"
#include "Pieces/Pawn.h"

//Special moves?
//Castling (sv: Rockad) (req: not moved before)
//En passant (req: last move)
//Pawn promotion

//Game
#include "History.h"
#include "Board.h"