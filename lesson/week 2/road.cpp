#include <cstdio>

#define P 1000000007

inline long long sqr ( long long n ) {
	n = ( n * n ) % P;
	return n;
} 

long long exp ( int, int );

int calculate ( int );

int main() {
	int n;
	scanf ( "%d", &n );

	printf ( "%d\n", calculate ( n ) );
	return 0;
}

int calculate ( int n ) {
	if ( n ) {
		return ( n & 1 ? 
		( exp ( 3, n + 1 ) + ( P - exp ( 2, n + 1 ) ) ) % P :
		( exp ( 3, n + 1 ) + exp ( 2, n + 1 ) ) % P );
	}
	return n;
}

long long exp ( int base, int e ) {
	if ( e == 1 ) return base;
	if ( !e ) return 1;
	return ( e & 1 ? 
		base * sqr ( exp ( base, e >> 1 ) ) % P :
		sqr ( exp ( base, e >> 1) ) % P );
}
