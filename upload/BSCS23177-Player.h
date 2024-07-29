#pragma once
#include<string>
using namespace std;
#include"Header.h"

class Player {
	string name;
	color C;
public:
	Player(string _n,color _C);
	string getName();
	color getColor();
};