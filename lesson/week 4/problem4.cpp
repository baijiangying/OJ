#include <iostream>
#include <string>

#define P1 19260817
#define P2 19951031

int solve ( const std::string&, int );
bool check ( long long*, int, int, int );
long long* hash ( long long*, int, int, long long );
long long hash ( long long*, int, long long );

int main() {
	std::ios::sync_with_stdio ( false );
	//freopen ( "2.in", "r", stdin );

	std::string s;
	int m;
	std::cin >> s >> m;
	
	std::cout << solve ( s, m ) << std::endl;
	return 0;
}

int solve ( const std::string& s, int m ) {
	int count[26]; for ( int i = 0; i != 26; ++i ) count[i] = 0;
	for ( int i = 0; i != s.size(); ++i ) ++count[s[i] - 'a'];
	int max = 0;
	for ( int i = 0; i != 26; ++i ) if ( count[i] > max ) max = count[i];
	if ( max < m ) return 0;
	
	long long* a = new long long[s.size()];
	for ( int i = 0; i != s.size(); ++i ) a[i] = s[i] - 'a' + 1;

	int lo = 1, hi = s.size() / m + 1;
	while ( lo + 1 < hi ) {
		int mi = ( lo + hi ) >> 1;
		check ( a, s.size(), mi, m ) ? lo = mi : hi = mi;
	}
	return lo;
}

bool check ( long long* a, int n, int mi, int m ) {
	long long* h = hash ( a, n, mi, P1 );

	int* count = new int[P1];
	for ( int i = 0; i != P1; ++i ) count[i] = 0;
	for ( int i = 0; i != n - mi + 1; ++i ) {
		++count[h[i]];
		if ( count[h[i]] == m ) {
			delete[] h;
			delete[] count;
			return true;
		}
	}

	delete[] h;
	delete[] count;
	return false;
}

long long* hash ( long long* a, int n, int m, long long mo ) {
	int exp = 1;
	for ( int i = 0; i != m; ++i ) exp = exp * 43 % mo;
	long long* h = new long long[n -m + 1];
	h[0] = hash ( a, m, mo );
	for ( int i = 1; i != n - m + 1; ++i ) {
		h[i] = ( 43 * h[i - 1] % mo + a[i + m - 1] - ( a[i - 1] * exp ) % mo + mo )
				% mo;
	}

	return h;
}

long long hash ( long long* b, int m, long long mo ) {
	long long h = b[0];
	for ( int i = 1; i != m; ++i )
		h = ( h * 43 % mo + b[i] ) % mo;

	return h;
}