#include <iostream>
#include <string>

long long pallindrome ( const std::string& s );

int main() {
	std::ios::sync_with_stdio ( false );
	std::string s;
	std::cin >> s;

	std::cout << pallindrome ( s ) << std::endl;
}

long long pallindrome ( const std::string& s ) {
	long long count = 0;
	for ( int i = 1; i != 2 * s.size(); ++i ) {
		if ( i & 1 ) {
			int r = i >> 1;
			long long c = 1;
			while ( r - c != -1 && r + c != s.size() &&
					s[r - c] == s[r + c] ) ++c;
			count += c;

		}
		else {
			int r = i >> 1;
			long long c = 0;
			while ( r - c != -1 && r + c != s.size() &&
					s[r - 1 - c] == s[r + c] ) ++c;
			count += c;
		}
	}

	return count;
}