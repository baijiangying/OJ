#include <iostream>
#include <stack>
#include "BinTree.h"


void travPost ( BinNode<int>* );
void travPre ( BinNode<int>* );

int main() {
	std::ios::sync_with_stdio ( false );
	BST<int> bst;
	int n;
	std::cin >> n;
	for ( int i = 0; i != n; ++i ) {
		int m;
		std::cin >> m;
		bst.insert ( m );
	}
	travPre ( bst.root() );
	std::cout << std::endl;
	travPost ( bst.root() );
	std::cout << std::endl;

	return 0;
}

void travPre ( BinNode<int>* x ) {
	std::stack<BinNode<int>*> s;
	while ( x ) {
		std::cout << x -> data << " ";
		s.push ( x -> rchild );
		x = x -> lchild;
	}
	while ( s.size() ) {
		x = s.top(), s.pop();
		while ( x ) {
			std::cout << x -> data << " ";
			s.push ( x -> rchild );
			x = x -> lchild;
		}
	}
}

//迭代版后续遍历
void travPost ( BinNode<int>* x ) {
	//在以x为根的树中寻找后序遍历第一个visit的节点
	std::stack<BinNode<int>*> s;
	while ( x ) {
		s.push ( x );
		//如果有左孩子则当前节点和它的右孩子顺序入栈
		if ( x -> lchild ) {	
			if ( x -> rchild ) s.push ( x -> rchild );
			x = x -> lchild;
		}
		//没有左孩子就转向右孩子
		else 
			x = x -> rchild;
	}
	while ( s.size() ) {
		//弹出该visit的节点
		x = s.top(), s.pop();
		std::cout << x -> data << " ";	//	visit
		//如果此时栈非空并且栈顶不是当前节点的父亲，说明栈顶是当前节点的右兄弟
		if ( s.size() && x -> parent != s.top() ) {
			x = s.top(), s.pop();		//转入右子树以同样的方式遍历右子树
			while ( x ) {
				s.push ( x );
				if ( x -> lchild ) {
					if ( x -> rchild ) s.push ( x -> rchild );
					x = x -> lchild;
				}
				else 
					x = x -> rchild;
			}
		}
	}
}