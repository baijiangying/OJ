#include <cstdio>
#include <stack>

std::stack<int> sort ( std::stack<int> );

int main() {
	std::stack<int> s;
	int n,a;
	scanf ( "%d", &n );
	int* result = new int[n];
	int r = n;

	while ( 0 < r-- ) scanf ( "%d", &a ), s.push( a );
	s = sort ( s );
	r = n;
	while ( !s.empty() ) {
		* ( result + --r ) = s.top();
		s.pop();
	}

	for ( int i = 0; i != n; ++i )
		printf ( "%d\n", * ( result + i ) );
	return 0;
}

std::stack<int> sort ( std::stack<int> r ) {
	std::stack<int> s;

	while ( !r.empty() ) {
		if ( s.empty() || s.top() <= r.top() )
			s.push ( r.top() ), r.pop();
		else {
			int t = r.top();
			r.pop();
			r.push ( s.top() ), s.pop();
			r.push ( t );
		}
	}

	return s;
}