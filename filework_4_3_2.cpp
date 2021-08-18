//============================================================================
// Name        : filework_4_3_2.cpp
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

void print_file_to_file(string src, string dest)
{
	ifstream input(src);
	ofstream output(dest);
	string line;
	if(input)
	{
		while(getline(input, line))
		{
			output << line << endl;
		}
	}
	else
		cout << "error";
}

int main() {
	print_file_to_file("input.txt", "output.txt");
	return 0;
}
