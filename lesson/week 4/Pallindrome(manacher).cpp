#include <iostream>
#include <string>

long long pallindrome ( const std::string& );
std::string insertNull ( const std::string& );

int main() {
	std::ios_sync_with_stdio ( false );
	std::string s;
	std::cin >> s;

	std::cout << pallindrome ( s ) << std::endl;
}

long long pallindrome ( const std::string& s ) {
	std::string str = insertNull ( s );
	int maxRight = -1, pos = -1;
	

}

std::string insertNull ( const std::string& s ) {
	std::string str = "#";
	for ( int i = 0; i != s.size(); ++i ) 
		str = str + s[i] + "#";

	return str;
}