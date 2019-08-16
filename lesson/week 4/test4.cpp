#include <iostream>
#include <string>

int solve ( const std::string&, std::string*, int );
bool check ( const std::string&, int, const std::string& );

int main() {
	std::ios::sync_with_stdio ( false );
	std::string S; std::cin >> S;
	int n; std::cin >> n;
	std::string* s = new std::string[n];
	for ( int i = 0; i != n; ++i ) std::cin >> s[i];

	std::cout << solve ( S, s, n ) << std::endl;
}

int solve ( const std::string& S, std::string* s, int n ) {
	int* result = new int[S.size() + 1]; result[0] = 1;
	for ( int i = 1; i != S.size() + 1; ++i ) result[i] = 0;
	for ( int i = 1; i != S.size() + 1; ++i ) {
		for ( int j = 0; j != n; ++j )
			if ( check ( S, i, s[j] ) )  
				result[i] = 
				( result[i] + result[i - s[j].size()] ) % 23333;
	}

	return result[S.size()];
}

bool check ( const std::string& S, int n, const std::string& s ) {
	if ( n - s.size() >= 0 ) {
		int i = 1;
		while ( i != s.size() + 1 && S[n - i] == s[s.size() - i] ) ++i;
		if ( i == s.size() + 1 ) return true;
	}

	return false;
}