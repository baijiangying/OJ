#include <cstdio>

template <typename T> T max ( const T& a, const T& b ) {
	return ( a > b ? a : b );
}

void solve ( int*, int*, int, int*, int*, int );

int main() {
	int n;
	scanf ( "%d", &n );
	int* value = new int[n + 1];
	int* volume = new int[n + 1];
	for ( int i = 1; i != n + 1; ++i ) 
		scanf ( "%d%d", &volume[i], &value[i] );
	int q; scanf ( "%d", &q );
	int* query = new int[q];
	int* queryV = new int[q];
	for ( int i = 0; i != q; ++i ) {
		scanf ( "%d%d", &queryV[i], &query[i] );
	}

	solve ( value, volume, n, query, queryV, q );
	return 0;
}

void solve ( int* value, int* volume, int n, int* query, int* queryV, int q ) {
	int size = 0; 
	for ( int i = 1; i != n + 1; ++i ) size += volume[i];
	size = ( size < 5000 ? ++size : 5001 );
	int** prefix = new int*[n + 1];
	for ( int i = 0; i != n + 1; ++i ) {
		prefix[i] = new int[size];
		for ( int j = 0; j != size; ++j )
			prefix[i][j] = 0;
	}
	int** postfix = new int*[n + 2];
	for ( int i = 0; i != n + 2; ++i ) {
		postfix[i] = new int[size];
		for ( int j = 0; j != size; ++j )
			postfix[i][j] = 0;
	} 
	for ( int i = 1; i != n + 1; ++i ) {
		for ( int j = 1; j != size; ++j ) 
			prefix[i][j] = max ( prefix[i - 1][j],
				( j - volume[i] >= 0 ?
				prefix[i - 1][j - volume[i]] + value[i] : 0 ) );
	}
	for ( int i = n; i != 0; --i ) {
		for ( int j = 1; j != size; ++j ) 
			postfix[i][j] = max ( postfix[i + 1][j],
				( j - volume[i] >= 0 ?
				postfix[i + 1][j - volume[i]] + value[i] : 0 ) );
	}
	for ( int i = 0; i != q; ++i ) {
		int v = queryV[i], x = query[i];
		int result = 0;
		for ( int j = 0; j != v + 1; ++j ) {
			result = max ( result, prefix[x - 1][j] + postfix[x + 1][v - j] );
		}
		printf ( "%d\n", result );
	}
}