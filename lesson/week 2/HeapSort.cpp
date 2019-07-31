#include <iostream>
#include "Heap.h"

void heapSort ( int*, int, int );

int main() {
	std::ios::sync_with_stdio ( false );
	int n;
	std::cin >> n;
	int* a = new int[n];
	for ( int i = 0; i != n; ++i )
		std::cin >> a[i];

	heapSort ( a, 0, n );
	for ( int i = 0; i != n; ++i )
		std::cout << a[i] << " ";
	std::cout << std::endl;
}

void heapSort ( int* a, int lo, int hi) {
	MinHeap h ( hi - lo );
	for ( int i = lo; i != hi; ++i )
		h.insert ( a[i] );
	for ( int i = lo; i != hi; ++i )
		a[i] = h.pop();
}
