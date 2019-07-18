#include <iostream> 


inline int read ( char* c ) 
{ return ( *c - '0' ) * 10 + ( * ( c + 1 ) - '0' ); };

int main() {
	char time[18];
	std::cin.getline ( time, 18 );
	int phone = ( ( ( read ( time + 9 ) - read ( time ) +24 ) % 24
				* 60 + read ( time + 12 ) - read ( time + 3 ) ) * 60
				+ ( read ( time + 15 ) - read ( time + 6 ) ) );

	std::cout << phone << std::endl;
	return 0;
}

