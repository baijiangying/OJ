#ifndef BINTREE_H
#define BINTREE_H

template <typename T> struct BinNode {
	T data = 0;
	BinNode<T>* lchild = nullptr;
	BinNode<T>* rchild = nullptr;
	BinNode<T>* parent = nullptr;
	BinNode ( T e, BinNode<T>* p, BinNode<T>* lc, BinNode<T>* rc ) :
	data ( e ), parent ( p ), lchild ( lc ), rchild ( rc ) {}	
	void insertAsLc ( BinNode<T>*, const T& );
	void insertAsRc ( BinNode<T>*, const T& );
};

template <typename T> 
void BinNode<T>::insertAsLc ( BinNode<T>* p, const T& e ) {
	if ( ! ( this -> lchild ) ) {
		BinNode<T>* x = new BinNode<T> ( e, this, nullptr, nullptr );
		this -> lchild = x;
	}	
}
template <typename T> 
void BinNode<T>::insertAsRc ( BinNode<T>* p, const T& e ) {
	if ( ! ( this -> rchild ) ) {
		BinNode<T>* x = new BinNode<T> ( e, this, nullptr, nullptr );
		this -> rchild = x;
	}	
}


template <typename T> class BST {
private:
	int _size;
	BinNode<T>* _root = nullptr;
	BinNode<T>* _hot = nullptr;

public:
	BinNode<T>* root() { return _root; }
	void insert ( const T& e );
	BinNode<T>* find ( const T& e );
};

template <typename T> 
BinNode<T>* BST<T>::find ( const T& e ) {
	//std::cout << "find " << e << std::endl;
	BinNode<T>* x = _root;
	while ( x && x -> data != e ) {
		_hot = x;
		x = ( ( e < x -> data ) ? x -> lchild : x -> rchild );
	}
	return x;
}

template <typename T> void BST<T>::insert ( const T& e ) {
	//std::cout << "insert " << e << std::endl;
	if ( _root ) {
		BinNode<T>* x = find ( e );
		if ( x ) return;
		else {
			x = new BinNode<T> ( e, _hot, nullptr, nullptr );
			if ( e < _hot -> data ) _hot -> lchild = x;
			else _hot -> rchild = x;
			++_size;
		}
	}
	else {
		_root = new BinNode<T> ( e, nullptr, nullptr, nullptr );
		++_size;
	}
}





#endif