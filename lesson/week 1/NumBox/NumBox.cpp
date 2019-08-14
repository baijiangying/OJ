#include <cstdio>
#include "Set.h"

int main() {
	int q ;
	scanf ( "%d", &q );
	Set<long long> s;
	for ( int i = 0; i != q ; ++i ) {
		int op;
		long long opnd;
		scanf ( "%d%lld", &op, &opnd );
		bool succeed = ( op == 1? s.push ( opnd ) : s.pop ( opnd ) );
		printf ( "%s\n", succeed ? "Succeeded" : "Failed" );
	}
}