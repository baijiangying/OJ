#include <cstdio>

int sail ( int*, int, int* );
bool IsValid ( int* );
bool IsSafe ( int* );
bool IsFoward ( int*, int* );
void move ( int*, int , int );
void mark ( int*, int* );


char table[4] = { 'H', 'W', 'S', 'V' };
bool done = false;
int solu[100];

int main() {
	int east[4] = { 1, 1, 1, 1 };
	int markTable[16]; 
	for ( int i = 0; i != 16; ++i ) markTable[i] = 1; 
	sail( east, 0, markTable );
	return 0;
}

int sail( int* east, int step, int* markTable ) {
	if ( done ) return 0;
	else if ( !east[0] && !east[1] &&
		 !east[2] && !east[3] ) {
		for ( int i = 0; i != step; ++i ) {
			if ( solu[i] )
				printf ( "%c%c%c", table[0], table[solu[i]], ' ' );
			else
				printf ( "%c%c", table[0], ' ' );
		}
		done = true;
		printf ( "\n" );
		return 0;
	}
	else if ( !done ) {
		for ( int i = 0; i != 4; ++i ) {
			if ( done ) continue;
			int newEast[4], newMark[16], newStep = step + 1;
			for ( int i = 0; i != 4; ++i ) 
				newEast[i] = east[i];
			for ( int i = 0; i != 16; ++i ) 
				* ( newMark + i ) = * ( markTable + i ); 
			move ( newEast, i, step ), mark ( newMark, newEast );
			if ( !IsValid ( newEast ) ) continue; 
			if ( !IsSafe ( newEast ) ) continue; 
			if ( !IsFoward ( newMark, newEast ) ) continue; 

			sail ( newEast, newStep, newMark );

		}
	}

}

void move ( int* east, int i, int step ) {
	if ( step % 2 ) {
			solu[step] = i;
			east[0] = 1; east[i] = 1;
	}
	else {
		solu[step] = i;
		east[0] = 0, east[i] = 0;
	}
}

void mark ( int* markTable, int* east ) { 
	int rank = 0;
	for ( int i = 0; i != 4; ++i )
		rank += ( ( east[i] ) << ( 3 - i ) );
	--markTable[rank]; 
}

bool IsValid ( int* east ) {
	for ( int i = 0; i != 4; ++i ) 
		if ( ( east[i] > 1 || east[i] < 0 ) ||
			 ( east[i] > 1 || east[i] < 0 ) )
			return false;
	return true;
}

bool IsSafe ( int* east ) {
	for ( int i = 1; i != 3; ++i ) {
		if ( !east[0] && east[i] && east[i + 1] ) return false;
		else if ( east[0] && !east[i] && !east[i + 1] )
			return false; 
	}
	return true;
}

bool IsFoward ( int* markTable, int* east ) {
	int rank = 0;
	for ( int i = 0; i != 4; ++i )
		rank += ( ( east[i] ) << ( 3 - i ) );
	return !markTable[rank] ;
}