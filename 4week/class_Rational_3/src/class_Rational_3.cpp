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

bool operator==(const Rational& lhs, const Rational& rhs)
{
	if (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator())
		return true;
	else
		return false;
}

Rational operator+(const Rational& lhs, const Rational& rhs)
{
	Rational sum(lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator());
	return sum;
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
	Rational subst(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator());
	return subst;
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
	Rational mult(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
	return mult;
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
	Rational div(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
	return div;
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
