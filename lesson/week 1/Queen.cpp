#include <iostream>

#include "../Vector/Vector.h"
#include "Stack.h"

struct Queen {
	int x, y;
	Queen ( int xx = 0, int yy= 0 ) : x ( xx ), y ( yy ) {};
	bool operator== ( Queen const& q ) const {
		return ( x == q.x )
			   || ( y == q.y )
			   || ( x + y == q.x + q.y )
			   || ( x - y == q.x - q.y );
	}
	bool operator!= ( Queen const& q ) const {
		return ! ( *this == q );
	}
};

void placeQueen ( int n, Stack<Queen>& solu, int** chessBoard ) {
	int i = 0, j = 0;		//Queen的坐标
	
	while ( solu.size() != n ) {     //栈内有n个互异Queen问题即得解。
		Queen q ( i, j );	
		//坐标(i,j)可放下皇后时将该坐标入栈，换下一行，否则换下一列。		
		( solu.find ( q ) == -1 && !chessBoard[i][j] ) ? solu.push ( q ), ++j, i = 0 : ++i;
		//假如每一列都不能放下Queen，解失败，回退至可以向右移动的解。
		if ( i == n ) { 
			while ( ( q = solu.pop() ).x == ( n - 1 ) );
			i = ++q.x, j =q.y; 
		}
	}
}

int main() {
	int n;
	std::cin >> n; 
	Stack<Queen> solu ;
	int** chessBoard = new int*[n];
	for ( int i = 0; i != n; ++i )
		for ( int j = 0; j != n; ++j )
			std::cin >> chessBoard[i][j];
	placeQueen ( n, solu， chessBoard );

	return 0;
}

