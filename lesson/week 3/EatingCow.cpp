#include <cstdio>
#include <cstdlib>

const int N = 2000;
int dp[N + 2][N + 2][2];

int solve ( int*, int, int );
int abs ( int a ) { return ( a < 0 ? -a : a ); }
int min ( const int& a, const int& b ) { return ( a < b ? a : b ); }
void quickSort ( int*, int, int );
int getPivot ( int*, int, int );
template <typename T> void swap ( T& a, T& b ) { T tmp = a; a = b; b = tmp; }


int main() {
	int n, k;
	scanf ( "%d%d", &n, &k );
	int* pos = new int[n + 1];
	for ( int i = 1; i != n + 1; ++i )
		scanf ( "%d", &pos[i] );

	printf ( "%d\n", solve ( pos, n, k ) );
}

int solve ( int* pos, int n, int k ) {
	quickSort ( pos, 1, n + 1 );
	for ( int i = 1; i != n + 1; ++i )
		dp[i][i][0] = dp[i][i][1] = abs ( pos[i] - k ) * n;
	for ( int len = 1; len != n; ++len )
		for ( int l = 1, r; ( r = l + len ) <= n; ++l ) {
			dp[l][r][0] =
				min ( dp[l + 1][r][0] + ( n - r + l ) * abs ( pos[l] - pos[l + 1] ),
					  dp[l + 1][r][1] + ( n - r + l ) * abs ( pos[l] - pos[r] ) );
			dp[l][r][1] = 
				min ( dp[l][r - 1][1] + ( n - r + l) * abs ( pos[r] - pos[r - 1] ),
					  dp[l][r - 1][0] + ( n - r + l) * abs ( pos[r] - pos[l] ) );
		}
	return min ( dp[1][n][0], dp[1][n][1] );
}

void quickSort ( int* a, int lo, int hi ) {
	if ( lo + 1 < hi ) {
		int pivot = getPivot ( a, lo, hi );
		quickSort ( a, lo, pivot );
		quickSort ( a, pivot + 1, hi );
	}
}

int getPivot ( int* a, int lo, int hi ) {
	int pivot = lo;
	swap ( a[lo + rand() % ( hi - lo )], a[lo] );
	for ( int i = lo + 1; i != hi; ++i ) {
		if ( a[i] < a[pivot] ) {
			swap ( a[i], a[pivot++] );
			swap ( a[i], a[pivot] );
		}
	}
	return pivot;
}