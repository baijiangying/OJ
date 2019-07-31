#ifndef MINHEAP_H
#define MINHEAP_H

#define parent(i) ( ( i - 1 ) ) >> 1
#define rchild(i)  ( i + 1 ) << 1
#define lchild(i)  ( rchild(i) ) - 1


class MinHeap {
private:
	int _size, _capacity;
	int* _elem;

public:
	MinHeap ( int );
	void insert ( int );
	int size() { return _size; }
	int pop();
};

MinHeap::MinHeap ( int c ) {
	_size = 0; _capacity = c;
	_elem = new int[_capacity];
	for ( int i = 0; i != _capacity; ++i )
		_elem[i] = 0;
}

void MinHeap::insert ( int d ) {
	_elem[_size++] = d;
	int m = _size - 1;
	while ( m && _elem[m] < _elem[parent(m)] ) 
		std::swap ( _elem[m], _elem[parent(m)] ), m = parent(m);
}

int MinHeap::pop() {
	int min = _elem[0];
	int m = 0;
	std::swap ( _elem[0], _elem[--_size] );
	_elem[_size] = 0;
	while ( lchild(m) < _size || rchild(m) < _size ) {
		if ( lchild(m) < _size && rchild(m) < _size ) {
			if ( _elem[m] > _elem[lchild(m)] ||
				_elem[m] > _elem[rchild(m)] ) 
				_elem[lchild(m)] < _elem[rchild(m)] ? 
				( std::swap ( _elem[lchild(m)], _elem[m] ), m = lchild(m) ) : 
				( std::swap ( _elem[rchild(m)], _elem[m] ), m = rchild(m) ) ;
			else break;
		}
		else if ( lchild(m) < _size ) {
			if ( _elem[m] > _elem[lchild(m)] ) 
				std::swap ( _elem[lchild(m)], _elem[m] ), m = lchild(m);
			else break;
		}
	}
	
	return min;
}


class MaxHeap {
private:
	int _size, _capacity;
	int* _elem;

public:
	MaxHeap ( int );
	void insert ( int );
	int size() { return _size; }
	int pop();
};

MaxHeap::MaxHeap ( int c ) {
	_size = 0; _capacity = c;
	_elem = new int[_capacity];
	for ( int i = 0; i != _capacity; ++i ) _elem[i] = 0;
}

void MaxHeap::insert ( int d ) {
	int m = _size;
	_elem[_size++] = d;
	while ( m && _elem[parent(m)] < _elem[m] ) 
		std::swap ( _elem[parent(m)], _elem[m] ), m = parent(m);
}

int MaxHeap::pop() {
	int max = _elem[0];
	std::swap ( _elem[--_size], _elem[0] );
	_elem[_size] = 0;
	int m = 0;
	while ( lchild(m) < _size || rchild(m) < _size ) {
		if ( lchild(m) < _size && rchild(m) < _size ) {
			if ( _elem[lchild(m)] > _elem[m] || 
				_elem[rchild(m)] > _elem[m] )
				_elem[lchild(m)] > _elem[rchild(m)] ?
				( std::swap ( _elem[lchild(m)], _elem[m] ), m = lchild(m) ) :
				( std::swap ( _elem[rchild(m)], _elem[m] ), m = rchild(m) );
			else 
				break;
		}
		else if ( lchild(m) < _size ) {
			if ( _elem[m] < _elem[lchild(m)] )
				std::swap ( _elem[lchild(m)], _elem[m] ), m = lchild(m);
			else
				break;
		}
	}
	return max;
}

#endif