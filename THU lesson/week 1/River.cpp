#include <cstdio>

void sail( int );
bool IsValid();
bool IsSafe();
bool IsBack();
void move ( int , int );
void mark();

int east[4] = { 1, 1, 1, 1 };
int markTable[2][2][2][2]; 
char table[4] = { 'H', 'W', 'S', 'V' };
bool done = false;
int solu[100];

int main() {
	for ( int i = 0; i != sizeof(markTable); ++i ) **** ( markTable + i ) = 0;
	****markTable = 1; 
	sail( 0 );
	return 0;
}

void sail( int step ) {
	if ( done == true ) return;
	if ( !east[0] && !east[1] &&
		 !east[3] && !east[4] ) {
		for ( int i = 0; i != step; ++i ) {
			if ( solu[i] )
				printf ( "%c%c%c", table[0], table[solu[i]], ' ' );
			else
				printf ( "%c%c", table[0], ' ' );
		}
		done = true;
		scanf ( "\n" );
		return;
	}
	for ( int i = 0; i != 4; ++i ) {
		int oldEast[4], oldMark[2][2][2][2], newStep = step + 1;
		for ( int i = 0; i != 4; ++i ) 
			oldEast[i] = east[i];
		for ( int i = 0; i != sizeof(oldMark); ++i ) 
			**** ( oldMark + i ) = **** ( markTable + i ); 
		move ( i, step ), mark ();
		printf ( "%d%c\n", step, ' ' );
		if ( !IsValid() ) { printf ( "%s\n", "Invalid"); continue; }
		if ( !IsSafe() ) { printf ( "%s\n", "Unsafe"); continue; }
		if ( IsBack() ) { printf ( "%s\n", "Back"); continue; }

		sail ( newStep ), printf ( "%d%c\n", step, ' ' );
		for ( int i = 0; i != 4; ++i ) 
			east[i] = oldEast[i];
		for ( int i = 0; i != sizeof(oldMark); ++i ) 
			**** ( markTable + i ) = **** ( oldMark + i );

	}

}

void move ( int i, int step ) {
	if ( step % 1 ) {
			solu[step] = i;
			east[0] = 1; east[i] = 1;
	}
	else {
		solu[step] = i;
		east[0] = 0, east[i] = 0;
	}
}

void mark() { ++markTable[east[0]][east[1]][east[2]][east[3]]; }

bool IsValid() {
	for ( int i = 0; i != 4; ++i ) 
		if ( ( east[i] > 1 || east[i] < 0 ) ||
			 ( east[i] > 1 || east[i] < 0 ) )
			return false;
	return true;
}

bool IsSafe() {
	for ( int i = 1; i != 3; ++i ) {
		if ( !east[0] && east[i] && east[i + 1] ) return false;
		else if ( east[0] && !east[i] && !east[i + 1] )
			return false; 
	}
	return true;
}

bool IsBack() {
	return ( markTable[east[0]][east[1]][east[2]][east[3]] > 1 );
}