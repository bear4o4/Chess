#include "Bishp.h"

Bishp::Bishp(int _r, int _c, color _C, Board* _B) :Piece(_r, _c, _C, _B)
{
	this->ri = _r;
	this->ci = _c;
	this->C = _C;
	this->B = _B;
	this->move = 0;
}

bool Bishp::IsLegalMove(Board* B, int sr, int sc, int er, int ec)
{
	return IsDiagonalMove(sr, sc, er, ec) && IsDiagonalPathClear(B, sr, sc, er, ec);
}

void Bishp::Draw()
{
	cout << ((C == WHITE) ? 'B' : 'b');
}

int Bishp::getMoves()
{
	return move;
}

void Bishp::setMoves()
{
	move + 1;
}

char Bishp::getPieceSym()
{
	if (C == WHITE) {
		return 'B';
	}
	else {
		return 'b';
	}
}

int Bishp::getTurnNUMbyColor()
{
	if (C == BLACK) {
		return 1;
	}
	else {
		return 0;
	}
}

