#include <cstdio>
#include "Heap.h"

class Edge {
public:
	int weight;
	int u, v;
	Edge* next;
	Edge ( int s = -1, int t = -1, int w = 0, Edge* n = nullptr ) :
	u ( s ), t ( v ), weight ( w ), next ( n ) {};
}


int main() {
	int n, m, S, T;
	scanf ( "%d%d%d%d", &n, &m, &S, &T );
	Edge* vertex = new Edge[n + 1];
	for ( int i = 0; i != n + 1; ++i ) vertex[i] = nullptr;
	for ( int i = 0; i != m; ++i ){
		int u, v, w;
		scanf ( "%d%d%d", &u, &v, &w );
		insert ( u, v, w, vertex );
	}

	std::cout << solve ( vertex, n + 1 ) << std::endl;
	return 0;
}