#include <iostream>
#include <fstream>
#include <string>

char table[5][10] = {
	{ '0','1','2','3','4','5','6','7','8','9' },
	{ ')','!','@','#','$','%','^','&','*','(' },
	{ 'p','q','w','e','r','t','y','u','i','o' },
	{ ';','a','s','d','f','g','h','j','k','l' },
	{ '/','z','x','c','v','b','n','m',',','.' }
};
std::string fTable[5] = {
	".-.....-..-.....-..-..-..-..-.",
	"|.|..|..|..||.||..|....||.||.|",
	".......-..-..-..-..-.....-..-.",
	"|.|..||....|..|..||.|..||.|..|",
	".-.....-..-.....-..-.....-..-."
};



void print ( const std::string s );

int main() {
	std::ios::sync_with_stdio ( false );
	
	int n = 0;
	std::cin >> n;
	std::string* text = new std::string[n];
	for ( int i = 0; i != n; ++i )
		std::cin >> text[i];
	for ( int i = 0; i != n; ++i )
		if ( text[i].size() )  print ( text[i] ); 

	return 0;
}

void print( const std::string s ) {
	bool hasF = false;
	for ( int i = 1; i < s.size(); i += 2 )
		if ( s[i] == 'f' )
			hasF = true;
	if ( hasF ) {
		for ( int row = 0; row != 5; ++row ) {
			for ( int i = 1; i < s.size(); i += 2 )
				if ( s[i] != 'f' )
					std::cout << ( row == 4 ? table[s[i] - 'a'][s[i-1] - '0'] : '.' );
				else {
					int r = ( s[i - 1] - '0' ) * 3;
					std::cout << fTable[row][r] 
					<< fTable[row][r + 1] << fTable[row][r + 2];
				}
			std::cout << std::endl;
		}
	}
	else {
		for ( int i = 1; i < s.size(); i += 2 ) 
			std::cout << table[s[i] - 'a'][s[i-1] - '0'];
		std::cout << std::endl;
	}
}