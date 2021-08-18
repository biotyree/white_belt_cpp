//============================================================================
// Name        : print_table_4_5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void print_table(string path)
{
	ifstream input(path);
	int i = 0;
	int start_j = 0;
	double number;
	if(input)
	{
		input >> i;
		input.ignore(1);
		input >> start_j;
		input.ignore(1);
		int j = 0;
		while(i--)
		{
			j = start_j;
			while(j--)
			{
				input >> number;
				cout << setw(10);
				cout << number;
				if (j != 0)
					cout << " ";
				input.ignore(1);
			}
			if(i != 0)
				cout << endl;
		}
	}
	else
		cout << "error";
}

int main() {

	print_table("input.txt");
	return 0;
}
