#include <string>
#include <iostream>
#include "Trie.h"

int main() {
	std::ios::sync_with_stdio ( false );
	Trie trie;
	std::string s;
	int n, m;
	std::cin >> n >> m;
	for ( int i = 0; i != n; ++i ) {
		std::cin >> s;
		trie.insert ( s );
	}
	int* result =  new int[m];
	for ( int i = 0; i != m; ++i ) {
		std::cin >> s;
		Node* p = trie.find ( s );
		//std::cout << p -> parent -> c << std::endl;
		result[i] = ( p ? p -> parent -> size : 0 );
	}

	for ( int i = 0; i != m; ++i ) std::cout << result[i] << std::endl;
	return 0;
}