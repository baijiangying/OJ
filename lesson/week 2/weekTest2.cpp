#include <cstdio>
#include <iostream>

long long solve ( int*, int, int );
void reverseCount ( int*, int, int, long long&, long long& );
void quickSort ( int*, int, int );
int getPivot ( int*, int, int );


int main () {
	int n;
	scanf ( "%d", &n );
	int* leaf = new int[n];
	for ( int i = 0; i != n; ++i ) 
		scanf ( "%d", &leaf[i] );
	printf ( "%lld\n", solve ( leaf, 0, n ) );
}

long long solve ( int* leaf, int lo, int hi ) {
	if ( lo + 2 < hi ) {
		int mi = lo + ( ( hi -lo ) >> 1 );
		long long lR = solve ( leaf, lo, mi );
		long long rR = solve ( leaf, mi, hi );
		long long r,rPrime;
		reverseCount ( leaf, lo, hi, r, rPrime );
		if ( r > rPrime ) {
			for ( int i = 0; i != mi - lo; ++i )
				std::swap ( leaf[lo + i],leaf[mi + i] );
		}
		return lR + rR + ( r > rPrime ? rPrime : r );
	}
	else {
		if ( leaf[lo] > leaf[lo + 1] )
			std::swap ( leaf[lo], leaf[lo + 1] );
		return 0;
	}
}

void reverseCount ( int* leaf, int lo, int hi, long long& r, long long& rPrime ) {
	r = 0; rPrime = 0;
	int n = hi - lo, mi = n >> 1;
	int* l = new int[hi - lo];
	for ( int i = 0; i != n; ++i ) l[i] = leaf[lo + i];
	quickSort ( l, 0, mi );
	quickSort ( l, mi, n );
	for ( int i = 0, j = mi; i != mi && j != n; ) {
		if ( l[j] < l[i] ) {
			r += mi - i;
			++j;
		}
		else
			++i;
	}

	for ( int i = mi, j = 0; i != n && j != mi; ) {
		if ( l[j] < l[i] ) {
			rPrime += n - i;
			++j;
		}
		else
			++i;
	}
	delete[] l;
}

void quickSort ( int* a, int lo, int hi ) {
	if ( lo + 1 > hi ) return;
	int pivot = getPivot ( a, lo, hi );
	quickSort ( a, lo, pivot );
	int i = 1;
	while ( a[pivot + i] == a[pivot] ) ++i;
	quickSort ( a, pivot + i, hi );
}

int getPivot ( int* a, int lo, int hi ) {
	int pivot = lo;
	std::swap ( a[pivot], a[lo + rand() % ( hi - lo )] );
	for ( int i = pivot + 1; i != hi; ++i ) {
		if ( a[i] < a[pivot] ) {
			std::swap ( a[pivot++], a[i] );
			std::swap ( a[pivot], a[i] );
		}
	}
	return pivot;
}