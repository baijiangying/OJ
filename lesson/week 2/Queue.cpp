#include <cstdio>

int sterlingFirst ( int n, int m );

int main() {
	int n, m;
	scanf ( "%d%d", &n, &m );

	printf ( "%d\n", sterlingFirst ( n, m ) );
	return 0;
}

int sterlingFirst ( int n, int m ) {
	long long* result = new long long[n + 1];
	result[0] = 0;
	for ( int i = 1; i != n + 1; ++i ) {
		result[i] = 1;
		for ( int j = i - 1; j != 0; --j )
			result[j] = ( ( i - 1 ) * result[j] % 1000000007 + 
				result[j - 1] ) % 1000000007;
	} 

	return result[m];
}