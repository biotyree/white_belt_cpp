//============================================================================
// Name        : ensureequal_4_4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void EnsureEqual(const string& left, const string& right)
{
	if(left != right)
	{
		string str = "";
		str = left + " != " + right;
		throw runtime_error(str);
	}
}

int main() {
  try {
    EnsureEqual("C++ White", "C++ White");
    EnsureEqual("C++ White", "C++ Yellow");
  } catch (runtime_error& e) {
    cout << e.what() << endl;
  }
  return 0;
}
