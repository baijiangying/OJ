#include <iostream>
#include "Union-Find.h"

struct Edge {
	int x;
	int y;
	int weight;
	int key;
	bool operator< ( Edge& );
};

bool Edge::operator< ( Edge& w ) {
	return ( weight == w.weight ? key > w.key : weight < w.weight );
}

int solve ( Edge*, int, int, int );
void quickSort ( Edge*, int, int );
int getPivot ( Edge*, int, int );

int main() {
	std::ios::sync_with_stdio ( false );
	int n, m, k;
	std::cin >> n >> m >> k;
	Edge* edge = new Edge[m];
	for ( int i = 0; i != m; ++i ) 
		std::cin >> edge[i].x >> edge[i].y
		>> edge[i].weight >> edge[i].key;
	std::cout << solve ( edge, n, m, k ) << std::endl;
	return 0;
}

int solve ( Edge* edge, int n, int m, int k ) {
	int hi = -1;
	for ( int i = 0; i != m; ++i )
		if ( edge[i].weight > hi ) hi = edge[i].weight;
	int lo = -hi, result = 0;
	while ( lo <= hi ) {
		int mi = ( hi + lo ) >> 1;
		Edge* e = new Edge[m];
		for ( int i = 0; i != m; ++i ) {
			e[i] = edge[i];
			if ( edge[i].key )
				e[i].weight += mi;
		}
		quickSort ( e, 0, m );
		UnionFind u ( n + 1 );
		int kE = 0;
		int sum = 0;
		for ( int i = 0, c = 0; i != m && c != n - 1; ++i ) {
			if ( u.find ( e[i].x ) != u.find ( e[i].y ) ) {
				u.unit ( e[i].x, e[i].y ); ++c;
				sum += e[i].weight;
				if ( e[i].key ) ++kE;
			}
		}
		kE >= k ? lo = mi + 1, result = sum - k * mi : hi = mi - 1;
	}
	return result;	
}

void quickSort ( Edge* e, int lo, int hi ) {
	if ( lo + 1 >= hi ) return;
	int pivot = getPivot ( e, lo, hi );
	quickSort ( e, lo, pivot );
	quickSort ( e, pivot + 1, hi );
}

int getPivot ( Edge* e, int lo, int hi ) {
	int pivot = lo;
	for ( int i = lo + 1; i != hi; ++i ) 
		if ( e[i] < e[pivot] ) {
			std::swap ( e[i], e[pivot++] );
			std::swap ( e[i], e[pivot] );
		}
	return pivot;
}