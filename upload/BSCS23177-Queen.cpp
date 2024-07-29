#include "Queen.h"

Queen::Queen(int _r, int _c, color _C, Board* _B) :Piece(_r, _c, _C, _B)
{
	this->ri = _r;
	this->ci = _c;
	this->C = _C;
	this->B = _B;
	this->move = 0;
}


bool Queen::IsLegalMove(Board* B, int sr, int sc, int er, int ec) {
	return (IsHorizontalMove(sr, sc, er, ec) && IsHorizontalPathClear(B, sr, sc, sr, ec) || IsVerticalMove(sr, sc, er, ec) && IsVertiaclPathClear(B, sr, sc, er, ec)) || (IsDiagonalMove(sr, sc, er, ec) && IsDiagonalPathClear(B, sr, sc, er, ec));
}

void Queen::Draw(){
	cout << ((C == WHITE) ? 'Q' : 'q');
}

int Queen::getMoves()
{
	return move;
}

void Queen::setMoves()
{
	move + 1;
}

char Queen::getPieceSym()
{
	if (C == WHITE) {
		return 'Q';
	}
	else {
		return 'q';
	}
}

int Queen::getROW()
{
	return ri;
}

int Queen::getCOL()
{
	return ci;
}

int Queen::getTurnNUMbyColor()
{
	if (C == BLACK) {
		return 1;
	}
	else {
		return 0;
	}
}
