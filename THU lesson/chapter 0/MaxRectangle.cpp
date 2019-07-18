#include <stack>
#include <bits/stdc++.h>

int maxInHistogram ( int*, int );

int main() {
	std::ios::sync_with_stdio(false);
	int n = 0, m = 0;
	std::cin >> n >> m;
	std:: string* matrix = new std::string[n]();
	for ( int i = 0; i != n; ++i ) {
		std::cin >> matrix[i];
	}
	
	int max = 0;
	int* histogram = new int[m];
	for ( int i = 0; i != m; ++i ) histogram[i] = 0;
	for ( int i = 0; i != n ; ++i ) { 
		for ( int j = 0; j != m; ++j ) {
			( matrix[i][j] == '.' ) ? ++histogram[j] : histogram[j] = 0;
		}
		max = ( max > maxInHistogram ( histogram, m ) ) ? 
				max : maxInHistogram ( histogram, m );

	}
	

	std::cout << max <<std::endl;;
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