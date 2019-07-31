#include <cstdio>
#include "Union-Find.h"

struct Edge {
	int x;
	int y;
	int weight;
};


void solve ( Edge*, int, int );


int main() {
	int n, m;
	scanf ( "%d%d", &n, &m );
	Edge* edge = new Edge[m];
	for ( int i = 0; i != m; ++i ) {
		scanf ( "%d%d", &edge[i].x, &edge[i].y );
		edge[i].weight = i + 1;
	}
	solve ( edge, n, m );

	return 0;
}

void solve ( Edge* e, int n, int m ) {
	int c = 0;
	Edge* result = new Edge[n - 1];
	UnionFind u ( n + 1 ); 
	for ( int i = m - 1; i != -1 && c != n - 1; --i ) {
		if ( u.find ( e[i].x ) != u.find ( e[i].y ) ) {
			u.unit ( e[i].x, e[i].y );
			result[c] = e[i];
			++c;
		}
	}
	printf ( "%d\n", c );
	while ( 0 < c-- )
		printf ( "%d\n", result[c].weight );
}
