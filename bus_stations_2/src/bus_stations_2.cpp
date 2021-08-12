//============================================================================
// Name        : bus_station_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void new_roadmap(map<int, vector<string>>& roadmap)
{
	int amount;
	string station;
	vector<string> stations;
	cin >> amount;
	int i = 1;

	for(int i = 0; i < amount; i++)
	{
		cin >> station;
		stations.push_back(station);
	}
	for(auto& road : roadmap)
	{
		if (road.second == stations)
		{
			cout << "Already exists for " << road.first << endl;
			return;
		}
		i++;
	}
	roadmap[i] = stations;
	cout << "New bus " << i << endl;
}

int main() {
	int N;
	map<int, vector<string>> roadmap;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		new_roadmap(roadmap);

	}
	return 0;
}
