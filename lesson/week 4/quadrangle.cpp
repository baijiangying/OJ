#include <cstdio>
#include <cstdlib>
#include "Stack.h"

struct Point {
	double x;
	double y;
	Point operator- ( Point q ) {
		Point p { x - q.x, y - q.y };
		return p;
	}
};

inline double cross(Point a, Point b) {
	return a.x * b.y - a.y * b.x;
}

inline bool toLeft ( Point P, Point Q, Point R ) {
	return cross ( Q - P, R - Q ) > 0;
}

inline double area ( Point i, Point j, Point k, Point l ) {
	return cross ( j - i, l - k );
}

Point* convexHull ( Point*, int, int& );
void quickSort ( Point*, int lo, int hi, Point );
int getPoivot ( Point*, int lo, int hi, Point );
double solve ( Point*, int );
template <typename T> void swap ( T& a, T& b ) { T tmp = a; a = b; b = tmp; }

int main() {
	int n;
	scanf ( "%d", &n );
	Point* a = new Point[n];
	for ( int i = 0; i != n; ++i ) 
		scanf ( "%lf%lf", &a[i].x, &a[i].y );
	
	printf ( "%.3lf\n", solve ( a, n ) );
	return 0;
}

double solve ( Point* a, int n ) {
	int count = 0;
	Point* p = convexHull ( a, n, count );
	double maxArea = 0;
	for ( int i = 0; i != count; ++i ) {
		int k = ( i + 1 ) % count, l = ( i + 3 ) % count;
		for ( int j = i + 2 ; j < count; ++j ) {
			while ( k != j - 1 && 
				area ( p[i], p[j], p[k], p[l]) < 
				area ( p[i], p[j], p[k + 1], p[l] ) )
				++k;
			while ( l != ( i - 1 + count ) % count &&
				area ( p[i], p[j], p[k], p[l]) < 
				area ( p[i], p[j], p[k], p[l + 1] ) )
				++l;
			if ( area ( p[i], p[j], p[k], p[l] ) > maxArea )
				maxArea = area ( p[i], p[j], p[k], p[l] );
		}
	}
	return maxArea / 2;
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


