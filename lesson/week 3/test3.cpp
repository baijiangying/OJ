#include <cstdio>
#include <set>
#include <iostream>

#define P 1e17

bool sigbit ( long long a ) { return a >= 0; }

long long abs ( long long a ) { return ( a < 0 ? -a : a ); }
bool check ( long long*,long long*, int, long long );
void cal ( long long*, long long*, int lo, int hi, std::set<long long>& );

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
	std::set<long long> s1, s2;
	cal ( a, b, 0, n >> 1, s1 );
	cal ( a, b, n >> 1, n, s2 );
	for ( auto n : s1 ) {
		if ( S < P && S > -P && s2.find ( S - n ) != s2.end() )
			return true;
	}
	return false;
}

void cal ( long long* a, long long* b, int lo, int hi, std::set<long long>& s ) {
	if ( lo + 1 < hi ) {
		int mi = ( lo + hi ) >> 1;
		std::set<long long> s1;
		cal ( a, b, lo, mi, s1 );
		std::set<long long> s2;
		cal ( a, b, mi, hi, s2 );
		for ( auto n : s1 ) 
			for ( auto m : s2 )
				s.insert ( n + m );
	}
	else {
		s.insert ( a[lo] );
		s.insert ( b[lo] );
		s.insert ( a[lo] * b[lo] );
	}
}