//============================================================================
// Name        : class_Rational_exception.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Rational {
public:
    Rational()
	{
    	numerator = 0;
    	denominator = 1;
	}

    Rational(int tmp_numerator, int tmp_denominator) {

    	if(tmp_denominator == 0)
    	{
    		string str = "";
    		throw invalid_argument(str);
    	}

    	if (tmp_numerator < 0 || tmp_denominator < 0)
    	{
    		if (tmp_numerator < 0 && tmp_denominator <0)
    		{
    			tmp_numerator *= (-1);
    			tmp_denominator *= (-1);
    		}
    		else
    		{
    			tmp_numerator = abs(tmp_numerator) * (-1);
    			tmp_denominator = abs(tmp_denominator);
    		}
    	}

    	if(abs(tmp_numerator) % abs(tmp_denominator) == 0)
    	    	{
    	    		tmp_numerator /=abs(tmp_denominator);
    	    		tmp_denominator /=abs(tmp_denominator);
    	    	}

    	int max = tmp_numerator > tmp_denominator ? tmp_numerator : tmp_denominator;
    	for(int i = 2; i < max / 2; i++)
    	{
    		if(tmp_numerator % i == 0 && tmp_denominator % i == 0)
    		{
    			tmp_numerator /= i;
    			tmp_denominator /= i;
    			i--;
    		}
    	}
    	numerator = tmp_numerator;
    	denominator = tmp_denominator;
    }

    int Numerator() const {
    	return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:
    int numerator;
    int denominator;
};

Rational operator/(const Rational& lhs, const Rational& rhs)
{
	if(rhs.Numerator() == 0)
	{
		string str = "";
		throw domain_error(str);
	}
	Rational div(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
	return div;
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
