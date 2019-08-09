#include <cstdio>
#include <iostream>

struct Edge {
	int v;
	Edge* next;
	Edge ( int u ) : v ( u ), next ( nullptr ) {}
};

struct Vertex {
	bool visited = false;
	int outDegree = 0, inDegree = 0;
	Edge* next = nullptr;
	void insertE ( int  v ) {
		if ( outDegree ) {
			Edge* e = next;
			while ( e -> next ) e = e -> next;
			e -> next = new Edge ( v );
		}
		else {
			next = new Edge ( v );
		}
		++outDegree;
	}
	int nextEdge() {
		Edge* e = next; int c = outDegree - 1;
		while ( 0 < c-- ) {
			e = e -> next;
		}
		if ( outDegree ) {
			--outDegree;
			return e -> v;
		}
		return 0;
	}
};

bool check ( Vertex*, int );

int main() {
	int	T, n, m;
	scanf ( "%d", &T );
	bool* result = new bool[T];
	for ( int i = 0; i != T; ++i ) {
		result[i] = 1;
		scanf ( "%d%d", &n, &m );
		Vertex* vertex = new Vertex[n + 1];
		for ( int i = 0; i != m; ++i ) {
			int u, v;
			scanf ( "%d%d", &u, &v );
			vertex[u].insertE ( v );
			++vertex[v].inDegree;
		}
		result[i] = check ( vertex, n );
		delete[] vertex;
	}
	for ( int i = 0; i != T; ++i ) {
		printf ( "%d\n", ( result[i] ? 1 : 0 ) );
	}
}

bool check ( Vertex* vertex, int n ) {
	int c = 0, u = 0;
	for ( int i = 1; i != n + 1; ++i ) 
		if ( !vertex[i].inDegree ) u  = i, ++c;
	if ( c != 1 ) return false;
	while ( vertex[u].outDegree ) {
		int c = 0, t = 0, v = 0;
		while ( v = vertex[u].nextEdge() ) {
			--vertex[v].inDegree;
			if ( !vertex[v].inDegree )
				++c, t = v;
		}
		if ( c != 1 ) return false;
		vertex[u].visited = true;
		u = t;
	}
	vertex[u].visited = true;
 	for ( int i = 1; i != n + 1; ++i )
		if ( !vertex[u].visited ) return false; 
	return true;
}