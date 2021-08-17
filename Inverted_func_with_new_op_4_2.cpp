//============================================================================
// Name        : Inverted_func_with_new_op_4_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class FunctionPart
{
public:
	void AddPart(char new_operation, double new_value)
	{
		operation = new_operation;
		value = new_value;
	}
	double Apply(double return_value) const
	{
		if(operation == '+')
			return_value += value;
		else if(operation == '-')
			return_value -= value;
		else if(operation == '*')
			return_value *= value;
		else if(operation == '/')
			return_value /= value;
		return return_value;
	}
	void Invert()
	{
		if(operation == '+')
			operation = '-';
		else if (operation == '-')
			operation = '+';
		else if (operation == '/')
			operation = '*';
		else if (operation == '*')
			operation = '/';
	}

private:
	char operation;
	double value;
};

class Function
{
public:
	void AddPart (char new_operation, double value)
	{
		FunctionPart part;
		part.AddPart(new_operation,value);
		my_function.push_back(part);
	}
	double Apply (double value) const
	{
		for(auto& part : my_function)
			value = part.Apply(value);
		return value;
	}
	void Invert ()
	{
		for(auto& part : my_function)
			part.Invert();
		reverse(my_function.begin(),my_function.end());
	}
private:
	vector<FunctionPart> my_function;
};


struct Image {
  double quality;
  double freshness;
  double rating;
};

struct Params {
  double a;
  double b;
  double c;
};

Function MakeWeightFunction(const Params& params,
                            const Image& image) {
  Function function;
  function.AddPart('*', params.a);
  function.AddPart('-', image.freshness * params.b);
  function.AddPart('+', image.rating * params.c);
  return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}

int main() {
  Image image = {10, 2, 6};
  Params params = {4, 2, 6};
  cout << ComputeImageWeight(params, image) << endl;
  cout << ComputeQualityByWeight(params, image, 52) << endl;
  return 0;
}
