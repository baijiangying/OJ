#include <iostream>
#include <stack>
#include <queue>


std::stack<int> sort ( std::stack<int> );
int huffmanLength ( std::stack<int>, int, int );

int main() {
	std::ios::sync_with_stdio ( false );
	int n, k;
	std::cin >> n >> k;
	std::stack<int> s;
	for ( int i = 0; i != n; ++i ) {
		int n = 0;
		std::cin >> n;
		s.push ( n );
	}
	std::stack<int> s1 = s;
	std::cout << huffmanLength( s, n, k ) << std::endl;;
	return 0;
}

int huffmanLength ( std::stack<int> s, int n, int k ) {
	int length = 0;
	s = sort ( s );
	std::queue<int> q;
	int a = ( n - 1 ) % ( k - 1 );
	if ( a ) {
		int sum = 0;
		for ( int i = 0; i != a + 1; ++i ) {
			sum += s.top();
			//std::cout << "pop " << s.top() << std::endl;
			s.pop();
		}
		q.push ( sum );
		//std::cout << " length+ " << sum << std::endl;
		length += sum;
	}
	int count = ( n - 1 ) / ( k - 1 );
	while ( 0 < count-- ) {
		int sum = 0;
		for ( int i = 0; i != k; ++i ) {
			if ( ( s.size() && q.size() && s.top() < q.front() ) ||
				s.size() && !q.size() ) {
				sum += s.top();
				//std::cout << "pop " << s.top() << std::endl;
				s.pop();
			}
			else {
				sum += q.front();
				//std::cout << "deque " << q.front() << std::endl;
				q.pop();
			}
		}
		//std::cout << " enque " << sum << std::endl;
		q.push ( sum );
		//std::cout << " length+ " << sum << std::endl;
		length += sum;
	}

	return length;
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
	while ( !s.empty() ) {
		r.push ( s.top() );
		s.pop();
	}
	return r;
}