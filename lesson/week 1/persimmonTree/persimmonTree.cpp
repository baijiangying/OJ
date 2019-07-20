#include <iostream>
#include "Union-Find.h"

struct Edge {
	int u;
	int v;
	int weight;
};

void quickSort ( Edge*, int lo, int hi );
int getPivot ( Edge* path, int lo, int hi );

int main() {
	std::ios::sync_with_stdio ( false );
	int n, m, k;
	std::cin >> n >> m >> k;
	if ( n < k || m < ( n - k ) ) {
		std::cout << -1 << std::endl;
		return 0;
	}
	UnionFind u ( n + 1 );
	Edge* path = new Edge[m];
	for ( int i = 0; i != m; ++i ) {
		std::cin >> path[i].u >> path[i].v >> path[i].weight;
	}
	quickSort ( path, 0, m );

	int cost = 0;
	int edgeCount = 0;
	for ( int i = 0; i != m && edgeCount != ( n - k ); ++i ) {
		if ( u.find ( path[i].u ) != u.find ( path[i].v ) ) {
			u.unit ( path[i].u, path[i].v );
			cost += path[i].weight;
			++edgeCount;
		}
	}
	if ( edgeCount != ( n -k ) ) cost = -1;
	std::cout << cost << std::endl;
	return 0;
}

void quickSort ( Edge* path, int lo, int hi ) {
	if ( lo + 1 < hi ) {
		int pivot = getPivot ( path, lo, hi );
		quickSort ( path, lo, pivot );
		quickSort ( path, pivot + 1, hi );
	}
}	

int getPivot ( Edge* path, int lo, int hi ) {
	int pivot = lo;
	for ( int i = lo; i != hi ; ++i ) {
		if ( path[i].weight < path[pivot].weight ) {
			std::swap ( path[pivot], path[i] );
			std::swap ( path[++pivot], path[i] );
		}
	}

	return pivot;
}