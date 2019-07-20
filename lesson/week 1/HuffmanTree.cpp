#include <iostream>
#include <stack>
#include <queue>

void quickSort ( int* , int, int );
int getPivot ( int* path, int lo, int hi );
void sort ( std::stack<int>& );

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
	long long length = 0;
	sort ( s );
	std::queue<int> q;
	int a = ( n - 1 ) % ( k - 1 );
	if ( a ) {
		long long sum = 0;
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

void sort ( std::stack<int>& r ) {
	int size = r.size();
	int* path = new int[r.size()];
	for ( int i = 0; r.size(); ++i ) {
		path[i] = r.top();
		r.pop();
	}
	quickSort ( path, 0, size );
	
	while ( 0 < size-- ) r.push ( path[size] );
}

void quickSort ( int* path, int lo, int hi ) {
	if ( lo + 1 < hi ) {
		int pivot = getPivot ( path, lo, hi );
		quickSort ( path, lo, pivot );
		quickSort ( path, pivot + 1, hi );
	}
}	

int getPivot ( int* path, int lo, int hi ) {
	int pivot = lo;
	for ( int i = lo; i != hi ; ++i ) {
		if ( path[i] < path[pivot] ) {
			std::swap ( path[pivot], path[i] );
			std::swap ( path[++pivot], path[i] );
		}
	}



	return pivot;
}