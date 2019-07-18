#include <iostream>
#include <stack>
#include <limits.h>

int maxInHistogram ( int*, int );

int main() {
	std::ios::sync_with_stdio ( false );
	int n = 0;
	std::cin >> n;
	int* histogram = new int[n];
	for ( int i = 0; i != n; ++i ) {
		int a;
		std::cin >> a;
		* ( histogram + i ) = a;
	}

	std::cout << maxInHistogram ( histogram, n );
	return 0;
}

int maxInHistogram ( int* histogram, int n ) {
	std::stack<int> s;    //stack的size默认为1。
	if ( n > 1 ) s.push ( 0 ); else return ( n ? *histogram : 0 );

	s.push ( -1 ); 		//此时s.size()为1。
	s.push ( 0 );
	int max = 0;
	for ( int i = 1; i != n + 1; ++i ) {
		while ( ( i == n ) || 
			histogram[i] < histogram[s.top()] ) {
			if ( s.size() == 2 ) break;
			int height = histogram[s.top()]; 
			s.pop();
			int width = i - s.top() - 1;
			if ( height * width > max ) 
				max = height * width;
		}

		s.push ( i );
	}
	
	return max;
}