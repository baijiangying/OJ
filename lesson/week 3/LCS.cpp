#include <cstdio>

int LCS ( int*, int, int*, int );

int main() {
	int n;
	scanf ( "%d", &n );
	int* a = new int[n];
	int* b = new int[n];
	for ( int i = 0; i != n; ++i ) scanf ( "%d", &a[i] );
	for ( int i = 0; i != n; ++i ) scanf ( "%d", &b[i] );

	printf ( "%d\n", LCS ( a, n, b, n ) );
}

int LCS ( int* a, int n, int* b, int m ) {
	int* table[2];
	for ( int i = 0; i != 2; ++i ) {
		table[i] = new int[m];
		for ( int j = 0; j != m; ++j )
			table[i][j] = 0;
	}
	table[0][0] = ( a[0] == b[0] );
	for ( int i = 1; i != m; ++i )
		table[0][i] = ( a[0] == b[i] || table[0][i - 1] );
	for ( int i = 1; i != n; ++i ) {
		table[i & 1][0] = ( a[i] == b[0] );
		for ( int j = 1; j != m; ++j ) {
			if ( a[i] == b[j] )
				table[i & 1][j] = table[( i - 1 ) & 1][j - 1] + 1;
			if ( table[( i - 1 ) & 1][j] > table[i & 1][j] )
				table[i & 1][j] = table[( i - 1 ) & 1][j];
			if ( table[i & 1][j - 1] > table[i & 1][j] )
				table[i & 1][j] = table[i & 1][j - 1];
		}
	}

	return table[( n - 1 ) & 1][m - 1];
}

