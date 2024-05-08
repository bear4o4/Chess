#include "King.h"

King::King(int _r, int _c, color _C, Board* _B) :Piece(_r, _c, _C, _B)
{
	this->ri = _r;
	this->ci = _c;
	this->C = _C;
	this->B = _B;
	this->move = 0;
}

bool King::IsLegalMove(Board* B, int sr, int sc, int er, int ec)
{
	int changeinrow, changeincol;
	changeinrow = abs(sr - er);
	changeincol = abs(sc - ec);

	return ((IsHorizontalMove(sr, sc, er, ec) && IsHorizontalPathClear(B, sr, sc, sr, ec) || IsVerticalMove(sr, sc, er, ec) && IsVertiaclPathClear(B, sr, sc, er, ec)) || (IsDiagonalMove(sr, sc, er, ec) && IsDiagonalPathClear(B, sr, sc, er, ec))) && changeinrow <= 1 && changeincol <= 1;
}

void King::Draw()
{
	cout << ((C == WHITE) ? 'K' : 'k');
}

int King::getMoves()
{
	return move;
}

void King::setMoves()
{
	move + 1;
}

char King::getPieceSym()
{
	if (C == WHITE) {
		return 'K';
	}
	else {
		return 'k';
	}
}

int King::getTurnNUMbyColor()
{
	if (C == BLACK) {
		return 1;
	}
	else {
		return 0;
	}
}
