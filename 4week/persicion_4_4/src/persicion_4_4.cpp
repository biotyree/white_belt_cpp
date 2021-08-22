
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void print_file(string path)
{
	ifstream input(path);
	double line;
	if(input)
	{
		while(input >> line)
		{
			cout << fixed << setprecision(3);
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
