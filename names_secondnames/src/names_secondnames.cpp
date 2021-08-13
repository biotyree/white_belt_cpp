//============================================================================
// Name        : names_secondnames.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
	  FirstName[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
	  LastName[year] = last_name;
  }
  string GetFullName(int year) {
	  int firstname_year = year_cheanged(FirstName, year);
	  int lastname_year = year_cheanged(LastName, year);

	  if (FirstName.count(firstname_year) && LastName.count(lastname_year))
		  return FirstName[firstname_year] + " " + LastName[lastname_year];
	  else if (FirstName.count(firstname_year) && !(LastName.count(lastname_year)))
	  {
		  return FirstName[firstname_year] + " with unknown last name";
	  }
	  else if (!(FirstName.count(firstname_year)) && LastName.count(lastname_year))
	  {
		  return LastName[lastname_year] + " with unknown first name";
	  }
	  else
		  return "Incognito";
  }
private:
  map<int, string> FirstName;
  map<int, string> LastName;

  int year_cheanged(map<int, string>& name, int year)
  {
	  int tmp = -1;
	  for(const auto& i : name)
		  if(i.first <= year && i.first > tmp)
			  tmp = i.first;
	  return tmp;
  }
};


int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  return 0;
}
