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
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void print_map(const map<int, string>& vec)
{
	cout << "begin:" << endl;
	for(const auto& el : vec)
		cout << el.first << el.second << endl;
	cout << ":end" << endl;
}

void print_vector(const vector<string>& vec)
{
	cout << "begin:" << endl;
	for(const auto& el : vec)
		cout << el << endl;
	cout << ":end" << endl;
}

vector<string> reverse_vector(const vector<string>& vec)
{
	vector<string> new_vec;
	if (vec.size() > 0)
	{
		for(int i = vec.size() - 1; i >= 0;)
		{
			new_vec.push_back(vec[i]);
			i--;
		}
	}
	return new_vec;
}

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
	  FirstName[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
	  LastName[year] = last_name;
  }
  string GetFullName(int year) {
	  int firstname_year = year_changed(FirstName, year);
	  int lastname_year = year_changed(LastName, year);

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

  string GetFullNameWithHistory(int year) {
	  string fn_hist = change_hist(FirstName, year);
	  string ln_hist = change_hist(LastName, year);

	  string name_history = fn_hist + " " + ln_hist;

	  if(name_history.size() == 1)
		  name_history = "Incognito";
	  else if(!(fn_hist.size()))
		  name_history = ln_hist + " with unknown first name";
	  else if(!(ln_hist.size()))
		  name_history = fn_hist + " with unknown last name";
	  else
		  name_history = fn_hist + " " + ln_hist;
	  return name_history;
  }

private:
  map<int, string> FirstName;
  map<int, string> LastName;

  int year_changed(const map<int, string>& name, int year)
  {
	  int tmp = -1;
	  for(const auto& i : name)
		  if(i.first <= year && i.first > tmp)
			  tmp = i.first;
	  return tmp;
  }
  string change_hist(const map<int, string>& names, int year)
  {
	  string history;

	  vector<string> forgot_names;

	  for(const auto& name : names)
		  if(name.first <= year)
			  forgot_names.push_back(name.second);

	  vector<string> tmp_names = reverse_vector(forgot_names);

	  if(tmp_names.size())
	  {
		  history = tmp_names[0];

	  }
	  if(tmp_names.size() > 1 )
	  {
		  string first_word = tmp_names[0];


		  tmp_names.erase(tmp_names.begin());
		  if(tmp_names.size() < 2 && tmp_names[0] == first_word)
		  {
			  return history;
		  }
		  history += " (";
		  int i = 0;
		  bool flag = true;
		  for(auto& el : tmp_names)
		  {
			  int j = 0;
			  for(auto& el1 : tmp_names)
			  {
				  if((el == el1 && i != j))
				  {
					  tmp_names.erase(tmp_names.begin() + i);
					  flag = false;
					  break ;
				  }
				  j++;
			  }
			  i++;
			  if(!flag)
			  {
				  break ;
				  cout << "hi";
			  }else
			  {
				  history += el;
				  if (i < (int)tmp_names.size())
					  history += ", ";
			  }
		  }

		  history += ")";
	  }
  	  return history;
  }
};



int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;

  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;

  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;

  return 0;
}

