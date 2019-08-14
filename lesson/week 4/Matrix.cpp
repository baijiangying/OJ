#include <cstdio>
#include <cstdlib>

#define P1 12637
#define P2 1123433

long long hash ( int*, const int&, int* );
void solve ( int**, const int&, const int&, int**, const int&, const int& );

int main() {
	int a, b, c, d;
	scanf ( "%d%d%d%d", &a, &b, &c, &d );
	int** matrix = new int*[a];
	for ( int i = 0; i != a; ++i ) {
		matrix[i] = new int[b];
		for ( int j = 0; j != b; ++j )
			scanf ( "%d", &matrix[i][j] );
	}

	int** pattern = new int*[c];
	for ( int i = 0; i != c; ++i ) {
		pattern[i] = new int[d];
		for ( int j = 0; j != d; ++j )
			scanf ( "%d", &pattern[i][j] );
	}

	solve ( matrix, a, b, pattern, c, d );
	return 0;
}

void solve ( int** matrix, const int& a, const int& b, 
			 int** pattern, const int& c, const int& d ) {
	int max = ( c > d ? c : d );
	int* exp = new int[max]; exp[0] = 1;
	for ( int i = 1; i != max; ++i ) exp[i] = P2 % P1 * exp[i - 1] % P1; 
	for ( int i = 0; i != a; ++i ) {
		for ( int j = 0; j != b - d + 1; ++j )
			matrix[i][j] = hash ( matrix[i] + j, d, exp );
	}
	for ( int i = 0; i != a - c + 1; ++i ) {
		for ( int j = 0; j != b - d + 1; ++j ) {
			int* tmp = new int[c];
			for ( int k = 0; k != c; ++k )
				tmp[k] = matrix[i + k][j];
			matrix[i][j] = hash ( tmp, c, exp );
			delete[] tmp;  
		}
	}

	int hashP = 0;
	int* h = new int[c];
	for ( int i = 0; i != c; ++i )
		h[i] = hash ( pattern[i], d, exp );
	int* p = pattern[1] + 0;
	
	hashP = hash ( h, c, exp );

	for ( int i = 0; i != a - c + 1; ++i ) {
		for ( int j = 0; j != b - d + 1; ++j ) 
			if ( matrix[i][j] == hashP )
				printf ( "%d %d\n", i + 1, j + 1 );
	}

	delete[] h; delete[] exp;
}

long long hash ( int* S, const int& L, int* exp ) {
	long long h = 0;
	for ( int i = 0; i != L; ++i )
		h += S[i] * exp[i];

	return h;
}