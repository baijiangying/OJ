#include <cstdio>

#define P1 19260817
#define P2 19951031

void match ( char*, int, char*, int );
long long hash ( long long*, int, long long );
long long* hash ( long long*, int, int, long long );

int main() {
	int n; scanf ( "%d", &n );
	char* A = new char[n];
	scanf ( "%s", A );
	int m; scanf ( "%d", &m );
	char* B = new char[m];
	scanf ( "%s", B );

	match ( A, n, B, m ); 
	return 0;
}

void match ( char* A, int n, char* B, int m ) {
	long long* a = new long long[n];
	for ( int i = 0; i != n; ++i ) a[i] = A[i] - 'a' + 1;
	long long* b = new long long[m];
	for ( int i = 0; i != m; ++i ) b[i] = B[i] - 'a' + 1;

	long long hashB1 = hash ( b, m, P1 ), hashB2 = hash ( b, m, P2 );
	long long* h1 = hash ( a, n, m, P1 );
	long long* h2 = hash ( a, n, m, P2 );
	for ( int i = 0; i != n - m + 1; ++i ) {
		if ( h1[i] == hashB1 && h2[i] == hashB2 )
			printf ( "%d\n", i );
	}
	delete[] h1;
	delete[] h2;
	delete[] a;
	delete[] b;
}

long long hash ( long long* b, int m, long long mo ) {
	long long h = b[0];
	for ( int i = 1; i != m; ++i )
		h = ( h * 43 % mo + b[i] ) % mo;

	return h;
}

long long* hash ( long long* a, int n, int m, long long mo ) {
	int exp = 1;
	for ( int i = 0; i != m; ++i ) exp = exp * 43 % mo;
	long long* h = new long long[n -m + 1];
	h[0] = hash ( a, m, mo );
	for ( int i = 1; i != n - m + 1; ++i ) {
		h[i] = ( 43 * h[i - 1] % mo + a[i + m - 1] - ( a[i - 1] * exp ) % mo + mo )
				% mo;
	}

	return h;
}
