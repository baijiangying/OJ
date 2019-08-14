#include <cstdio>

const unsigned long long factorial[21] = {
	1,
	1,
	2,
	6,
	24,
	120,
	720,
	5040,
	40320,
	362880,
	3628800,
	39916800,
	479001600,
	6227020800,
	87178291200,
	1307674368000,
	20922789888000,
	355687428096000,
	6402373705728000,
	121645100408832000,
	2432902008176640000
};

class Combination {
private:
	int _n;
	int _m;
	int* _combination;
	int* _max;
public:
	Combination ( int, int );
	~Combination() { delete[] _combination; delete[] _max; }
	bool operator++();
	bool output ( int* );
};

Combination::Combination ( int n, int m ) {
	_n = n, _m = m;
	_combination = new int[m];
	_max = new int[m];
	for ( int i = 0; i != m; ++i )
		_combination[i] = i + 1;
	for ( int i = 0; i != m; ++i )
		_max[m - 1 - i] = _n - i;
}

bool Combination::output ( int* c ) {
	for ( int i = 0; i != _m; ++i ) 
		c[i] = _combination[i];
	return true;
}

bool Combination::operator++() {
	if ( _combination[0] == _max[0] ) return false;
	int r = _m - 1;
	++_combination[r];
	while ( _combination[r] > _max[r] )
		++_combination[--r];
	while ( ++r != _m ) _combination[r] = _combination[r - 1] + 1;
	return true;
}

struct Partner{
	int woman;
	int man;
};

unsigned long long solve ( int, Partner*, int );
int check ( int*, int, Partner*, int );

int main() {
	int n, m;
	scanf ( "%d%d", &n, &m );
	Partner* ban = new Partner[m + 1];
	for ( int i = 1; i != m + 1; ++i ) 
		scanf ( "%d%d", &ban[i].woman, &ban[i].man );

	printf ( "%llu\n", solve ( n, ban, m ) );
	return 0;
}

unsigned long long solve ( int n, Partner* ban, int m ) {
	unsigned long long result = factorial[n];
	for ( int i = 1; i != m + 1; ++i ) {
		int* cbt = new int[i];
		Combination C ( m, i );
		do { 
			C.output ( cbt );
			int e = 0;
			if ( ( e = check ( cbt, i, ban, n ) ) != -1 )
				result = ( i & 1 ? result - factorial[e] :
								   result + factorial[e] );
		} while ( ++C );
		delete[] cbt;
	}
	return result;
}

int check ( int* cbt, int i, Partner* ban, int n ) {
	int result = n;
	int* man = new int[n + 1];
	int* woman = new int[n + 1];
	for ( int _ = 0; _ != n + 1; ++_ ) man[_] = woman[_] = 0; 
	for ( int _ = 0; _ != i; ++_ ) {
		if ( man[ban[cbt[_]].man] || woman[ban[cbt[_]].woman ]) { delete[] man; delete[] woman; return -1; }
		man[ban[cbt[_]].man] = ban[cbt[_]].woman;
		woman[ban[cbt[_]].woman] = ban[cbt[_]].man;
		--result;
	}
	delete[] man;
	delete[] woman;
	return result;
}