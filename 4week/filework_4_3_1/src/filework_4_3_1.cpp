//============================================================================
// Name        : filework_4_3_1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void print_file(string path)
{
	ifstream input(path);
	string line;
	if(input)
	{
		while(getline(input, line))
		{
			cout << line << endl;
		}
	}
	else
		cout << "error";
}

int main() {
	print_file("input.txt");
	return 0;
}
