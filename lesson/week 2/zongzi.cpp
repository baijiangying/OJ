#include <cstdio>
#include <iostream>
#include "Stack.h"
#include <limits.h>


struct Edge {
	int v;
	Edge* next = nullptr;
	Edge() {}
	Edge ( int w ) : v ( w ) {}
};

struct Vertex {
	bool visited;
	int price,outDegree, c;
	int minCost, maxPrice;
	Edge* next;
	Edge* e;
	Vertex () {
		visited = false;
		price = outDegree = c = 0;
		minCost = INT_MAX; maxPrice = INT_MIN;
		next = nullptr;
		Edge* e = next;
	}
	Edge* nextEdge() {
		if ( outDegree ) {
			e = next;
			for ( int i = 1; i != c; ++i )
				e = e -> next;
			--c;
			if ( !c ) c += outDegree;
			return e;
		}
	}
	void insertE ( int  v ) {
		if ( outDegree ) {
			Edge* e = next;
			for ( int i = 0; i != outDegree; ++i ) {
				if ( e -> v == v ) return;
				e = e -> next;
			}
			e = next;
			while ( e -> next ) e = e -> next;
			e -> next = new Edge ( v );
		}
		else {
			next = new Edge ( v );
		}
		++outDegree;
		c = outDegree;
	}
};

int min ( const int& a, const int& b ) { return ( a < b ? a : b ); }
int max ( const int& a, const int& b ) { return ( a > b ? a : b ); }

int solve ( Vertex*, Vertex*, int );

int main() {
	//freopen ( "2.in", "r", stdin);
	int n, m;
	scanf ( "%d%d", &n, &m );
	Vertex* city = new Vertex[n + 1];
	Vertex* city_ = new Vertex[n + 1];
	for ( int i = 1; i != n + 1; ++i ) {
		scanf ( "%d", &city[i].price );
		city_[i].price = city[i].price;
	}
	for ( int i = 0; i != m; ++i ) {
		int u, v;
		scanf ( "%d%d", &u, &v );
		city[u].insertE ( v );
		city_[v].insertE ( u );
	}
	printf ( "%d\n", solve ( city, city_, n ) );
	return 0;
}

int solve ( Vertex* city, Vertex* city_, int n ) {
	int result = 0;
	city[1].minCost = city[1].maxPrice = city[1].price;
	Stack<int> s ( 5 * n );
	s.push ( 1 );
	city[1].visited = true;
	while ( s.size() ) {
		Edge* e;
		int count = 0;
		while ( e = city[s.top()].nextEdge() ) {
			if ( city[e -> v].minCost > city[s.top()].minCost ) {
				city[e -> v].minCost = min ( city[s.top()].minCost, city[e -> v].price );
				s.push ( e -> v ), count = 0;
			}
			else {
				++count;
				if ( count == city[s.top()].outDegree + 1 ) break;
			}
		}
		city[s.top()].visited = true;
		s.pop();
		int c = 0;
	}
	
	if ( city[n].minCost != INT_MAX ) {
		s.push ( n );
		city_[n].visited = true;
		city_[n].minCost = city_[n].maxPrice = city_[n].price;
		while ( s.size() ) {
			Edge* e;
			int count = 0;
			while ( e = city_[s.top()].nextEdge() ) {
				if ( city_[e -> v].maxPrice < city_[s.top()].maxPrice ) {
					city_[e -> v].maxPrice = max ( city_[s.top()].maxPrice, city_[e -> v].price );
					s.push ( e -> v ), count = 0;
				}
				else {
					++count;
					if ( count == city_[s.top()].outDegree + 1 ) break;
				}
			}
			city_[s.top()].visited = true;
			s.pop();
			int c = 0;
		}
		for ( int i = 1; i != n + 1; ++i ) 
			if ( city[i].visited && city_[i].visited )
				result = max ( city_[i].maxPrice - city[i].minCost, result );
		return result;
	}
	else return 0;
}

