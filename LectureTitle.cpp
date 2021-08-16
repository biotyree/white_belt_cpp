//============================================================================
// Name        : LectureTitle.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

struct Specialization{
	string value;
	explicit Specialization(const string& new_value)
	{
		value = new_value;
	}
};

struct Course{
	string value;
	explicit Course(const string& new_value)
	{
		value = new_value;
	}
};

struct Week{
	string value;
	explicit Week(const string& new_value)
	{
		value = new_value;
	}
};

struct LectureTitle {
  string specialization;
  string course;
  string week;

  LectureTitle(Specialization new_spec, Course new_cour, Week new_week)
  {
	  specialization = new_spec.value;
	  course = new_cour.value;
	  week = new_week.value;
  }
};

int main() {

	return 0;
}
