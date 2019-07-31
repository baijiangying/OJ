#include <cstdio>

int caculate ( int );
long long exp ( int, int );
long long sqr ( long long a) { return a * a;}

int main() {
	int n;
	scanf ( "%d", &n );

	printf ( "%d\n", caculate ( n ) );
	return 0;
}

long long exp ( int base, int e ) {
	if ( e == 1 ) return base;
	if ( e == 0 ) return 1;
	return ( e & 1 ? 
	sqr ( exp ( base, e >> 1 ) % 1000000007 ) *  
	base % 1000000007 :
	sqr ( exp ( base, e >> 1 ) % 1000000007 ) % 1000000007 );
}

int caculate ( int n ) {
	return (  ( exp ( 4, n - 1 ) % 1000000007 +
		exp ( 2, n - 1 ) % 1000000007 ) %
		1000000007 );
}