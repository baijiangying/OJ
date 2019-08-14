#ifndef TRIE_H
#define TRIE_H

struct Node {
	char c;
	int size;
	Node* parent;
	Node* sibling;
	Node* child;
	Node ( const char d ) {
		c = d;
		size = 0;
		parent = sibling = child = nullptr;
	}
	Node ( const char d, Node* p, Node* s, Node* ch ) {
		c = d; size = 0;
		parent = p; sibling = s; child = ch; 
	}
};

class Trie{
private:
	Node* _root;
public:
	Trie();
	// ~Trie();
	void insert ( std::string const& );
	// void erase ( char* );
	Node* find ( std::string const& );
	//int postfixNum ( char* );
};

Trie::Trie() {
	_root = new Node ( '\0' );
}

// Trie::~Trie() {

// }

void Trie::insert ( std::string const& s ) {
	Node* x = _root;
	int i = 0;
	for ( ; i != s.size(); ++i ) {
		//层查找
		while ( x -> sibling && x -> c != s[i] )
			x = x -> sibling;
		if ( x -> c == s[i] && x -> child ) //层查找命中并且仍有后缀
			x = x -> child;	//向后缀深入
		else break;  //层查找失败或成功但无后缀，查找到插入点，退出循环。
	}
	if ( i == s.size() ) {
		while ( x -> sibling && x -> c != '\0' )
			x = x -> sibling;
		if ( x -> c != s[i] ) {
			x -> sibling = new Node ( '\0', x -> parent, nullptr, nullptr );
			x = x -> sibling;
		}
		++ ( x -> size ); 
		while ( x -> parent ) ++ ( ( x = x -> parent ) -> size );
		return;
	}
	//判断插入点退出时的状态为层查找失败还是层查找成功
	if ( x -> c == s[i] ) {  //退出时状态为层查找成功
		while ( ++i != s.size() ) {
			x -> child = new Node ( s[i], x, nullptr, nullptr );
			x = x -> child;
		}
		x -> child = new Node ( '\0', x, nullptr, nullptr );
	}
	else if ( x -> c != s[i] ) {   //退出时状态为层查找失败
		x -> sibling = new Node ( s[i], x -> parent, nullptr, nullptr );
		x = x -> sibling;
		while ( ++i != s.size() ) {
			x -> child = new Node ( s[i], x, nullptr, nullptr );
			x = x -> child;
		}
		x -> child = new Node ( '\0', x, nullptr, nullptr );
	}
	++ ( x -> size ); 
	while ( x -> parent ) ++ ( ( x = x -> parent ) -> size );
}

// void Trie::erase ( char* s ) {

// }

Node* Trie::find ( std::string const& s ) {
	Node* x = _root;
	for ( int i = 0; i != s.size(); ++i ) {
		//层查找
		while ( x -> c != s[i] && x -> sibling )
			x = x -> sibling;
		if ( x -> c == s[i] && x -> child ) { //层查找命中并且仍有后缀
			x = x -> child;	//向后缀深入
		}
		else 
			return nullptr; // 层查找失败或成功但无后缀，整个查找失败，返回空。
	}
	return x;
}


#endif