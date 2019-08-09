#include <cstdio>
#include <iostream>

#define LEFT -1
#define RIGHT 1

struct Rank {
	int rank;
	int direction;
	int xRank() { return rank + direction; }
};

void printSJT ( int, int );
void swap ( int&, int&, Rank* );

int main() {
	int n, k;
	scanf ( "%d%d", &n, &k );

	printSJT ( n, k );
	return 0;
}

void printSJT ( int n, int k ) {
	int* permutation = new int[n];
	Rank* rankTable =  new Rank[n + 1];
	for ( int i = 0; i != n; ++i ) 
		permutation[i] = i + 1, rankTable[i + 1] = Rank { i, LEFT };
	for ( int i = 1; i != k; ++i ) {
		int r = n;
		while ( rankTable[r].xRank() == n || rankTable[r].xRank() == -1 ||
			    permutation[rankTable[r].rank] < permutation[rankTable[r].xRank()] )
			--r;
		for ( int i = r + 1; i != n + 1; ++i )
			rankTable[i].direction = -rankTable[i].direction;
		swap ( permutation[rankTable[r].rank], permutation[rankTable[r].xRank()], rankTable );
	}
	printf ( "%d", permutation[0] );
	for ( int i = 1; i != n; ++i )
		printf ( "%c%d", ' ', permutation[i] );
	printf ( "\n" );
}

void swap ( int& a, int& b, Rank* r ) {
	a += b; b = a - b; a -= b;
	r[a].rank += r[b].rank; 
	r[b].rank = r[a].rank - r[b].rank;
	r[a].rank -= r[b].rank;
}
