//============================================================================
// Name        : capitals.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <string>

using namespace std;

void change_capital(map<string, string>& countries)
{
	string country, capital;
	cin >> country >> capital;

	if(countries.count(country))
	{
		if(countries[country] == capital)
		{
			cout << "Country "<< country <<" hasn't changed its capital";
		}
		else
		{
			cout << "Country " << country << " has changed its capital from " <<
					countries[country] << " to " << capital;
			countries[country] = capital;
		}
	}
	else
	{
		cout << "Introduce new country " << country << " with capital " << capital;
		countries[country] = capital;
	}
}

void rename(map<string, string>& countries)
{
	string old_country, new_country;
	cin >> old_country >> new_country;

	if(old_country == new_country || countries.count(new_country) || !(countries.count(old_country)))
	{
		cout << "Incorrect rename, skip";
	}
	else
	{
		cout << "Country " << old_country << " with capital " << countries[old_country]
		<< " has been renamed to " << new_country;
		countries[new_country] = countries[old_country];
		countries.erase(old_country);
	}
}

void about(map<string, string>& countries)
{
	string country;
	cin >> country;
	if (countries.count(country) == 0)
	{
		cout << "Country "<< country << " doesn't exist";
	}
	else
	{
		cout << "Country " << country << " has capital " << countries[country];
	}
}

void dump(map<string, string>& countries)
{
	if(countries.size())
	{
		for(auto& country : countries)
		{
			cout << country.first << "/" << country.second << " ";
		}
	}
	else
		cout << "There are no countries in the world";
}

int main()
{
	string comand;
	int n;
	cin >> n;
	map<string, string> countries;

	for(int i = 0; i < n; i++)
	{
		cin >> comand;
		if(comand == "CHANGE_CAPITAL")
		{
			change_capital(countries);
		}
		else if(comand == "RENAME")
		{
			rename(countries);
		}
		else if(comand == "ABOUT")
		{
			about(countries);
		}
		else if(comand == "DUMP")
		{
			dump(countries);
		}
		cout << endl;
	}

	return 0;
}
