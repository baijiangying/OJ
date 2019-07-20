#include <iostream>
#include "Union-Find.h"

struct Edge {
	int u;
	int v;
	int weight;
};

void sort ( Edge*, int size );

int main() {
	std::ios::sync_with_stdio ( false );
	int n, m, k;
	std::cin >> n >> m >> k;
	UnionFind u ( n + 1 );
	Edge* path = new Edge[m];
	for ( int i = 0; i != m; ++i ) {
		std::cin >> path[i].u >> path[i].v >> path[i].weight;
	}
	sort ( path, m );
	int cost = 0;
	for ( int i = 0; i != ( n - k ); ++i ) {
		if ( u.find ( path[i].u ) != u.find ( path[i].v ) )
			u.unit ( path[i].u, path[i].v ), cost += path[i].weight;
	}
	std::cout << cost << std::endl;
	return 0;
}

void sort ( Edge* path, int size ) {
	for ( int i = 1; i != size; ++i ) {
		for ( int j = i; j != 0; --j ) {
			if ( path[j].weight < path[j - 1].weight) {
				std::swap ( path[j], path[j - 1] );
			}

		}
	}
}	