#include <iostream>
#include <stack>

std::stack<int> sort ( std::stack<int> );

int main() {
	std::stack<int> s;
	int a;
	while ( std::cin >> a) s.push( a );
	s = sort ( s );

	while ( !s.empty() ) {
		std::cout << s.top() << std::endl;
		s.pop();
	}
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