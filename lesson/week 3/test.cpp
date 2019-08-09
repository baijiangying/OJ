#include <iostream>

bool sigbit ( long long a ) { return a >= 0; }

long long abs ( long long a ) { return ( a < 0 ? -a : a ); }
int main() {
	long long S = -9223372036854775808;
	long long s = -9223372032559808512;
	long long b = 4294967296;
	std::cout << ( sigbit ( s ) == sigbit ( b ) ) << std::endl;
	std::cout << ( ( s - b) == S ) << std::endl;
}