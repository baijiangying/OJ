#include <cstdio>
#include <cstdlib>

long long solve ( int*, int, int );
bool lt ( int, int, int );
int abs ( int a ) { return ( a < 0 ? -a : a ); }
void quickSort ( int*, int, int );
int getPivot ( int*, int, int );
template <typename T> void swap ( T& a, T& b ) { T tmp = a; a = b; b = tmp; }

int main() {
	int n, k;
	scanf ( "%d%d", &n, &k );
	int* pos = new int[n + 1];
	for ( int i = 1; i != n + 1; ++i )
		scanf ( "%d", &pos[i] );

	printf ( "%lld\n", solve ( pos, n, k ) );
}

long long solve ( int* pos, int n, int k ) {

}

void quickSort ( int* a, int lo, int hi ) {
	if ( lo + 1 < hi ) {
		int pivot = getPivot ( a, lo, hi );
		quickSort ( a, lo, pivot );
		quickSort ( a, pivot + 1, hi );
	}
}

int getPivot ( int* a, int lo, int hi ) {
	int pivot = lo;
	swap ( a[lo + rand() % ( hi - lo )], a[lo] );
	for ( int i = lo + 1; i != hi; ++i ) {
		if ( a[i] < a[pivot] ) {
			swap ( a[i], a[pivot++] );
			swap ( a[i], a[pivot] );
		}
	}
	return pivot;
}