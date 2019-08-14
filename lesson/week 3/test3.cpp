#include <cstdio>
#include <cstdlib>
#include "Set.h"

long long abs ( long long a ) { return ( a < 0 ? -a : a ); }
bool check ( long long*,long long*, int, long long );
void cal ( long long*, long long*, int lo, int hi, Set<long long>&, long long );

int main() {
	int T;
	scanf ( "%d", &T );
	bool* result = new bool[T];
	for ( int i = 0; i != T; ++i ) {
		long long n,S;
		scanf ( "%lld%lld", &n, &S );
		long long* a = new long long[n];
		long long* b = new long long[n];
		for ( int i = 0; i != n; ++i )
			scanf ( "%lld", &a[i] );
		for ( int i = 0; i != n; ++i )
			scanf ( "%lld", &b[i] );

		result[i] = check ( a, b, n, S );
	}
	for ( int i = 0; i != T; ++i )
		printf ( "%d\n", result[i] );
}

bool check ( long long* a, long long* b, int n, long long S ) {
	Set<long long> s1, s2;
	cal ( a, b, 0, n >> 1, s1, 0 );
	cal ( a, b, n >> 1, n, s2, 0 );
	for ( int i = 0; i != s1.size(); ++i ) {
		if ( s2.inSet ( S - s1.data[i] ) )
			return true;
	}
	return false;
}

void cal ( long long* a, long long* b, int lo, int hi, Set<long long>& s, long long sum ) {
	if ( lo == hi ) {
		s.push ( sum );
	}
	else {
		cal ( a, b, lo + 1, hi, s, sum + a[lo] );
		cal ( a, b, lo + 1, hi, s, sum + b[lo] );
		cal ( a, b, lo + 1, hi, s, sum + a[lo] * b[lo] );
	}
}