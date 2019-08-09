#include <cstdio>
#include "Queue.h"
#include <iostream>

struct State {

public:
	int nMax, mMax;
	int n, m;
	State ( int nn = 0, int mm = 0 ) {
		nMax = nn; mMax = mm;
		n = m = 0;
	}
	void toN() { n = nMax; }
	void toM() { m = mMax; }
	void NtoM();
	void MtoN();
	void Mto0() { n = 0; }
	void Nto0() { m = 0; }
	int op ( int i ) {
		switch ( i ) {
			case 0: toN(); break;
			case 1: toM(); break;
			case 2: NtoM(); break;
			case 3: MtoN(); break;
			case 4: Mto0(); break;
			case 5: Nto0(); break;
			default : break;
		}
		return n + m;
	}
	int get() { return n + m; }
	void operator= ( State const& s ) {
		nMax = s.nMax; mMax = s.mMax;
		n = s.n; m = s.m;
	}
};

void State::MtoN() {
	if ( nMax - n > m ) { n += m; m = 0; }
	else {  m -= ( nMax - n ); n = nMax; }
}

void State::NtoM() {
	if ( mMax - m > n ) { m += n; n = 0; }
	else { n -= ( mMax - m ); m = mMax;  }
}

int solve ( int, int, int, int );
void swap ( int&, int& );
int ans ( const int& );

int main() {
	int n, m, t, d;
	scanf ( "%d%d%d%d", &n, &m, &t, &d );
	if ( n < m ) swap ( n, m );

	printf ( "%d\n", solve ( n, m, t, d) );
	return 0;
}

int solve ( int n, int m, int t, int d ) {
	int result = d;
	int** mark = new int*[n + 1];
	for ( int i = 0; i != n + 1; ++i ) {
		mark[i] = new int[m + 1];
		for ( int k = 0; k != m + 1; ++k )
			mark[i][k] = 0;
	}
	Queue<State> q1, q2;
	State s ( n, m );
	q1.enqueue ( s );
	mark[s.n][s.m] = 1;
	int level = 0;
	while ( ( q1.size() || q2.size() ) && level <= t + 1 ) {
		while ( q1.size() ) {
			for ( int i = 0; i != 6; ++i ) {
				State s = q1.front();
				s.op( i );
				if ( !mark[s.n][s.m] ) {
					q2.enqueue ( s ), mark[s.n][s.m] = 1;
				}
				if ( ans ( s.get() - d ) < result )
					result = ans ( s.get() - d ); 
			}
			q1.dequeue ( true );
			if ( !result ) break;
		}
		++level; if ( level == t || !result ) break;
		while ( q2.size() ) {
			for ( int i = 0; i != 6; ++i ) {
				State s = q2.front();
				s.op( i );
				if ( !mark[s.n][s.m] ) {
					q1.enqueue ( s ), mark[s.n][s.m] = 1;
				}
				if ( ans ( s.get() - d ) < result )
					result = ans ( s.get() - d ); 
			}
			q2.dequeue ( true );
			if ( !result ) break;
		}
		++level; if ( level == t || !result ) break;
	}
	return result;
}

void swap ( int& a, int& b ) {
	a = a + b;
	b = a - b;
	a = a - b;
}

int ans ( const int& a ) { return ( a < 0 ? -a : a ); }