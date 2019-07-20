#include <iostream>
#include "Queue.h"

void sequece ( int*, int );

int main() {
	int n;
	std::cin >> n;
	int* a = new int[n];
	for ( int i = 0; i !=n; ++i ) {
		int m = 0;
		std::cin >> m;
		a[i] = m;
	}

	sequece ( a, n );
	for ( int i = 0; i != n; ++i ) std::cout << a[i] << " ";
	std::cout << std::endl;
	

	return 0;
}

void sequece( int* a, int n ) {
	int* maxElem = new int[n];
	int* result = new int[n];
	int rank = 0;
	maxElem[n - 1] = a[n - 1];
	for ( int i = n - 2; i != -1; --i ) {
		maxElem[i] = ( maxElem[i + 1] > a[i] ? maxElem[i + 1] : a[i] );
	}
	Queue<int> q;
	q.init();
	for ( int i = 0; i < n; ) {
		int max = maxElem[i];
		if ( q.size() && ( max <= q.front() || max <= q.rear() ) ) {
			if ( q.front() < q.rear() )
				result[rank] = q.dequeue ( false ), ++rank;
			else
				result[rank] = q.dequeue ( true ), ++rank;
		} 
		else {
			while ( a[i] != max) {
				q.enqueue ( a[i] );
				++i;
			}
			result[rank] = max, ++rank, ++i;
		}
		

	}
	while ( q.size() ) {
		if ( q.front() < q.rear() )
			result[rank] = q.dequeue ( false ), ++rank;
		else
			result[rank] = q.dequeue ( true ), ++rank;
	} 
	for ( int i = 0; i != n; ++i ) 
		* ( a + i ) = result[i];
}