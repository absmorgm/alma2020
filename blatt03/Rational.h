#include <stdexcept>

class Rational {
public:
    using IntType = long long;

    Rational(IntType n, IntType d): _numerator(n), _denominator(d) {
        if (d < 1) {
		    errorZero();
		}
		normalizeNominatorDenominator();
    }

    IntType numerator() const {
        return _numerator;
    }

    IntType denominator() const {
        return _denominator;
    }

	// addition
    Rational operator+(const Rational & other) const {
        return Rational(numerator() * other.denominator() + other.numerator() * denominator(),
                        denominator() * other.denominator());
    }

	// subtraction
	Rational operator-(const Rational & other) const {
		return Rational(numerator() * other.denominator() - other.numerator() * denominator(),
						denominator() * other.denominator());

	}

	// multiplication
	Rational operator*(const Rational & other) const {
		return Rational(numerator() * other.numerator(), denominator() * other.denominator());
	}

	// division
	Rational operator/(const Rational & other) const {
		return Rational(numerator() * other.denominator(), denominator() * other.numerator());
	}


    bool operator<(const Rational & other) const {
        return numerator() * other.denominator() < other.numerator() * denominator();
    }


	void normalizeNominatorDenominator() {
		IntType gcd = _findGreatestCommonDivisor(_numerator,_denominator);
		_numerator = _numerator / gcd;
		_denominator = _denominator / gcd;
	}

    void reciprocal() {
        if (numerator() == 0) {
            errorZero();
        }
		else {
            std::swap(_numerator, _denominator);
            if (denominator() < 0) {
                _numerator   = -_numerator;
                _denominator = -_denominator;
            }
        }
    }



private:
    IntType _numerator;
    IntType _denominator;

	void errorZero() {
        throw std::runtime_error("Denominator < 1 not allowed in Rational.");
    }

	IntType _findGreatestCommonDivisor(IntType a, IntType b) {
		IntType t = 0;
		while(b != 0) {
		    t = b;
            b = a % b;
			a = t;
		}
		return std::abs(a);
	}
};

//  Write Rational r to an output stream, e.g. to std::cout.
//  When this 'operator<<' is used first argument (here os)
//  is condisdered  the first (left hand side operand).
//  E.g. you can write a Rational to std::cout by calling:
//  std::cout << r;
inline std::ostream& operator<< (std::ostream& os, const Rational& r) {
   os << r.numerator() << "/" << r.denominator();
   return os;
}

