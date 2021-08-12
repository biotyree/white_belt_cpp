//============================================================================
// Name        : sort_by_abs.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_vector(vector<int> vect)
{
	for(const auto& element : vect)
		cout << element << " ";
	cout << endl;
}

int main() {
	int N;
	vector<int> array;
	int tmp;
	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> tmp;
		array.push_back(tmp);
	}
	sort (array.begin(),array.end(),[](int x, int j){
		return(abs(x) < abs(j));
	});
	print_vector(array);
	return 0;
}
