#pragma once
using namespace std;
#include<iostream>
#include"Board.h"
#include"Player.h"
#include"Piece.h"
#include<time.h>
#include<string>


class Gameflow
{
private:
	int sr, sc, er, ec;
	int turn;
	Player* Pps[2];
	Board* B;
	char HPs[8][8];
public:
	Gameflow();
	void play();
	void TurnMsg(Player* Pps);
	void SelectSRCPosition(int& sr, int& sc);
	void SelectDESPosition(int& er, int& ec);
	bool IsValidSourceSelected(Player* Pps,int r,int c);
	bool IsValidDestinationSelected(Player* Pps, int r, int c);
	bool IsLegalMove();
	void UpdateBoard(int& sr, int& sc, int& er, int& ec);
	bool IsKill();
	void Highlight(int& sr, int& sc);
	void gotoRowCol(int rpos, int cpos);

	bool checkcastling();
	void docastling();

	bool IsCheckmate();
	bool doCheckmate();

	bool SelfCheck();
};


