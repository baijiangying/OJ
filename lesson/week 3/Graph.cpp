#include <cstdio>

struct Vertex {
	int succ = 0;
	int pred = 0;
	bool visited = false;
	// ListNode ( int v1, 
	// ListNode* p = nullptr, ListNode* s = nullptr ) :
	// v ( v1 ), pred ( p ), succ ( s ) {}
};

int main() {
	int	T, n, m;
	scanf ( "%d", &T );
	bool* result = new bool[T];
	for ( int i = 0; i != T; ++i ) {
		result[i] = 1;
		scanf ( "%d%d", &n, &m );
		Vertex* vertex = new Vertex[n + 1];
		for ( int j = 0; j != m; ++j ) {
			int u, v;
			scanf ( "%d%d", &u, &v );
			if ( vertex[u].succ ) { result[i] = 0; }
			if ( vertex[v].pred ) { result[i] = 0; }
			vertex[u].succ = v;
			vertex[v].pred = u;
			vertex[u].visited = true;
		}
		for ( int i = 1; i != n + 1; ++i )
			if ( !vertex[i].visited ) {
				result[i] = 0; break;
			}
	}
	for ( int i = 0; i != T; ++i ) {
		printf ( "%d\n", result[i] );
	}
}