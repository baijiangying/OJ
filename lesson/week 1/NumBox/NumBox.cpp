#include <bits/stdc++.h>
#include <set>
#include "Set.h"

int main() {
	int q;
	scanf ( "%d", &q );
	Set s ( q );
	for ( int i = 0; i != q; ++i ) {
		int op;
		long long opnd;
		scanf ( "%d%lld", &op, &opnd );
		bool succeed = ( op == 1? s.push ( opnd ) : s.pop ( opnd ) );
		puts ( succeed ? "Succeeded" : "Failed" );
	}
}