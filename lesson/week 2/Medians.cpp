#include <iostream>
#include <stdlib.h>
#include "Heap.h"


int main() {
	std::ios::sync_with_stdio ( false );
	int n;
	std::cin >> n;
	int* a = new int[2 * n - 1];
	int mid = 0;
	std::cin >> mid;
	std::cout << mid << std::endl;
	MinHeap minH ( n - 1 );
	MaxHeap maxH ( n - 1 );
	for ( int i = 1; i != 2 * n - 1; ) {
		int m = 0, count = 0;
		std::cin >> m;
		if ( m < mid ) maxH.insert ( m ), ++count;
		else minH.insert ( m ), --count;
		std::cin >> m;
		if ( m < mid ) maxH.insert ( m ), ++count;
		else minH.insert ( m ), --count;
		if ( count == 2 ) {
			minH.insert ( mid );
			mid = maxH.pop();
		}
		else if ( count == -2 ) {
			maxH.insert ( mid );
			mid = minH.pop();
		}
		std::cout << mid << std::endl;
		i += 2;
	}
}