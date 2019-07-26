#include <iostream>
#include <stack>
#include <queue>

void quickSort ( long long* , int, int );
int getPivot ( long long* path, int lo, int hi );
void sort ( std::stack<long long>& );

long long huffmanLength ( std::stack<long long>, int, int );

int main() {
	std::ios::sync_with_stdio ( false );
	int n, k;
	std::cin >> n >> k;
	std::stack<long long> s;
	for ( int i = 0; i != n; ++i ) {
		long long n;
		
		std::cin >> n;
		s.push ( n );
	}
	std::cout << huffmanLength( s, n, k ) << std::endl;;
	return 0;
}

long long huffmanLength ( std::stack<long long> s, int n, int k ) {
	long long length = 0;
	sort ( s );
	std::queue<long long> q;
	int a = ( n - 1 ) % ( k - 1 );
	if ( a ) {
		long long sum = 0;
		for ( int i = 0; i != a + 1; ++i ) {
			sum += s.top();
			s.pop();
		}
		q.push ( sum );
		length += sum;
	}
	int count = ( n - 1 ) / ( k - 1 );
	while ( 0 < count-- ) {
		long long sum = 0;
		for ( int i = 0; i != k; ++i ) {
			if ( ( s.size() && q.size() && s.top() < q.front() ) ||
				s.size() && !q.size() ) {
				sum += s.top();
				s.pop();
			}
			else {
				sum += q.front();
				q.pop();
			}
		}
		q.push ( sum );
		length += sum;
	}

	return length;
}

void sort ( std::stack<long long>& r ) {
	int size = r.size();
	long long* path = new long long[r.size()];
	for ( int i = 0; r.size(); ++i ) {
		path[i] = r.top();
		r.pop();
	}
	quickSort ( path, 0, size );
	
	while ( 0 < size-- ) r.push ( path[size] );
}

void quickSort ( long long* path, int lo, int hi ) {
	if ( lo + 1 < hi ) {
		int pivot = getPivot ( path, lo, hi );
		quickSort ( path, lo, pivot );
		quickSort ( path, pivot + 1, hi );
	}
}	

int getPivot ( long long* path, int lo, int hi ) {
	int pivot = lo;
	for ( int i = lo; i != hi ; ++i ) {
		if ( path[i] < path[pivot] ) {
			std::swap ( path[pivot], path[i] );
			std::swap ( path[++pivot], path[i] );
		}
	}



	return pivot;
}