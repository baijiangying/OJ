#ifndef SET_H
#define SET_H

#define Default 123433
#define P 1e20 + 7

// const int prime[] = {
// 	52433, 123433, 243433, 463433, 999433
// };

template <typename T> struct Entry {
	T data;
	Entry<T>* next;
	Entry ( T e ) { data = e; next = nullptr; }
};

template <typename T> class Set {
private:
	int _capacity, _size;
	Entry<T>** _elem;
	int hash ( T );
	bool deleteNext ( Entry<T>* e );
public:
	Set();
	~Set();
	T* data;
	void init();
	int size() { return _size; }
	bool push ( const T& key );
	bool pop ( const T& key );
	bool inSet ( const T& key );
};

template <typename T> Set<T>::Set() {
	_capacity = Default; _size = 0;
	_elem = new Entry<T>*[_capacity];
	data = new T[_capacity];
	for ( int i = 0; i != _capacity; ++i )
		_elem[i] = 0, data[i] = 0;
}

template <typename T> Set<T>::~Set() {
	for ( int i = 0; i != _capacity; ++i ) {
		if ( _elem[i] ) {
			while ( deleteNext ( _elem[i] ) );
			delete _elem[i];
		}
	}
	delete[] _elem;
}

template <typename T> int Set<T>::hash ( T key ) {
	if ( key < 0 ) key += P;
	return ( key % _capacity * 3 + 65423 ) % _capacity; 	
}

template <typename T> bool Set<T>::deleteNext ( Entry<T>* e ) {
	if ( e -> next ) {
		Entry<T>* p = e -> next;
		e -> next  = p -> next;
		delete p;
		return true;
	}
	return false;
}

template <typename T> void Set<T>::init() {
	_capacity = Default; _size = 0;
	_elem = new Entry<T>*[_capacity];
	data = new T[_capacity];
	for ( int i = 0; i != _capacity; ++i )
		_elem[i] = 0, data[i] = 0;
}

template <typename T> bool Set<T>::push ( const T& key ) {
	int r = hash ( key );
	if ( !_elem[r] ) {
		_elem[r] = new Entry<T> ( key );
		data[_size++] = key;
		return true;
	}
	else {
		Entry<T>* e = _elem[r];
		while ( e -> data != key && e -> next ) e = e -> next;
		if ( !e -> next && e -> data != key ) {
			e -> next  = new Entry<T> ( key );
			data[_size++] = key;
			return true;
		} 
	}
	return false;
}

template <typename T> bool Set<T>::pop ( const T& key ) {
	int r = hash ( key );
	if ( _elem[r] && _elem[r] -> data == key ) {
		Entry<T>* e = _elem[r];
		_elem[r] = e -> next;
		delete e;
		--_size;
		return true;
	}
	else if ( _elem[r] ) {
		Entry<T>* e = _elem[r];
		while ( e -> next && e -> next -> data != key ) 
			e = e -> next;
		if ( e -> next ) { deleteNext ( e ); return true; }
	}
	return false;
}

template <typename T> bool Set<T>::inSet ( const T& key ) {
	int r = hash ( key );
	Entry<T>* e = _elem[r];
	while ( e && e -> data != key ) e = e -> next;
	return e; 
}


#endif