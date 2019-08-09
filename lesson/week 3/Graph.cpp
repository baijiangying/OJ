#include <cstdio>
#include <iostream>
#include "Stack.h"

struct Edge {
	int v;
	bool visited = false;
	Edge* next = nullptr;
	Edge() {}
	Edge ( int w ) : v ( w ) {}
};

struct Vertex {
	bool visited, discovered, reach;
	int dtime, ftime;
	int degree;
	Edge* next;
	Vertex () {
		visited = discovered = reach = false;
		dtime = ftime = degree = 0;
		next = nullptr;
		Edge* e = next;
		while ( e ) { e -> visited = false; e =  e -> next; }
	}
	Edge* nextEdge() {
		Edge* e = next;
		while ( e && e -> visited ) 
			e = e -> next;
		if ( e )e -> visited = true;
		return e;
	}
	void insertE ( int v ) {
		if ( degree ) {
			Edge* e = next;
			while ( e -> next ) e = e -> next;
			e -> next = new Edge ( v );
		}
		else {
			Edge* e = new Edge ( v );
			next = e;
		}
		++degree;
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
		}
		result[i] = check ( vertex, n );
		delete[] vertex;
	}
	for ( int i = 0; i != T; ++i ) {
		printf ( "%d\n", ( result[i] ? 1 : 0 ) );
	}
}

bool check ( Vertex* vertex, int n ) {
	int clock = 0;
	if ( !vertex[1].discovered ) {
		vertex[1].discovered = true;
		vertex[1].dtime = ++clock;
		Stack<Vertex> s ( n );
		s.push ( vertex[1] );
		Edge* e = nullptr;
		while ( e = s.top().nextEdge() ) {
			if ( !vertex[e -> v].discovered ) {
				vertex[e -> v].discovered = true;
				vertex[e -> v].dtime = ++clock;
				s.push ( vertex[e -> v] );
			}
			else if ( vertex[e -> v].discovered ) {
				if ( vertex[e -> v].dtime < clock )
					return false;
			}
		}
	}
	for ( int i = 1; i != n + 1; ++i )
		if ( !vertex[i].discovered ) return false;
	return true;
}