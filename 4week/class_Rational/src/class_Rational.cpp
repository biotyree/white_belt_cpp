#include <iostream>
#include <algorithm>
using namespace std;

class Rational {
public:
    Rational()
	{
    	numerator = 0;
    	denominator = 1;
	}

    Rational(int tmp_numerator, int tmp_denominator) {
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

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}
