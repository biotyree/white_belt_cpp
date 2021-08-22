#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>
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

ostream& operator<<(ostream& stream, Rational value)
{
	stream << value.Numerator() << "/" << value.Denominator();
	return stream;
}

istream& operator>>(istream& stream, Rational& value)
{
	if(stream)
	{
		int N, D;
		char symb;

		if(stream >> N && stream >> symb && stream >> D && symb == '/')
		{
			Rational new_value(N, D);
			value = new_value;
		}
	}
	return stream;
}

bool operator<(const Rational& lhs, const Rational& rhs)
{
	return (lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator());
}

bool operator>(const Rational& lhs, const Rational& rhs)
{
	return (lhs.Numerator() * rhs.Denominator() > rhs.Numerator() * lhs.Denominator());
}


int main() {

	map<Rational, string> name;
	name[Rational(1, 2)] = "одна вторая";

    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}

