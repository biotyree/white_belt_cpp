//============================================================================
// Name        : sort_wo_registr.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void print_vector(vector<string> vect)
{
	for(const auto& element : vect)
		cout << element << " ";
	cout << endl;
}



int main() {
	int N;
	vector<string> array;
	string tmp;
	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> tmp;
		array.push_back(tmp);
	}
	sort (array.begin(),array.end(),[](string x, string j){
		return(tolower(x[0]) < tolower(j[0]));
	});
	print_vector(array);
	return 0;
}

