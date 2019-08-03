#include <cstdio>
#include <iostream>
#include <limits.h>
int min[300000], max[300000];
int minNum ( const int& a, const int& b ) { return ( a > b ? b : a ); }
int minNum ( const int& a, const int& b, const int& c ) { return minNum ( minNum ( a, b ), c ); }
int maxNum ( const int& a, const int& b ) { return ( a > b ? a : b ); }
int maxNum ( const int& a, const int& b, const int& c ) { return maxNum ( maxNum ( a, b ), c ); }
long long sequenceCount ( int*, int, int, int );

int main() {
	int n, d;
	scanf ( "%d%d", &n, &d );
	int* a = new int[n];
	for ( int i = 0; i != n; ++i ) scanf ( "%d", &a[i] );

	printf ( "%lld\n", sequenceCount ( a, 0, n, d ) );
	return 0;
}

long long sequenceCount ( int* a, int lo, int hi, int d ) {
	if ( lo + 1 < hi ) {
		long long result = 0;
		int mi = lo + ( ( hi - lo ) >> 1 );
		long long l = sequenceCount ( a, lo, mi, d );
		long long r = sequenceCount ( a, mi, hi, d );
		max[mi] = a[mi]; min[mi] = a[mi];
		for ( int i = mi + 1; i != hi; ++i ) {
			max[i] = ( a[i] > max[i - 1] ? a[i] : max[i - 1] );
			min[i] = ( a[i] < min[i - 1] ? a[i] : min[i - 1] );
		}
		int M = INT_MIN, m = INT_MAX;
		--hi;
		for ( int i = mi - 1; i != lo - 1; --i ) {
			M = maxNum ( a[i], M ); m = minNum ( a[i], m );
			while ( hi != mi - 1 && maxNum ( max[hi], M) - minNum ( m, min[hi]) > d ) --hi;
			if ( hi == mi - 1 ) break;
			result += hi - mi + 1;
		}
		return result + l + r;
	}
	else return 0;
}


