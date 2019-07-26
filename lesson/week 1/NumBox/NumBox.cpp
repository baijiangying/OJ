#include <bits/stdc++.h>
#include <set>
#include "Set.h"

int main() {
	srand ( time ( nullptr ) );
	int c = 0;
	while ( 1 ) {
		
		int q = rand() % 500000;
	
		Set s1 ( q );
		std::set<long long> s;
		int count  = 0;
		for ( int i = 0; i != q; ++i ) {
			int n = rand() % 2 + 1;
			long long m = rand();
			bool succeeded1 = ( n == 1 ? s1.push ( m ) : s1.pop ( m ) );
			bool succeeded;
			if ( n == 1 ) {
				if ( s.find ( m ) != s.end() ) succeeded = false;
				else { succeeded = true; s.insert ( m ); }
			}
			else {
				if ( s.find ( m ) != s.end() ) { succeeded = true; s.erase ( m ); }
				else succeeded = false;
			}
			if ( succeeded != succeeded1 ) ++count;
			
		}
		std::cout << ++c << " " << q << " " << count << std::endl;
	}
	return 0;
}

// int main() {
// 	int q;
// 	scanf ( "%d", &q );
// 	Set s ( q );
// 	for ( int i = 0; i != q; ++i ) {
// 		int op;
// 		long long opnd;
// 		scanf ( "%d%lld", &op, &opnd );
// 		bool succeed = ( op == 1? s.push ( opnd ) : s.pop ( opnd ) );
// 		puts ( succeed ? "Succeed" : "Failed" );
// 	}
// }