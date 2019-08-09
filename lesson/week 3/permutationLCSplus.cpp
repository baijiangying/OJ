#include <cstdio>
#include <limits.h>

struct Rank {
	int rank[5];
	Rank() { for ( int i = 0; i !=5; ++i ) rank[i] = 0; }
	void insert ( int r ) { 
		for ( int i = 0; i != 5; ++i )
			if ( !rank[i] ) {
				rank[i] = r;
				break;
			} 
	}
};


int LCS ( int*, Rank*, int );
int LIS ( Rank*, int*, int, int );
int binSearch ( int*, int, int, int );

int main() {
	int n;
	scanf ( "%d", &n );
	int* A = new int[5 * n + 1];
	//int* B = new int[5 * n + 1];
	for ( int i = 1; i != 5 * n + 1; ++i ) scanf ( "%d", &A[i] );
	Rank* rankB = new Rank[n + 1];
	for ( int i = 1; i != 5 * n + 1; ++i ) {
		int n; scanf( "%d", &n );
		rankB[n].insert ( i );
	}
	
	printf ( "%d\n", LCS ( A, rankB, n ) );
	return 0;
}

int LCS ( int* A, Rank* rankB, int n ) {
	
		
	return LIS ( rankB, A, 1, 5 * n + 1 );
}

int LIS ( Rank* p, int* A, int lo, int hi ) {
	int n = ( hi - lo ) * 5;
	int* least = new int[n];
	for ( int i = 0; i != n; ++i ) 
		least[i] = INT_MAX;
	for ( int i = lo; i != hi; ++i ) 
		for ( int j = 4; j != -1; --j )
			least[binSearch ( least, 0, n, p[A[i]].rank[j] )] = p[A[i]].rank[j];
	int length = 0;
	while ( least[length] != INT_MAX ) ++length;
	
	return length;
}

int binSearch ( int* a, int lo, int hi, int n ) {
	while ( lo < hi ) {
		int mi = ( lo + hi ) >> 1;
		n <= a[mi] ? hi = mi : lo = mi + 1;
	}
	
	return lo;
}