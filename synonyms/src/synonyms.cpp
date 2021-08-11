//============================================================================
// Name        : synonyms.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

void add(vector<set<string>>& dict)
{
	string word1, word2;
	cin >> word1 >> word2;

	set<string> tmp;
	tmp.insert(word1);
	tmp.insert(word2);

	dict.push_back(tmp);
}

void count(vector<set<string>>& dict)
{
	int counter = 0;
	string word;
	cin >> word;

	for(auto& words_set : dict)
	{
		if(words_set.count(word))
			counter++;
	}
	cout << counter << endl;
}

void check(const vector<set<string>>& dict)
{
	string isSynonyms = "NO";
	string word1, word2;
	cin >> word1 >> word2;

	for(auto& words_set : dict)
	{
		if(words_set.count(word1) && words_set.count(word2))
		{
			isSynonyms = "YES";
			break;
		}
	}
	cout << isSynonyms << endl;
}

int main() {
	int N;
	cin >> N;
	string request;
	vector<set<string>> dict;

	for (int i = 0; i < N; i++)
	{
		cin >> request;
		if(request == "ADD")
		{
			add(dict);
		}
		else if(request == "COUNT")
		{
			count(dict);
		}
		else if (request == "CHECK")
		{
			check(dict);
		}
	}
	return 0;
}
