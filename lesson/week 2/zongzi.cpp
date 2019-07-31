#include <cstdio>

struct Edge {
	int u, v;
	int weight;
	Edge* next;
}

int main() {
	int n, m;
	scanf ( "%d%d", &n, &m );
	int* price = new int[n + 1];
	for ( int i = 1; i != n + 1; ++i )
		scanf ( "%d", &price[i] );
	Edge** vertex = new Edge*[m + 1];
	for ( int i = 1; i != m + 1; ++i ) {
		Edge* e = vertex[i];
		while ( e -> next != null ) e = vertex[i] -> next;
		
	}
}