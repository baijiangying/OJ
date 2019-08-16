#include <cstdio>
#include <cstring>
//待修改
void match ( char const*, int, char const*, int );
int* bulidNext ( char const*, int );

int main() {
	int n, m;
	scanf ( "%d", &n );
	char* A = new char[n];
	scanf ( "%s", A );
	scanf ( "%d", &m );
	char* B = new char[m];
	scanf ( "%s", B );

	match ( A, n, B, m );
	return 0;
}

void match ( char const* A, int n, char const* B, int m ) {
	int i = 0, j = 0;
	int* next = bulidNext ( B, m );
	while ( i != n ) {
		if ( j == - 1 || A[i] == B[j] ) {
			++i, ++j;
			if ( j == m ) {
				printf ( "%d\n", i - j );
				j = next[j];
			}
		}
		else j = next[j];
	}
}

int* bulidNext ( char const* s, int n ) {
	int* next = new int[n + 1]; next[0] = -1;
	int j = -1;
	for ( int i = 1; i != n + 1; ++i ) {
		while ( j != -1 && s[j] != s[i] ) j = next[j];
		next[i] = next[j] + 1;
	}

	return next;
}

