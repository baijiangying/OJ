#include <cstdio>
#include <stdlib.h>
#include <limits.h>

int main() {
	int n = 0;
	scanf ( "%d", &n );
	int** workTime = new int*[n];
	for ( int i = 0; i != n; ++i ) { workTime[i] = new int[n]; }
	for( int i = 0; i != n; ++i ) 
		for ( int j = 0; j != n; ++j ) 
			scanf ( "%d", &workTime[i][j] );
	printf ( "%s\n", "reading done");

	int* workTable = new int[n];
	for ( int i = 0; i != n; ++i ) workTable[i] = 0;
	int* staffTable = new int[n];
	for ( int i = 0; i != n; ++i ) staffTable[i] = 0;

	int sum = 0;
	for ( int i = 0; i != n; ++i ) {
		int min = INT_MAX, x = 0, y = 0;
		for ( int j = 0; j != n; ++j )
			if ( !staffTable[j] )
				for ( int k = 0; k != n; ++k )
					if ( !workTable[k] && workTime[i][j] < min )
						x = j, y = k, min = workTime[j][k];
		
		workTable[y] = x, staffTable[x] = y;
		sum += min;
	}
	printf ( "%d\n", sum );
	
	return 0;
}

