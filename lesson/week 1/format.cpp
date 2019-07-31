#include <iostream>
#include <string>

int readNum ( std::string, int );
int exp ( int, int );

int main() {
	std::ios::sync_with_stdio ( false );
	std::string s1, s2;
	std::cin >> s1 >> s2;
	if ( s1[0] == '%' ) {
		int a = ( s1[1] == '-' ? 
			-readNum ( s1, 2 ) : readNum ( s1, 1 ) );
		int i = 1;
		while ( s1[i++] != '.' );
		int b = readNum ( s1, i );
		if ( a > 0 ) {
			int i = -1;
			while ( s2[++i] == '*' ); 
			while ( isdigit ( s2[i++] ) ); --i;
			if ( s2[i] == '.' ) {
				int c = 0;
				while ( ++i != s2.size() && isdigit ( s2[i] ) ) 
					++c;
				if ( c == b && i == a ) {
					std::cout << "YES" << std::endl;
					return 0;
				}
				else if ( c == b && s2[0] != '*' && i > a ) {
					std::cout << "YES" << std::endl;
					return 0;
				}
			}
		}
		else if ( a < 0 ) {
			a = -a;
			int i = -1;
			while ( isdigit ( s2[++i] ) );
			if ( s2[i] == '.' ) {
				int c = 0;
				while ( ++i != s2.size() && isdigit ( s2[i] ) )
					++c;
				if ( c == b ) {
					if ( i == s2.size() ) {
						std::cout << "YES" << std::endl;
						return 0;
					} 
					else {
						while ( i != s2.size() && s2[i++] == '*' );
						if ( i == s2.size() && i == a ) {
							std::cout << "YES" << std::endl;
							return 0;
						}
					}
				}
			}
		}
		else {
			std::cout << "YES" << std::endl;
			return 0;
		}
	}
	std::cout << "NO" << std::endl;
	return 0;
}

int exp ( int base, int expo) {
	if ( expo == 1 ) return base;
	if ( expo == 0 ) return 1; 
	return ( expo ? exp ( base, expo >> 1) * exp ( base, expo >> 1) * base 
		: exp ( base, expo >> 1) * exp ( base, expo >> 1 ) ); 
}

int readNum ( std::string s, int start ) {
	int num[100], i = 0;
	while ( isdigit ( s[start] ) ) 
		num[i++] = ( s[start++] - '0' );
	int result = 0;
	for ( int j = 0; j != i; ++j ) 
		result += ( num [i - j - 1] * exp ( 10, j ) );
	return result; 
}