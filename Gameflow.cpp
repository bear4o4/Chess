#include "Gameflow.h"

Gameflow::Gameflow()
{
	Pps[0] = new Player("PLAYER 1", BLACK);
	Pps[1] = new Player("PLAYER 2", WHITE);
	B = new Board();
	turn = 0;
	HPs[8][8]={};
}
void Gameflow::play()
{
	B->PRINTboard();
	do{
		TurnMsg(Pps[turn]);
		do{
			do {

				do {
					
					do {
						SelectSRCPosition(sr, sc);
					} while (!IsValidSourceSelected(Pps[turn], sr, sc));
					system("cls");
					B->PRINTboard();
					Highlight(sr,sc);          //highlight
					SelectDESPosition(er, ec);
				} while (!IsValidDestinationSelected(Pps[turn], er, ec)) ;

			} while (!IsKill());

		} while (!IsLegalMove());

		UpdateBoard(sr,sc,er,ec);
		system("cls");
		B->PRINTboard();
	} while (true);
}
bool Gameflow::IsKill()
{//so baically what it will do is that it will kinda prevent player pieces to kill eachoter rest killing is happening 
	if (B->getPiece(er, ec)!=nullptr) {
		if (B->getPiece(sr, sc)->getColor() == B->getPiece(er, ec)->getColor()) {
			return false;
		}
	}
	return true;
}
void Gameflow::Highlight(int& sr ,int &sc)
{

	for (int i = 0; i < 8; i++){//cleaning HPs array 
		for (int j = 0; j < 8; j++){
			if ((B->getPiece(i, j) == nullptr)) {
				HPs[i][j] = '-';
			}
		}
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((B->getPiece(i, j) == nullptr) && (B->getPiece(sr, sc)->IsLegalMove(B, sr, sc, i, j))) {
					HPs[i][j] = 'x';
			}
			if ((B->getPiece(i, j) == nullptr)&&(HPs[i][j]!='x')) {
				HPs[i][j] = '-';
			}
		}
	}
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if ((HPs[i][j]=='x')|| (HPs[i][j] == '-')) {
				gotoRowCol(i, j);
				cout << HPs[i][j];
			}
			if (HPs[i][j] == 'x' && B->getPiece(i, j) != nullptr) {
				gotoRowCol(i, j);
				B->getPiece(i, j)->Draw();
			}
		}
		cout << endl;
	}
}
void Gameflow::TurnMsg(Player* P)
{
	cout << endl;
	if (turn == 0) {//white
		//if (P->getColor() == 15 && P->getName() == "PLAYER 2") {
		cout << P->getName() << " TURN :" << endl;
		cout << "WHITE (above)" << endl;
		turn++;
	}
	else if (turn == 1) {
		//if (P->getColor() == 0 && P->getName() == "PLAYER 1") {
		cout << P->getName() << " TURN :" << endl;
		cout << "BLACK (below)" << endl;
		turn--;
	}
	cout << endl;
}
void Gameflow::SelectSRCPosition(int& sr, int& sc)
{
	cout << "ENTER PIECE SOURCE COORDINATES :" << endl;
	cin >> sr >> sc;
}
void Gameflow::SelectDESPosition(int& er, int& ec) {
	cout <<endl<< "ENTER PIECE DESTINATION COORDINATES :" << endl;
	cin >> er >> ec;
}
bool Gameflow::IsValidSourceSelected(Player* Pps, int r, int c)
{
	if (r >= 0 && r < 8 && c >= 0 && c < 8) {
		return true;
	}
	/*Piece* p = B->getPiece(r, c);
	return p != nullptr&& p->getColor() == Pps->getColor();*/
}
bool Gameflow::IsValidDestinationSelected(Player* Pps, int r, int c)
{
	if (r >= 0 && r < 8 && c >= 0 && c < 8) {
		return true;
	}
	//Piece* p = B->getPiece(r, c);
	//return p != nullptr; //&& p->getColor() != Pps->getColor();
}
bool Gameflow::IsLegalMove()
{
	if (B->getPiece(sr, sc)->IsLegalMove(B, sr, sc, er, ec)==true) {
		return true;
	}
	else {
		return false;
	}
}
void Gameflow::UpdateBoard(int &sr,int &sc,int &er,int &ec)
{
	B->setPiece(sr, sc, er, ec);
}
void Gameflow::gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}
bool Gameflow::checkcastling()
{
	if (sr == 0 && sc == 4 && B->getPiece(sr,sc)->getColor() == BLACK && turn == 1 &&  B->getPiece(sr,sc)->getMoves()== 0)
	{
		if ((er == 0 && ec == 0) && B->getPiece(0, 0) != nullptr && B->getPiece(0,1) == nullptr && B->getPiece(0, 2) == nullptr && B->getPiece(0, 4) != nullptr && B->getPiece(0, 3) == nullptr && B->getPiece(0,0)-> getMoves() == 0) 
		{
			return true;
		}
		else if ((er == 0 && ec == 7) && B->getPiece(0, 7) != nullptr && B->getPiece(0, 6) == nullptr && B->getPiece(0, 5) == nullptr && B->getPiece(0, 4) != nullptr && B->getPiece(0, 7)->getMoves() == 0) 
		{
			return true;
		}
	}
	else if (sr == 7 && sc == 4 && B->getPiece(sr, sc)->getColor() == WHITE && turn == 0 && B->getPiece(sr, sc)->getMoves() == 0) 
	{
		if ((er == 7 && ec == 0) && B->getPiece(7, 0) != nullptr && B->getPiece(7, 1) == nullptr && B->getPiece(7, 2) == nullptr && B->getPiece(7, 4) != nullptr && B->getPiece(7, 3) == nullptr && B->getPiece(7, 0)->getMoves() == 0) 
		{
			return true;
		}
		else if ((er == 7 && ec == 7) && B->getPiece(7, 7) != nullptr && B->getPiece(7, 6) == nullptr && B->getPiece(7, 5) == nullptr && B->getPiece(7, 4) != nullptr && B->getPiece(7, 7)->getMoves() == 0) 
		{
			return true;
		}
	}
	return false;
}
void Gameflow::docastling()
{
	while (checkcastling()) {
		if (turn==0&&sr==7&&sc==4)
		{
			if (er==7&&ec==7) 
			{
				B->setPiece(7, 4, 7, 6);
				B->setPiece(7, 7, 7, 5);
			}
			if (er==7&&ec==0) {
				B->setPiece(7, 4, 7, 2);
				B->setPiece(7, 0, 7, 3);
			}
		}
		if (turn == 1 && sr == 0 && sc == 4) {
			if (er==0 && ec==7) {
				B->setPiece(0, 4, 0, 6);
				B->setPiece(0, 7, 0, 5);
			}
			if (er==0&&ec==0) {
				B->setPiece(0 ,4, 0, 2);
				B->setPiece(0, 0, 0, 3);
			}
		}
	}
}
bool Gameflow::IsCheckmate()
{
	int ri, ci;//king 
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
				if (B->getPiece(i, j) != nullptr&&turn==0&&B->getPiece(i,j)->getPieceSym()=='K') {
					ri = i;
					ci = j;
				}
				else if (B->getPiece(i, j) != nullptr&&turn == 1 && B->getPiece(i, j)->getPieceSym() == 'k') {
					ri = i;
					ci = j;
				}
		}
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (B->getPiece(i, j) != nullptr) {
				if (B->getPiece(i, j)->IsLegalMove(B, i, j, ri, ci) && (B->getPiece(i, j)->getColor() != B->getPiece(ri, ci)->getColor())) {
					return true;
				}
			}
		}
	}
	return false;
}
bool Gameflow::doCheckmate()
{
	while (IsCheckmate()) {
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				for (int k = 0; k < 8; k++)
				{
					for (int l = 0; l < 8; l++)
					{
						if (B->getPiece(i,j)!=nullptr && B->getPiece(i,j)->IsLegalMove(B,i,j,k,l) && B->getPiece(i,j)->getTurnNUMbyColor() == turn) {
							if (B->getPiece(k,l)==nullptr||B->getPiece(k,l)->getTurnNUMbyColor()!=turn) {
								if (!SelfCheck()) {

								}
							}
						}

					}

				}

			}

		}

	}
}
bool Gameflow::SelfCheck()
{
	Piece* P1 = B->getPiece(sr, sc);
	Piece* P2 = B->getPiece(er, ec);
	B->swapPiece(er, ec, P1);
	B->swapPiece(sr, sc, P2);
	while (IsCheckmate()) {
		B->swapPiece(sr, sc, P1);
		B->swapPiece(er, ec, P2);
		return true;
	}
	B->swapPiece(sr, sc, P1);
	B->swapPiece(er, ec, P2);
	return true;
}



