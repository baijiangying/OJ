#include <cstdio>
#include <iostream>

int solve ( int*, int, int );
bool check ( int*, int, int, long long );

int main() {
	int n, m;
	scanf ( "%d%d", &n, &m );
	int* a = new int[n];
	for ( int i = 0; i != n; ++i )
		scanf ( "%d", &a[i] );

	printf ( "%d\n", solve ( a, n, m ) );
	return 0;
}

int solve ( int* a, int n, int m ) {
	long long lo = 0, hi = 0;
	for ( int i = 0; i != n; ++i ) hi += a[i];
	long long mi = ( lo + hi ) >> 1;
	while ( lo < hi ) {
		check ( a, n, m, mi ) ? hi = mi : lo = mi + 1;
		mi = ( lo + hi ) >> 1;
	}
	return hi;
}

bool check ( int* a, int n, int m, long long mi ) {
	long long sum = 0, g = 0;
	for ( int i = 0; i != n; ++i ) {
		if ( a[i] > mi ) 
			return false;
		sum += a[i];
		if ( sum > mi )
			++g, sum = a[i];
	}
	return ( ++g <= m );
}