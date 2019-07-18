#include <iostream>

int gcd ( int a, int b ) {
	int p = 1;
	if ( ! ( a & 1 ) && ! ( b & 1 ) ) 
		a >>= 1, b >>= 1, p <<= 1;

	while ( a != b ) 
		a > b ? a = a - b :  b = b - a;


	return p * a;
}

int main() {
	int a, b;
	std::cin >> a >> b;
	std::cout << gcd ( a, b ) << std::endl;
}

