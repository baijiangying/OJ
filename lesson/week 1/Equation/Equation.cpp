#include <iostream>
#include <stdlib.h>

#include "Union-Find.h"

int main() {
	std::ios::sync_with_stdio ( false );
	int t, n, m;
	std::cin >> t;
	bool* result = new bool[t];
	for ( int i = 0; i != t; ++i ) result[i] = true;
	for ( int k = 0; k != t; ++k ) {
		std::cin >> n >> m;
		UnionFind u ( n + 1 );
		int array[2 * n];
		int count = 0;
		for ( int i = 0; i != m; ++i ) {
			int x, y, z;
			std::cin >> x >> y >> z;
			if ( z ) u.unit ( x, y );
			else { array[count++] = x; array[count++] = y; }
		}
		for ( int i = 0; i < count; i += 2 ) 
			if ( u.find ( array[i] ) == u.find ( array[i + 1] ) ) {
				result[k] = false;
				break;
			}
	}
	for ( int i = 0; i != t; ++i )
		std::cout << ( result[i] ? "Yes" : "No" ) << std::endl;
	return 0;
}