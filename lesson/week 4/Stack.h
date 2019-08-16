#ifndef STACK_H
#define STACK_H

#define DEFAULT_CAPACITY 123433

template <typename T> class Stack {
private:
	int _size,  _capacity;
	T* _elem;
	void expand();
public:
	~Stack() { delete[] _elem; }
	Stack();
	void push ( const T& );
	int size() { return _size; }
	T& top();
	T& subTop();
	T& pop();
};

template <typename T> void Stack<T>::expand() {
	if ( _size == _capacity ) {
		_capacity = _size * 2;
		T* oldElem = _elem;
		_elem = new T[_capacity];
		for ( int i = 0; i != _size; ++i )
			_elem[i] = oldElem[i];
		delete[] oldElem;
	}
}

template <typename T> Stack<T>::Stack() {
	_size = 0, _capacity = DEFAULT_CAPACITY;
	_elem = new T[_capacity];
	// for ( int i = 0; i != _capacity; ++i )
	// 	_elem[i] = 0;
}


template <typename T> void Stack<T>::push ( const T& e ) {
	//expand();
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

template <typename T> T& Stack<T>::subTop() {
	if ( _size > 1 ) 
		return _elem[_size - 2];
}

#endif