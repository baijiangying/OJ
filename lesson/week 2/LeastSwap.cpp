#include <cstdio>
#include <iostream>

long long reverseCount1 ( int*, int, int );
void quickSort ( int*, int, int );
int getPivot ( int*, int, int );

long long reverseCount ( int*, int, int );

int main() {
	int n;
	scanf ( "%d", &n );
	int* a = new int[n];
	for ( int i = 0; i != n; ++i ) scanf ( "%d", &a[i] );
	// for ( int i = 0; i != n; ++i ) std::cout << a[i] << " ";
	// std::cout << std::endl;
	long long r = reverseCount1 ( a, 0, n );
	//long long l = reverseCount ( a, 0, n );
	
	//printf ( "%lld\n", l );
	printf ( "%lld\n", r );
	
//	for ( int i = 1; i != n; ++i ) if ( a[i] < a[i -1] ) std::cout << "error\n";
	// 	for ( int i = 0; i != n; ++i ) std::cout << a[i] << " ";
	// std::cout << std::endl;
	return 0;
}

long long reverseCount ( int* a, int lo, int hi ) {
	if ( lo + 1 < hi ) {
		int mi = lo + ( ( hi - lo ) >> 1 );
		long long l = reverseCount ( a, lo, mi );
		long long r = reverseCount ( a, mi, hi );
		long long lr = 0, s = lo;
		int* tmp = new int[mi - lo];
		for ( int i = lo; i != mi; ++i ) tmp[i - lo] = a[i];
		for ( int i = lo, j = mi; i != mi || j != hi; ) {
			while ( j != hi && a[j] < tmp[i - s] ) a[lo++] = a[j++], ++lr;
			a[lo++] = tmp[i - s], ++i;
			while ( j != hi && i == mi ) a[lo++] = a[j++];
		}
		return l + r + lr;
	}
	else
		return 0;
}

long long reverseCount1 ( int* leaf, int lo, int hi ) {
	if ( lo + 1 < hi ) {
		long long r = 0;
		int n = hi - lo, mi = n >> 1;
		long long lr = reverseCount1 ( leaf, lo, mi );
		long long rr = reverseCount1 ( leaf, lo, mi );
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
		delete[] l;
		return r + lr + rr;
	}
	else
		return 0;
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