//============================================================================
// Name        : student_struct_4_3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student
{
	string FirstName;
	string LastName;
	int Day;
	int Month;
	int Year;
};

int main() {

	int N;
	cin >> N;

		string FirstName, LastName;
		int Day, Month, Year;
		vector<Student> Students;
		for(int i = 0; i < N; i++)
		{
			cin >> FirstName >> LastName >> Day >> Month >> Year;
			Students.push_back({FirstName, LastName, Day, Month, Year});
		}
		int M;
		cin >> M;
		string command;
		int K;
		for(int i = 0; i < M; i++)
		{
			cin >> command >> K;
			K--;
			if(command == "name" && K >= 0 && K < N)
			{
				cout << Students[K].FirstName << " " << Students[K].LastName << endl;
			}
			else if(command == "date" && K >=0 && K < N)
			{
				cout << Students[K].Day << "." << Students[K].Month << "." << Students[K].Year << endl;
			}
			else
				cout << "bad request" << endl;

	}
	return 0;
}
