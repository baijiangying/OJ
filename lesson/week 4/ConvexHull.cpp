#include <cstdio>
#include <cstdlib>

struct Point {
	long long x;
	long long y;
	int No;
	bool operator< ( Point Q ) {
		return ( y == Q.y ? x < Q.x : y < Q.y );
	}
};

Point stack[100000];
int _top = 0;
void push ( Point p ) { stack[_top++] = p; }
Point pop() { return stack[--_top]; }
Point top() { return stack[_top - 1]; }
Point subTop() { return stack[_top - 2]; }
int size() { return _top; }

inline bool toLeft ( Point, Point, Point ); 
template <typename T> void swap ( T&, T& );
int extremeP ( Point*, int );
void sort ( Point*, int, int, Point );
int getPivot ( Point*, int, int, Point );
void insertionSort ( Point* pos, int lo, int hi, Point P );


int main() {
	int n;
	scanf ( "%d", &n );
	Point* pos = new Point[n];
	for ( int i = 0; i != n; ++i ) 
		scanf ( "%lld%lld", &pos[i].x, &pos[i].y ), pos[i].No = i + 1; 

	printf ( "%d\n", extremeP ( pos, n ) );
	return 0;
}

int extremeP ( Point* pos, int n ) {
	int minR = 0;
	for ( int i = 0; i != n; ++i )
		if ( pos[i] < pos[minR] ) minR = i;
	swap ( pos[0], pos[minR] );
	sort ( pos, 1, n, pos[0] );

	push ( pos[0] ); push ( pos[1] );
	for ( int i = 2; i != n; ++i ) {
		if ( toLeft ( subTop(), top(), pos[i]) )
			push ( pos[i] );
		else {
			while ( !toLeft ( subTop(), top(), pos[i]) )
				pop();
			push ( pos[i] );
		}
	}
;
	int result = size();
	while ( size() ) 
		result = ( pop().No * ( long long ) result ) % ( n + 1 ) ;

	return result % ( n + 1 );
}

inline bool toLeft ( Point P, Point Q, Point R ) {
	return ( P.x * Q.y + Q.x * R.y + R.x * P.y -
		     P.x * R.y - Q.x * P.y - R.x * Q.y ) >= 0;
}

template <typename T> void swap ( T& a, T& b ) {
	T tmp = a;
	a = b; b = tmp;
}

void sort ( Point* pos, int lo, int hi, Point P ) {
	if ( lo + 1 < hi ) {
		int pivot = getPivot ( pos, lo, hi, P );
		sort ( pos, lo, pivot, P );
		sort ( pos, pivot + 1, hi, P );
	}
}

int getPivot ( Point* pos, int lo, int hi, Point P ) {
	int pivot = lo;
	swap ( pos[pivot], pos[lo + rand() % ( hi - lo )] );
	for ( int i = pivot + 1; i != hi; ++i ) 
		if ( !toLeft ( P, pos[pivot], pos[i] ) ) {
			swap ( pos[pivot++],pos[i] );
			swap ( pos[pivot], pos[i] );
		}

	return pivot;
}
