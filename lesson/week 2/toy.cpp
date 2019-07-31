#include <cstdio>

int combination ( int, int );

int main() {
	int n,m;
	scanf ( "%d%d", &n, &m );
	printf ( "%d\n", combination ( n + m * m - 1, n ) );
}

int combination ( int n, int m ) {
	int* c = new int[n + 1];
	c[0] = 1;
	for ( int i = 1; i != n + 1; ++i ) {
		c[i] = 1;
		for ( int j = i - 1; j != 0; --j ) {
			c[j] = ( c[j] % 1000000007 + c[j - 1] % 1000000007 ) % 1000000007 ;
		}
	}
	return c[m];
}
