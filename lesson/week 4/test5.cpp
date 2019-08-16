#include <cstdio>

struct Point {
	int x;
	int y;
};

int main() {
	int n, m;
	scanf ( "%d%d", &n, &m );
	Point* a = new Point[n];
	Point* b = new Point[m];

	for ( int i = 0; i != n; ++i ) 
		scanf ( "%d%d", &a[i].x, &a[i].y );
	for ( int i = 0; i != m; ++i ) 
		scanf ( "%d%d", &b[i].x, &b[i].y );

	for ( int i = 0; i != m; ++i )
		printf ( "%d\n", check ( a, n, b[i] ) );

	return 0;
}