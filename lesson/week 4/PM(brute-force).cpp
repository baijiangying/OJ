#include <iostream>
#include <string>

void match ( const std::string&, const std::string& );

int main() {
	std::string A, B;
	int n;
	std::cin >> n >> A >> n >> B;

	match ( A, B );
}

void match ( const std::string& A, const std::string& B ) {
	for ( int i = 0; i != A.size() - B.size() + 1; ++i ) {
		int j = 0;
		while ( j != B.size() && A[i + j] == B[j] ) ++j;
		if ( j == B.size() ) std::cout << i << std::endl;
	}
}