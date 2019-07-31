#include <cstdio>
#include <iostream>
#include <stdlib.h>

int divide ( int*, int, int );

int main() {
	srand( time ( nullptr ) );
	while (1){
	int n = rand() % 3000, m = rand() % 3000;
	printf ( "%d%c%d%c", n, ' ', m, ' ' );
	//scanf ( "%d%d", &n, &m );
	int* a = new int[n];
	for ( int i = 0; i != n; ++i ) a[i] = rand() % 10000;
	printf ( "%d\n", divide ( a, n, m ) );
	delete a;
	}
}

int divide ( int* a, int n, int m ) {
	std::cout << "-------";
	long long max = 0, min = 0;
	for ( int i = 0; i != n; ++i ) 
		max += a[i];
	while ( min < max ) {
		long long mid = ( min + max ) >> 1;
		long long sum = 0, g = 0;
		for ( int i = 0; i != n; ++i ) {
			sum += a[i];
			if ( sum > mid )
				++g, sum = a[i];
		}
		if ( ++g <= m ) max = mid;
		else if ( ++g > m ) min = mid + 1;
	}
	std::cout << "-------";
	int g = 0, rank = 0;
	long long sum = 0, result = 0;
	for ( ; g != m - 1; ++rank ) {
		sum += a[rank];
		if ( sum > min ) {
			if ( sum - a[rank] > result ) result = sum - a[rank];
			sum = a[rank], ++g;
		}
	}
	sum = 0;
	while ( rank != n ) {
		sum += a[rank++];
	}
	if ( sum > result ) result = sum;
	std::cout << "-------";
	return result;
}