#include <cstdio>

int minCycleLength ( char*, int );
bool checkCycle ( char*, int, int, int );

int main() {
	int n;
	scanf ( "%d", &n );
	char* text = new char[n];
	scanf ( "%s", text );

	printf ( "%d\n", minCycleLength ( text, n ) );
	return 0;
}

int minCycleLength ( char* text, int n ) {
	int lo = 0, hi = 1;
	while ( text[hi] != text[0] || !checkCycle ( text, n, lo, hi ) )
		++hi;
	return hi;
}

bool checkCycle ( char* text, int n, int lo, int hi ) {
	for ( int i = 0; i != n - hi; ++i )
		if ( text[hi + i] != text[lo + i % ( hi - lo )] )
			return false;

	return true;
}
