#include <iostream>
#include <limits.h>

bool state[9];
int rank ( bool* );
int solution[100], count = 0;
int c = 0;


void solve ( bool*, bool*, int );
bool solved ( bool* );
int rank ( bool* );

int main() {
	std::ios::sync_with_stdio ( false );
	for ( int i = 0; i != 100; ++i ) solution[i] = INT_MAX;
	int n;
	std::cin >> n;
	for ( int i = 0; i != 9; ++i ) state[i] = 1;
	for ( int i = 0; i != n; ++i ) {
		int m;
		std::cin >> m;
		state[m - 1] = 0;
	}
	bool markTable[512];
	for ( int i = 0; i != 512;++i ) markTable[i] = 0;
	markTable[rank(state)] = 1; 
	int min = INT_MAX;
	solve ( state, markTable, 0 );
	for ( int i = 0; i != count; ++i ) if ( solution[i] < min ) min = solution[i];
	std::cout << min << std::endl;
}

void solve ( bool* state, bool* markTable, int step ) {
	if ( solved ( state ) ) { solution[count++] = step; return; }
	bool newState[9], newMark[512];
	for ( int i = 0; i != 512; ++i ) newMark[i] = markTable[i];
	for ( int i = 0; i != 2; ++i ) {
		for ( int i = 0; i != 9; ++i ) newState[i] = state[i];
		if ( !i ) 
			newState[0] = !newState[0];
		else {
			for ( int i = 0; i != 8; ++i )
				if ( state[i] ) {
					newState[ i + 1 ] = !newState[i + 1];
					break;
				}
		}
		if ( newMark[rank(newState)] ) continue;
		newMark[rank(state)] = 1;
		int newStep = step + 1;
		solve ( newState, newMark, newStep );
	}
}

bool solved ( bool* state ) {
	int sum = 0;
	for ( int i = 0; i != 9; ++i ) sum += state[i];
	return !sum;
}

int rank ( bool* state ) {
	int rank = 0;
	for ( int i = 8; i != -1; --i ) rank += ( state[i] << i );
	return rank;
}