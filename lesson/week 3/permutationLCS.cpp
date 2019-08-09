#include <cstdio>
#include <limits.h>

int LCS ( int*, int*, int );
int LIS ( int*, int, int );
int max ( int a, int b ) { return ( a > b ) ? a : b; }
int max ( int a, int b, int c ) { return max ( a, max ( b, c ) ); }
int binSearch ( int*, int, int, int );

int main() {
	int n;
	scanf ( "%d", &n );
	int* A = new int[n + 1];
	int* B = new int[n + 1];
	for ( int i = 1; i != n + 1; ++i ) scanf ( "%d", &A[i] );
	for ( int i = 1; i != n + 1; ++i ) scanf ( "%d", &B[i] );

	printf ( "%d\n", LCS ( A, B, n ) );
	return 0;
}

int LCS ( int* A, int* B, int n ) {
	int* rank = new int[n + 1];
	for ( int i = 1; i != n + 1; ++i ) 
		rank[B[i]] = i;
	for ( int i = 1; i != n + 1; ++i )
		A[i] = rank[A[i]];
	
	delete[] rank;
	return LIS ( A, 1, n + 1 );
}

int LIS ( int* a, int lo, int hi ) {
	int* least = new int[hi - lo];
	for ( int i = 0; i != hi - lo; ++i ) 
		least[i] = INT_MAX;
	for ( int i = lo; i != hi; ++i ) 
		least[binSearch ( least, 0, hi - lo, a[i] )] = a[i];
	int length = 0;
	while ( least[length] != INT_MAX ) ++length;
	return length;
}

int binSearch ( int* a, int lo, int hi, int n ) {
	while ( lo < hi ) {
		int mi = ( lo + hi ) >> 1;
		n < a[mi] ? hi = mi : lo = mi + 1;
	}
	
	return lo;
}