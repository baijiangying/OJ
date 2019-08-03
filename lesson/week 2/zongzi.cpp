#include <cstdio>
#include <iostream>

template <typename T> class Stack {
private:
	int _size,  _capacity;
	T* _elem;
public:
	~Stack() { delete[] _elem; }
	Stack ( int c );
	void push ( const T& );
	int size() { return _size; }
	T& top();
	T& pop();
};

template <typename T> Stack<T>::Stack ( int c ) {
	_size = 0, _capacity = c;
	_elem = new T[_capacity];
	for ( int i = 0; i != _capacity; ++i )
		_elem[i] = 0;
}


template <typename T> void Stack<T>::push ( const T& e ) {
	_elem[_size++] = e;
}

template <typename T> T& Stack<T>::pop() {
	if ( _size-- ) {
		return _elem[_size];
	}
}

template <typename T> T& Stack<T>::top() {
	if ( _size ) 
		return _elem[_size - 1];
}

struct Edge {
	int v;
	bool visited = false;
	Edge* next = nullptr;
	Edge() {}
	Edge ( int w ) : v ( w ) {}
};

struct Vertex {
	bool visited, discovered, reach;
	int price;
	Edge* next;
	Edge* e;
	Vertex () {
		visited = discovered = reach = false;
		price = 0;
		next = nullptr;
		Edge* e = next;
		while ( e ) { e -> visited = false; e =  e -> next; }
	}
	Edge* nextEdge() {
		e = next;
		while ( e && e -> visited ) 
			e = e -> next;
		if ( e )e -> visited = true;
		return e;
	}
};

struct node {
	int v;
	int back = 0;
	node() {};
	node ( int v1, int b ) : v ( v1 ), back ( b ) {}
};

int solve ( Vertex*, int );
void max ( node*, Vertex*, int&, int, int );

int main() {
	//freopen ( "2.in", "r", stdin );
	int n, m;
	scanf ( "%d%d", &n, &m );
	Vertex* city = new Vertex[n + 1];
	for ( int i = 1; i != n + 1; ++i )
		scanf ( "%d", &city[i].price );
	for ( int i = 0; i != m; ++i ) {
		int u, v;
		scanf ( "%d%d", &u, &v );
		Edge* e =  city[u].next;
		if ( e ) {
			while ( e -> next ) e = e -> next;
			e -> next = new Edge ( v );
		}
		else {
			Edge* & firstE = city[u].next;
			firstE = new Edge ( v );
		}
	}
	//////测试语段
	// for ( int i = 1; i != n + 1; ++i ) {
	// 	std::cout << i << "->";
	// 	Edge* e;
	// 	while ( e = city[i].nextEdge() )
	// 		std::cout << e -> v << " ";
	// 	std::cout << std::endl;
	// }

	printf ( "%d\n", solve ( city, n + 1 ) );
	return 0;
}

int solve ( Vertex* v, int n ) {
	int result = 0;
	node* path = new node[n];
	int step = 0;
	path[step] = node ( 1, 0 ); //path用来存储当前路径
	Edge* e = v[1].next;
	v[1].discovered = true;
	Stack<int> s ( n );
	s.push ( 1 );
	while ( s.size() ) {
		Edge* e;
		while ( e = v[s.top()].nextEdge() ) {
			if ( !v[e -> v].discovered ) {
				v[e -> v].discovered = true;
				s.push ( e -> v );
				path[++step] = node ( e -> v, 0 );
				if ( e -> v == n - 1 )
					max ( path, v, result, step, n );
			}
			else if ( v[e -> v].discovered ) {
				if ( !v[e -> v].visited ) {
					path[step].back = e -> v;
					if ( v[e -> v].reach )
						max ( path, v, result, step, n );
				}
			}
		}
		v[s.top()].visited = true;
		s.pop(), --step;
	}
	max ( path, v, result, step, n );
	return result;
}

void max ( node* path, Vertex* v, int& r , int step, int n ) {
	int result = 0, profit = 0;
	node* p = new node[step + 1];
	for ( int i = 0; i != step + 1; ++i ) {
		v[path[i].v].reach = true, p[i] = path[i];
	}
	int count = 0, reach = false;
	for ( int cur = 1, pre = 0; cur != step + 1; ) {
		profit += ( v[p[cur].v].price - v[p[pre].v].price );
		pre = cur;
		if ( profit < 0 ) profit = 0;
		if ( profit > result ) result = profit;
		if ( p[cur].back ) {
			int&b = p[cur].back;
			while( p[--cur].v != b );
			b = 0;
		}
		else ++cur;
	}
	if ( result > r ) r = result;
}