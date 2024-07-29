#include "Rook.h"

Rook::Rook(int _r, int _c, color _C, Board* _B) :Piece(_r, _c, _C, _B)
{
	this->ri = _r;
	this->ci = _c;
	this->C = _C;
	this->B = _B;
	this->move = 0;
}


bool Rook::IsLegalMove(Board* B, int sr, int sc, int er, int ec) {
	return IsHorizontalMove(sr, sc, er, ec) && IsHorizontalPathClear(B, sr, sc, sr, ec) || IsVerticalMove(sr, sc, er, ec) && IsVertiaclPathClear(B, sr, sc, er, ec);
}

void Rook::Draw()
{
	cout << ((C == WHITE) ? 'R' : 'r');
}

int Rook::getMoves()
{
	return move;
}
void Rook::setMoves()
{
	move + 1;
}

char Rook::getPieceSym()
{
	if (C == WHITE) {
		return 'R';
	}
	else {
		return 'r';
	}
}

int Rook::getROW()
{
	return ri;
}

int Rook::getCOL()
{
	return ci;
}

int Rook::getTurnNUMbyColor()
{
	if (C == BLACK) {
		return 1;
	}
	else {
		return 0;
	}
}
