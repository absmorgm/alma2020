#include <iostream>
#include "Rational.h"

int main() {
		using IntType = long long;

		IntType a, b, c, d;

		std::cout << "Input a: ";
		std::cin >> a;
		std::cout << std::endl;

		std::cout << "Input b: ";
		std::cin >> b;
		std::cout << std::endl;

		std::cout << "Input c: ";
		std::cin >> c;
		std::cout << std::endl;

		std::cout << "Input d: ";
		std::cin >> d;
		std::cout << std::endl;

		try {
		    Rational p = Rational(a, b);
		    Rational q = Rational(c, d);

			std::cout << "a + b: " << p + q << std::endl;
			std::cout << "a - b: " << p - q << std::endl;
			std::cout << "a * b: " << p * q << std::endl;
			std::cout << "a / b: " << p / q << std::endl;
		}
		catch(const std::exception& e) {
			std::cout << "There was an error creating the rationals" << std::endl;
			std::cout << e.what();
		}

		return 0;

}
