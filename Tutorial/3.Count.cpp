#include <iostream>

const char Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
	char text[4097];
	std::cin.getline ( text, 4097 );

	int count[26];
	for ( auto& n : count ) n = 0;
	for ( int i = 0; ( i != 4097 ) && ( text[i] != '\0'); ++i ) 
		++count[tolower ( text[i] ) - 'a'];

	for ( int i = 0; i!= 26; ++i )
		if ( count[i] ) 
			std::cout << Alphabet[i] << ": "
					  << count[i] << std::endl;

	return 0;
}