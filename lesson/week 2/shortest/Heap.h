#ifndef HEAP_H
#define HEAP_H

#define parent(i) ( ( i - 1 ) ) >> 1
#define rchild(i)  ( i + 1 ) << 1
#define lchild(i)  ( rchild(i) ) - 1


template <typename T> void swap ( T& a, T& b ) {
	T tmp = a;
	a = b;
	b = tmp;
}


template <typename T> class MinHeap {
private:
	int _size, _capacity;
	T* _elem;

public:
	MinHeap ( int );
	void insert ( const T& );
	int size() { return _size; }
	T& pop();
};

template <typename T> MinHeap<T>::MinHeap ( int c ) {
	_size = 0; _capacity = c;
	_elem = new T[_capacity];
	for ( int i = 0; i != _capacity; ++i )
		_elem[i] = 0;
}

template <typename T> void MinHeap<T>::insert ( const T& d ) {
	_elem[_size++] = d;
	int m = _size - 1;
	while ( m && _elem[m] < _elem[parent(m)] ) 
		swap ( _elem[m], _elem[parent(m)] ), m = parent(m);
}

template <typename T> T& MinHeap<T>::pop() {
	T min = _elem[0];
	T m = 0;
	swap ( _elem[0], _elem[--_size] );
	_elem[_size] = 0;
	while ( lchild(m) < _size || rchild(m) < _size ) {
		if ( lchild(m) < _size && rchild(m) < _size ) {
			if ( _elem[m] > _elem[lchild(m)] ||
				_elem[m] > _elem[rchild(m)] ) 
				_elem[lchild(m)] < _elem[rchild(m)] ? 
				( swap ( _elem[lchild(m)], _elem[m] ), m = lchild(m) ) : 
				( swap ( _elem[rchild(m)], _elem[m] ), m = rchild(m) ) ;
			else break;
		}
		else if ( lchild(m) < _size ) {
			if ( _elem[m] > _elem[lchild(m)] ) 
				swap ( _elem[lchild(m)], _elem[m] ), m = lchild(m);
			else break;
		}
	}
	
	return min;
}


template <typename T> class MaxHeap {
private:
	int _size, _capacity;
	T* _elem;

public:
	MaxHeap ( int );
	void insert ( const T& );
	int size() { return _size; }
	T& pop();
};

template <typename T> MaxHeap<T>::MaxHeap ( int c ) {
	_size = 0; _capacity = c;
	_elem = new T[_capacity];
	for ( int i = 0; i != _capacity; ++i ) _elem[i] = 0;
}

template <typename T> void MaxHeap<T>::insert ( const T& d ) {
	int m = _size;
	_elem[_size++] = d;
	while ( m && _elem[parent(m)] < _elem[m] ) 
		swap ( _elem[parent(m)], _elem[m] ), m = parent(m);
}

template <typename T> T& MaxHeap<T>::pop() {
	T max = _elem[0];
	swap ( _elem[--_size], _elem[0] );
	_elem[_size] = 0;
	T m = 0;
	while ( lchild(m) < _size || rchild(m) < _size ) {
		if ( lchild(m) < _size && rchild(m) < _size ) {
			if ( _elem[lchild(m)] > _elem[m] || 
				_elem[rchild(m)] > _elem[m] )
				_elem[lchild(m)] > _elem[rchild(m)] ?
				( swap ( _elem[lchild(m)], _elem[m] ), m = lchild(m) ) :
				( swap ( _elem[rchild(m)], _elem[m] ), m = rchild(m) );
			else 
				break;
		}
		else if ( lchild(m) < _size ) {
			if ( _elem[m] < _elem[lchild(m)] )
				swap ( _elem[lchild(m)], _elem[m] ), m = lchild(m);
			else
				break;
		}
	}
	return max;
}

#endif