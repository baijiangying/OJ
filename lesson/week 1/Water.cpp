#include <cstdio>
#include <iostream>

static int count = 0;
int solu[100];
struct State {
	int A = 8;
	int B = 0;
	int C = 0;
} state;
typedef int ( *PMF ) ( State& );

int AtoB ( State& state ) { 
	if ( state.A > ( 5 - state.B ) )
		state.A -= ( 5 - state.B ), state.B = 5;
	else 
		state.B += state.A, state.A = 0;
	return 0;
}
int BtoA ( State& state ) {
	if ( state.B > ( 8 - state.A ) )
		state.B -= ( 8 - state.A ), state.A = 8;
	else
		state.A += state.B, state.B = 0;
	return 0;
}
int AtoC ( State& state ) { 
	if ( state.A > ( 3 - state.C ) )
		state.A -= ( 3 - state.C ), state.C = 3;
	else 
		state.C += state.A, state.A = 0;
	return 0;
}
int CtoA ( State& state ) {
	if ( state.C > ( 8 - state.A ) )
		state.C -= ( 8 - state.A ), state.A = 8;
	else
		state.A += state.C, state.C = 0;
	return 0;
}
int BtoC ( State& state ) { 
	if ( state.B > ( 3 - state.C ) )
		state.B -= ( 3 - state.C ), state.C = 3;
	else 
		state.C += state.B, state.B = 0;
	return 0;
}
int CtoB ( State& state ) {
	if ( state.C > ( 5 - state.B ) )
		state.C -= ( 5 - state.B ), state.B = 5;
	else
		state.B += state.C, state.C = 0;
	return 0;
}
PMF pour[] = { AtoB, AtoC, BtoC,
			   BtoA, CtoA, CtoB };

bool done = false;

bool IsBack ( State state, bool markTable[9][6][4] ) { 
	return markTable[state.A][state.B][state.C];
}

void mark ( State state, bool markTable[9][6][4] ) {
	markTable[state.A][state.B][state.C] = 1;
}

void pouring ( int step, State state, bool markTable[9][6][4] ) {
	if ( done ) return;
	if ( state.A == 4 && state.B == 4 ) {
		done = true, printf ( "%d\n", step );
		for ( int i = 0; i != step; ++i ) 
			switch ( solu[i] ) {
				case 0: printf ( "%c%c%c\n", 'A', ' ', 'B' ); break;
				case 1: printf ( "%c%c%c\n", 'A', ' ', 'C' ); break;
				case 2: printf ( "%c%c%c\n", 'B', ' ', 'C' ); break;
				case 3: printf ( "%c%c%c\n", 'B', ' ', 'A' ); break;
				case 4: printf ( "%c%c%c\n", 'C', ' ', 'A' ); break;
				case 5: printf ( "%c%c%c\n", 'C', ' ', 'B' ); break;
			}

		return;
	}
	int newStep = step + 1;
	State newState = state;
	bool newMark[9][6][4];
	for ( int i = 0; i != 216; ++i ) 
		* ( ( **newMark) + i ) = * ( ( **markTable) + i );
	for ( int i = 0; i != 6; ++i ) {
		if ( done ) continue;
		pour[i] ( newState );
		if ( IsBack ( newState, markTable ) ) { newState = state; continue; }

		mark ( newState, newMark );
		solu[step] = i;
		pouring ( newStep, newState, newMark );
	}

}

int main() {
	State state; 
	int step = 0;
	for ( int i = 0; i != 100; ++i ) solu[i] = -1;
	bool markTable[9][6][4];
	for ( int i = 0; i != 216; ++i ) 
		* ( ( **markTable) + i ) = 0;
	markTable[8][0][0] = 1;
	pouring ( step, state, markTable );
	return 0;
}


