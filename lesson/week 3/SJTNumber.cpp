#include <cstdio>

class SJTNum {
private:
	int n;
	unsigned long long No;
	int* digit;
	int* direction;
	
public:
	void increase();
	void increase ( unsigned long long  k );
	SJTNum ( int s );
	void print() { 
		int* result = new int[n];
		for ( int i = 0; i != n; ++i ) result[i] = 0;
		for ( int i = n - 1; i != -1; --i ) {
			int k = -1;
			for ( int j = n - 1; j != -1; --j ) {
				if ( !result[j] ) ++k;
				if ( k == digit[i] ) { result[j] = i + 1; break; }
			}
		}
		printf ( "%d", result[0] );
		for ( int i = 1; i != n; ++i )
			printf ( "%c%d", ' ', result[i]);
		printf ( "\n" );
	}
};

SJTNum::SJTNum( int s ) {
	n = s, No = 1;
	digit = new int[n]; direction = new int[n];
	for ( int i = 0; i != n; ++i )
		digit[i] = 0, direction[i] = 1;
}

void SJTNum::increase() {
	int r = n - 1;
	while ( digit[r] + direction[r] > r || digit[r] + direction[r] < 0 ) {
		direction[r] = -direction[r]; --r;
	}
	digit[r] += direction[r];
	++No;
}

void SJTNum::increase ( unsigned long long k ) {
	if ( k > 1 ) {
		int* kNum = new int[n];
		for ( int i = 0; i != n; ++i ) kNum[i] = 0;
		for ( int i = 1; i != n && k != 0; ++i ) {
			int digit = k % ( n - i + 1);
			if ( ( k /= ( n - i + 1) ) & 1 ) kNum[n - i] = ( n - i ) - digit;
			else kNum[n - i] = digit;
		}
		for ( int r = n - 1; r != -1 ; --r ) {
			for ( int i = 0; i != kNum[r]; ++i ) {
				if ( ( digit[r] + direction[r] > r || digit[r] + direction[r] < 0 ) )
					++kNum[r - 1], direction[r] = -direction[r];
				else
					digit[r] += direction[r];
			}
		}
		No += k;
		delete[] kNum;
	}
	else
		increase();
}


int main() {
	long long n, k;
	scanf ( "%lld%lld", &n, &k );
	SJTNum sjt ( n );


	sjt.increase ( k - 1 );
	sjt.print();
	
	return 0;
}