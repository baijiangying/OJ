#include <cstdio>

void radixSort ( unsigned* , int n );
unsigned nextInt ( unsigned );
void initData ( unsigned*, unsigned, unsigned, unsigned );
unsigned hashArr ( unsigned*, unsigned );
unsigned exp256 ( int b ) { return ( b == 0 ? 1 : exp256 ( b - 1 ) * 256 ); }

int main() {
	unsigned n, k, seed;
	scanf ( "%u%u%u", &n, & k, &seed );

	unsigned* a = new unsigned[n];
	initData ( a, n, k, seed );
	radixSort ( a, n );
	printf ( "%u\n", hashArr ( a, n ) );
}

unsigned nextInt ( unsigned x ) {
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return x;
}

void initData ( unsigned* a, unsigned n, unsigned k, unsigned seed ) {
	for ( int i = 0; i != n; ++i ) {
		seed = nextInt ( seed );
		a[i] = seed >> ( 32 - k );
	}
}

unsigned hashArr ( unsigned* a, unsigned n ) {
	unsigned x = 998244353, ret = 0;
	for ( int i = 0; i != n; ++i ) {
		ret ^= ( a[i] + x );
		x = nextInt ( x );
	}
	return ret;
}

void radixSort ( unsigned* a, int n ) {
	int base = 256;
	for ( int i = 0; i != 4; ++i ) {
		unsigned* dump = new unsigned[n];
		for ( int r = 0; r != n; ++r ) dump[r] = a[r];
		unsigned short* digit = new unsigned short[n];
		for ( int r = 0; r != n; ++r ) digit[r] = ( a[r] / exp256 ( i ) ) % base;
		int* count  = new int[256];
		for ( int r = 0; r != 256; ++r ) count[r] = 0;
		for ( int r = 0; r != n; ++r ) ++count[digit[r]];
		for ( int r = 1; r != 256; ++r ) count[r] += count[r - 1];
		for ( int r = n - 1; r != -1; --r )
			a[--count[digit[r]]] = dump[r];
		delete[] dump;
		delete[] digit;
		delete[] count;
	}
}