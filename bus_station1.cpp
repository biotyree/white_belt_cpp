//============================================================================
// Name        : bus_station1.cpp
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

void new_bus(map<string, vector<string>>& buses_stops)
{
	string bus, tmp_stop;
	int stops_count;

	cin >> bus >> stops_count;

	for(int i = 0; i < stops_count; i++)
	{
		cin >> tmp_stop;
		buses_stops[bus].push_back(tmp_stop);
	}
}

bool stops_for_this_bus(vector<string>& stops, string this_stop)
{
	for (auto& stop : stops)
	{
		if(stop == this_stop)
			return true;
	}
	return false;
}

void buses_for_stop(map<string, vector<string>>& buses_stops)
{
	string stop;
	cin >> stop;
	bool flag = false;

	for(auto& path : buses_stops)
	{
		if((flag = stops_for_this_bus(path.second, stop)))
			cout << path.first << " ";
	}
	if (flag == false)
		cout << "No stop";
	cout << endl;
}
// stops_for_bus is not working
void stops_for_bus(map<string, vector<string>>& buses_stops)
{
	string bus;
	cin >> bus;
	bool flag = false;
	int count = 0;

	if(!buses_stops.count(bus))
	{
		cout << "No bus" << endl;
		return;
	}

	for(auto& buses : buses_stops)
	{
		count = 0;
		for(auto& act_stop : buses_stops[bus])
		{

			flag = stops_for_this_bus(buses.second, act_stop);
			if(flag && bus != buses.first)
			{
				if(count == 0)
					cout << "Stop " << act_stop << ": ";
				cout << buses.first << " ";
				count++;
				cout << endl;
			}
		}
		if (count == 0)
				cout << "no interchange" << endl;
	}
}

void all_buses(const map<string, vector<string>>& buses_stops)
{
	if(buses_stops.size())
	{
		for(auto& act_bus : buses_stops)
		{
			cout << "Bus " << act_bus.first << ": ";
			for (auto& act_stop : act_bus.second)
			{
				cout << act_stop << " ";
			}
			cout << endl;
		}
	}
	else
		cout << "No buses" << endl;

}

int main() {
	int N;
	string command;
	map<string, vector<string>> buses_stops;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> command;
		if(command == "NEW_BUS")
		{
			new_bus(buses_stops);
		}
		else if (command == "BUSES_FOR_STOP")
		{
			buses_for_stop(buses_stops);
		}
		else if (command == "STOPS_FOR_BUS")
		{
			stops_for_bus(buses_stops);
		}
		else if (command == "ALL_BUSES")
		{
			all_buses(buses_stops);
		}
	}
	return 0;
}
