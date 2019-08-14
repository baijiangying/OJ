#include <cstdio>


class CantorNum {
private:
	int n;
	int* digit;
public:
	CantorNum ( int, long long );
	CantorNum ( int*, int );
	void increase ( long long );
	void print();
};

CantorNum::CantorNum ( int s, long long k ) {
	n = s; digit = new int[s];
	for ( int i = n - 1; i != -1 && k != 0; ++i ) {
		digit[i] = k % ( n - i );
		k /= ( n - i );
	}
}

CantorNum::CantorNum ( int* p, int s ) {
	n = s;
	digit = new int[n];
	for ( int i = n - 1; i != -1; --i ) {
		int c = 0;
		for ( int j = i + 1; j != n; ++j )
			if ( p[j] < p[i] ) ++c;
		digit[i] = c;
	}
}

void CantorNum::increase ( long long k ) {
	int* kCantor = new int[n];
	for ( int i = n - 1; i != -1 && k != 0; --i ) {
		kCantor[i] = k % ( n - i );
		k /= ( n - i );
	}
	for ( int i = 0; i != n; ++i ) {
		digit[n - 1 - i] += kCantor[n - 1 -i];
		if ( digit[n - 1 - i] > i ) {
			digit[n - 1 -i] %= ( i + 1 );
			++kCantor[n - i - 2]; 
		} 
	}
}

void CantorNum::print() {
	bool* choosed = new bool[n + 1];
	int* result = new int[n];
	for ( int i =0; i != n + 1; ++i ) choosed[i] = false;
	for ( int i = 0; i != n; ++i ) {
		int count = 0;
		for ( int j = 1; j != n + 1; ++j ) {
			if ( !choosed[j] ) ++count;
			if ( count == digit[i] + 1 ) {
				result[i] = j, choosed[j] = true;
				break;
			}
		}
	}
	for ( int i = 0; i != n; ++i )
		( i == n - 1 ) ? printf ( "%d\n", result[i] ) : printf ( "%d%c", result[i], ' ' );
}

int main() {
	long long n, a;
	scanf ( "%lld%lld", &n, &a );
	int* p = new int[n];
	for ( int i = 0; i != n; ++i ) scanf ( "%d", &p[i] );

	CantorNum  cantor ( p, n );
	cantor.increase ( a );
	cantor.print();	
}
