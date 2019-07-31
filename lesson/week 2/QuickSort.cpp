#include <iostream>

void quickSort ( int*, int, int );
int getPivot ( int*, int, int );

int main() {
	std::ios::sync_with_stdio ( false );
	int n;
	std::cin >> n;
	int* a = new int[n];
	for ( int i = 0; i != n; ++i )
		std::cin >> a[i];
	quickSort ( a, 0, n );
	for ( int i = 0; i != n; ++i )
		std::cout << a[i] << " ";
	std::cout << std::endl;
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