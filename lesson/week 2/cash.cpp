#include <cstdio>
#include <iostream>

int cash ( int*, int, int );

int main() {
	int n, v;
	scanf ( "%d%d", &n, &v );
	int* coin = new int[n];
	for ( int i = 0; i != n; ++i ) 
		scanf ( "%d", &coin[i] );

	printf ( "%d\n", cash ( coin, n, v ) );
}

int cash ( int* coin, int n, int v ) {
	int sum = 0;
	for ( int i = 0; i != n; ++i )
		sum += coin[i];
	if ( v > sum ) return 0;
	if ( v == sum ) return 1;
	int* result = new int[sum + 1];
	for ( int i = 0; i != sum + 1; ++i ) result[i] = 0;
	result[0] = 1;
	int max = 0;
	for ( int i = 0; i != n; ++i ) {
		int* tmp = new int[max + 1];
		for ( int j = 0; j != max + 1; ++j )
			tmp[j] = result[j];
		for ( int j = 0; j != max + 1; ++j )
			if ( tmp[j] ) {
				result[j + coin[i]] += tmp[j];
			}
		delete[] tmp;
		max += coin[i];
	}
	return result[v];
}