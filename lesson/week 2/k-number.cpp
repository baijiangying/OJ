#include <iostream>

int kMin ( long long*, int, int );
int getPivot ( long long*, int , int );

int main() {
	std::ios::sync_with_stdio ( false );
	long long n, k, a, p, q, M;
	std::cin >> n >> k >> a >> p >> q >> M;
	long long* s = new long long[n];
	s[0] = a;
	for ( int i = 1; i != n; ++i ) 
		s[i] = ( p * s[i - 1] + q ) % M;
	std::cout << kMin ( s, n, k - 1 ) << std::endl;

}

int getPivot ( long long* s, int lo, int hi ) {
	int pivot = lo;
	int r = lo + rand() % ( hi - lo );
	std::swap ( s[pivot], s[r] );
	for ( int i = lo + 1; i != hi; ++i )
		if ( s[i] < s[pivot] ) {
			std::swap ( s[i], s[pivot++] );
			std::swap ( s[i], s[pivot] );
		}
	return pivot;

}

int kMin ( long long* s, int n, int k ) {
	int rank = getPivot ( s, 0, n );
	int lo = 0, hi = n;
	while ( rank != k ) {
		if ( rank > k ) {
			while ( s[rank] == s[rank - 1] ){
				--rank;
				if ( rank == k )
					return s[rank];
			}
			hi = rank;
			rank = getPivot ( s, lo, hi );
		}
		else {
			while ( s[rank] == s[rank + 1] ){
				++rank;
				if ( rank == k )
					return s[rank];
			}
			lo = rank + 1;
			rank = getPivot ( s, lo, hi );
		}
	}
	return s[rank];
}