#include <iostream>


int sequenceCount ( int*, int, int, int );

int main() {
	std::ios::sync_with_stdio ( false );
	srand ( time ( nullptr ) );
	int n, d;
	std::cin >> n >> d;
	int* a = new int[n];
	for ( int i = 0; i != n; ++i ) std::cin >> a[i];


	std::cout << sequenceCount ( a, 0, n, d ) << std::endl;
}

int sequenceCount ( int* a, int lo, int hi, int d ) {
	int result = 0;
	int max = lo, min = lo;
	for ( int i = lo + 1; i != hi; ++i ) {
		if ( a[i] >= a[max] ) max = i;
		if ( a[i] <= a[min] ) min = i;
	 	if ( a[max] - a[min] > d ) {
	 		max = min = i;
	 		int r = i - 1;
	 		while ( a[max] - a[min] <= d ) {
	 			if ( a[r] >= a[max] ) max = r;
				if ( a[r] <= a[min] ) min = r;
				--r;
	 		}
	 		lo = ( min < max ? min + 1 : max + 1 );
	 	}
	 	result += ( i - lo );	
	}
	return result;
}

