#ifndef STACK_H
#define STACK_H


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

#endif