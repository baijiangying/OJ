#include <cstdio>
#include <cstring>

#define P 23333
int result[500005];
int pre[26]; 
char s[500005];

int main() {
	scanf ( "%s", s );
	int n = strlen ( s );
	
	for ( int i = 0; i != 26; ++i ) pre[i] = -1;
	result[0] = 0;
	for ( int i = 1; i != n + 1; ++i ) {
		if ( pre[s[i - 1] - 'a'] == -1 )
			result[i] = ( 2 * result[i - 1] + 1 ) % P;
		else
			result[i] = ( 2 * result[i - 1] + P - result[pre[s[i - 1] - 'a'] - 1] ) % P;
		pre[s[i - 1] - 'a'] = i;
	}

	printf ( "%d\n", result[n] );
}