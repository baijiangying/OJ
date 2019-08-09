#include <cstdio>

const long long factorial[20] = {
	1,1,2,6,24,
	120,720,5040,40320,362880,
	3628800,39916800,479001600,
	6227020800,87178291200,
	1307674368000,20922789888000,
	355687428096000,6402373705728000,
	121645100408832000
}

class CantorNum {
private:
	int n;
	int* digit;
public:
	CantorNum ( int, long long );
	void increase ( long long );
	void print();
};

void CantorNum::CantorNum ( int s, long long k ) {
	n = s; digit = new int[s];
	for ( int i = n - 1; i != -1 && k != 0; ++i ) {
		digit[i] = k % ( n - i );
		k /= ( n - i );
	}
}
