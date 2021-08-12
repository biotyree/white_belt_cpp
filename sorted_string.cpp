//============================================================================
// Name        : sorted_string.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
    sorted_string.push_back(s);
  }
  vector<string> GetSortedStrings()
  {
	  sort(sorted_string.begin(),sorted_string.end());
	  return sorted_string;
  }
private:
  vector<string> sorted_string;
};

void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}

int main() {
  SortedStrings strings;

  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  PrintSortedStrings(strings);

  strings.AddString("second");
  PrintSortedStrings(strings);

  return 0;
}
