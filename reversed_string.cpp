//============================================================================
// Name        : reversed_string.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class ReversibleString
{
	public:
		ReversibleString(){}
		ReversibleString(const string new_content)
		{
			content = new_content;
		}
		string ToString () const
		{
			return content;
		}
		void Reverse ()
		{
			string new_content = "";

			new_content += content;
			reverse(new_content.begin(),new_content.end());
			content = new_content;
		}
	private:
	string content;
};

int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;

  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;

  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;

  return 0;
}
