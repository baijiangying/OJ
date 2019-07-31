#include <cstdio>

int solve ( int**, int );
int max ( int, int );

int main() {
	int n;
	scanf ( "%d", &n );
	int** input = new int*[n];
	for ( int i = 0; i != n; ++i ) {
		input[i] = new int[n];
		for ( int j = 0; j != n; ++j )
			input[i][j] = 0;
	}
	for ( int i = 0; i != n; ++i ) {
		for ( int j = 0; j != i + 1; ++j ) {
			scanf ( "%d", &input[i][j] );
		}
	}
	printf ( "%d\n", solve ( input, n ) );
}

int solve ( int** input, int n ) {
	int result = 0;
	for ( int i = 1; i != n; ++i ) {
		input[i][0] += input[i - 1][0];
		for ( int j = 1; j != i + 1; ++j ) 
			input[i][j] += 
			max ( input[i - 1][j], input[i - 1][j - 1] );
	}
	for ( int i = 0; i != n; ++i ) 
		result =  max ( result, input[n - 1][i] );

	return result;
}

int max ( int a, int b ) {
	return ( a > b ? a : b );
}