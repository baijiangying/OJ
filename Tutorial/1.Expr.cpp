#include <iostream>

int main() {
	long long A = 0,B = 0;
	char op = '\0';
	std::cin >> A >> op >> B;

	switch ( op ) {
		case '+': std::cout << A + B << std::endl; break;
		case '-': std::cout << A - B << std::endl; break;
		case '*': std::cout << A * B << std::endl; break;
		default: break;
	}

	return 0;
}