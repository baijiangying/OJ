//贪心策略，有待修正


#include<cstdio>
#include<limits.h>

inline bool	hasWork ( short nameTable, int i ) 
{ return ( nameTable >> i ) & 1 ;}

inline void assignName ( short& nameTable, int i )
{ nameTable | ( 1 << i ); }

inline bool	workDone ( short workTable, int i ) 
{ return ( workTable >> i ) & 1 ;}

inline void assignWork ( short& nameTable, int i )
{ nameTable |= ( 1 << i ); }

int main() {
	int n = 0;
	scanf ( "%d", &n );
	int** workTime = new int*[n];
	for ( int i = 0; i != n; ++i ) { workTime[i] = new int[n]; }
	for( int i = 0; i != n; ++i ) 
		for ( int j = 0; j != n; ++j ) 
			scanf ( "%d", &workTime[i][j] );

	short workTable = 0, nameTable = 0;
	int min = INT_MAX, sum = 0, name = -1, work = -1;
	for ( int i = 0; i !=n; ++i ) {
		if ( hasWork ( nameTable, i ) )
			continue;
		else {
			for ( int j = 0; j != n; ++j )
				if ( workTime[i][j] < min )
					min = workTime[i][j], name = i, work = j;
			assignWork ( workTable, work );
			assignName ( nameTable, name );
			sum += min, min = INT_MAX;
		}
	}

	printf ( "%d\n", sum );
	return 0;
}