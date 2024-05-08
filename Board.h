#pragma once
#include"Header.h"
#include"Piece.h"
#include"Pawn.h"
#include"Rook.h"
#include "King.h"
#include"Queen.h"
#include"Bishp.h"
#include"Knight.h"
using namespace std;
//class Piece;
//class Pawn;
//class Rook;
//class King;
//class Queen;
//class Bishp;
//class Knight;

class Board
{
protected:
	Piece*** Ps;

public:
	Board();
	void PRINTboard();
	Piece* getPiece(int r,int c);
	//Board getBoardCoordinate(int r,int c);
	Piece* setPiece(int sr, int sc,int er,int ec);

};

