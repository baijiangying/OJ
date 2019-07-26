#ifndef SET_H
#define SET_H

class Set {
private:
	long long* _elem;
	long long prime[19] = { 101, 211, 433, 877,
					1619,3460,6841,12659,
					21121,45461,90217,187433,
					253433,427433,568433,639433,
					756433, 997433 };
	long long _size = 0;
	long long _capacity = 433;
	inline long long hash ( long long key, int i );
	inline long long rehash ( long long key );

public:
	Set ( long long c );
	~Set() { delete _elem; }
	bool inSet ( long long key );
	bool push ( long long key );
	bool pop ( long long key );
};

Set::Set ( long long c ) {
	for ( long long i = 0; i != 18; ++i ) {
		if ( ( _capacity = prime[i] ) > ( c << 1 ) ) break;
	}
	_capacity = 997433;
	_elem = new long long[_capacity];
	for ( long long i = 0; i != _capacity; ++i ) 
		_elem[i] = -2;
}

inline long long Set::hash ( long long key, int i ) {
	long long r = ( ( ( 2 * key + 123433 ) % _capacity ) +
					i * rehash ( key ) ) % _capacity;
	return r;
}

inline long long Set::rehash ( long long key ) {
	long long r = ( 3 * key + 433 ) % _capacity;
	return r;
}

bool Set::inSet ( long long key ) {
	for( int i = 0; ; ++i ) {
		long long r = hash ( key, i );
		if ( _elem[r] == -2 ) return false;
		else if ( _elem[r] == key ) return true;
	}
}

bool Set::push ( long long key ) {
	for ( int i = 0; ; ++i ) {
		long long r = hash ( key, i );
		if ( _elem[r] == -2 || _elem[r] == -1 ) {
			_elem[r] = key;
			return true;
		}
		else if ( _elem[r] == key ) 
			return false;
		for ( int j = 0; j != i; ++j ) {
			if ( r == hash ( key, j ) )
				std::cout << "Big Error! BIG TROUBLE!!!" << std::endl;
		}
	}
}

bool Set::pop ( long long key ) {
	for ( int i = 0; ; ++i ) {
		long long r = hash ( key, i );
		if ( _elem[r] == -2 ) 
			return false;
		else if ( _elem[r] == key ) {
			_elem[r] = -1;
			return true;
		}
	}
}



#endif