#include <cstdio>

int main() {
	setvbuf ( stdin, new char[1 << 20],_IOFBF, 1 << 20 );
	setvbuf ( stdout, new char[1 << 20],_IOFBF, 1 << 20 );

	int n = 0;
	std::scanf ( "%d", &n );
	for ( int i = 0; i != n; ++i ) {
		int A = 0, B = 0;
		scanf ( "%d%d", &A, &B );
		printf ( "%d\n", A + B );
	}
}