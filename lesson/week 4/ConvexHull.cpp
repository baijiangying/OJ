#include <cstdio>

inline bool toLeft ( Coordinate, Coordinate, Coordinate ); 
struct Coordinate {
	int x;
	int y;
	bool operator< ( Coordinate P, Q)
};

int extremeP ( Coordinate*, int );


int main() {
	int n;
	scanf ( "%d", &n );
	Coordinate* pos = new Coordinate[n];
	for ( int i = 0; i != n; ++i ) 
		scanf ( "%d%d", &pos[i].x, &pos[i].y ); 
	
	printf ( "%d\n", extremeP ( pos, n ) );
	return 0;
}

int extremeP ( Coordinate* pos, int n ) {

}

inline bool toLeft ( Coordinate P, Coordinate Q, Coordinate R ) {
	return ( P.x * Q.y + Q.x * R.y + R.x * P.y -
		     P.x * R.y - Q.x * P.y - R.x * Q.y ) > 0;
}