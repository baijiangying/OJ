#include <cstdio>
#include <cstdlib>
#include "Stack.h"

struct Point {
	long long x;
	long long y;
};

inline bool toLeft ( Point P, Point Q, Point R ) {
	return ( P.x * Q.y + Q.x * R.y + R.x * P.y -
			 P.x * R.y - Q.x * P.y - R.x * Q.y ) > 0;
}

Point* convexHull ( Point*, int, int& );
void quickSort ( Point*, int lo, int hi, Point );
int getPoivot ( Point*, int lo, int hi, Point );
bool check ( Point*, int, Point );
template <typename T> void swap ( T& a, T& b ) { T tmp = a; a = b; b = tmp; }

int main() {
	int n, m;
	scanf ( "%d", &n );
	Point* a = new Point[n];
	for ( int i = 0; i != n; ++i ) 
		scanf ( "%lld%lld", &a[i].x, &a[i].y );
	scanf ( "%d", &m );
	Point* b = new Point[m];
	for ( int i = 0; i != m; ++i ) 
		scanf ( "%lld%lld", &b[i].x, &b[i].y );
	int count;
	Point* extremeP = convexHull ( a, n, count );
	for ( int i = 0; i != m; ++i )
		printf ( "%d\n", check ( extremeP, count, b[i] ) );

	return 0;
}

Point* convexHull ( Point* a, int n, int& count ) {
	int min = 0;
	for ( int i = 1; i != n; ++i ) {
		if ( a[min].y == a[i].y && a[i].x < a[min].x ||
			 a[i].y < a[min].y )
			min = i;
	}
	swap ( a[min], a[0] );
	quickSort ( a, 1, n, a[0] );
	Stack<Point> s;
	s.push ( a[0] ); s.push ( a[1] );
	for ( int i = 2; i != n; ++i ) {
		if ( toLeft ( s.subTop(), s.top(), a[i] ) )
			s.push ( a[i] );
		else {
			while ( !toLeft ( s.subTop(), s.top(), a[i] ) )
				s.pop();
			s.push ( a[i] );
		}
	}
	Point* extremeP = new Point[s.size()];
	count = s.size();
	for ( int i = s.size() - 1; i != -1; --i )
		extremeP[i] = s.pop();

	return extremeP;
}

bool check ( Point* a, int count, Point b ) {
	for ( int i = 0; i != count; ++i ) {
		if ( !toLeft ( a[i], a[ ( i + 1 ) % count], b ) )
			return false;
	}
	return true;
}

void quickSort ( Point* a, int lo, int hi, Point b ) {
	if ( lo + 1 < hi ) {
		int pivot = getPoivot ( a, lo, hi, b );
		quickSort ( a, lo, pivot, b );
		quickSort ( a, pivot + 1, hi, b );
	}
}

int getPoivot ( Point* a, int lo, int hi, Point b ) {
	int pivot = lo;
	swap ( a[lo + rand() % ( hi - lo )], a[lo] );

	for ( int i = lo + 1; i != hi; ++i ) {
		if ( !toLeft ( b, a[pivot], a[i] ) ) {
			swap ( a[pivot++], a[i] );
			swap ( a[pivot], a[i] );
		}
	}

	return pivot;
}