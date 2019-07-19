#ifndef UNION_FIND_H
#define UNION_FIND_H

typedef int Rank;

struct node {
	Rank parent;
	int size = 0;
};

class UnionFind {
// private:
// 	int _size;
// 	node* _elem;
public:
	int _size;
	node* _elem;
	UnionFind ( int size ) { 
		_elem = new node[size]; 
		for (int i = 0; i != size; ++i ) _elem[i].parent = i; 
	}
	Rank find ( Rank i );
	void unit ( Rank i, Rank j );
};

Rank UnionFind::find ( Rank i ) {
	Rank _hot = _elem[i].parent;
	//std::cout << "_hot " << _hot << " i " << i << std::endl;   // _hot指向待查找的节点的父亲
	if ( _hot == i ) return i; //如果待查找的节点父亲是根节点或者待查找节点是根节点
	else if ( _hot == _elem[_hot].parent ) 
			return _hot;
		else{
		_elem[i].parent == _elem[_hot].parent, _elem[_hot].size += ( _elem[i].size + 1 );	//将以待查找节点为根的子树提升一层
		return find ( _hot );
	}
}

void UnionFind::unit ( Rank i, Rank j ) {
	Rank iParent = find ( i ), jParent = find ( j );
	if ( iParent == jParent )
		return;
	else {
		if ( _elem[iParent].size < _elem[jParent].size ) {
			_elem[iParent].parent = jParent;
			_elem[jParent].size += _elem[iParent].size;
		}
		else {
			_elem[jParent].parent = iParent;
			_elem[iParent].size += _elem[jParent].size;
		}
	}
}


#endif