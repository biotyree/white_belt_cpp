//============================================================================
// Name        : initialization.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Incognizable{
public:
	Incognizable(){}
	Incognizable(int i){number1 = i;}
	Incognizable(int i, int j){number1 = i; number2 = j;}
private:
	int number1 = 1;
	int number2 = 2;
};

int main() {
  Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
  return 0;
}
