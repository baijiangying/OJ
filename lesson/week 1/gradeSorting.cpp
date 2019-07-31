#include <iostream>

struct Grade {
	int stuNum;
	int algorithms;
	int dataStructure;
	bool operator> ( Grade );
};

bool Grade::operator> ( Grade g ) {
	if ( algorithms + dataStructure > 
		g.algorithms + g.dataStructure )
		return true;
	else if ( algorithms + dataStructure ==
		g.algorithms + g.dataStructure )
		return ( algorithms > g.algorithms );
	return false;
}

int sort ( Grade*, int );

int main() {
	std::ios::sync_with_stdio ( false );
	int n;
	std::cin >> n;
	Grade* grade = new Grade[n];
	for ( int i = 0; i != n; ++i ) {
		grade[i].stuNum = i + 1;
		std::cin >> grade[i].algorithms >> grade[i].dataStructure;
	}

	int r = sort ( grade, n );
	for ( int i = 0; i != n; ++i )
		std::cout <<  grade[i].stuNum << " " 
		<< grade[i].algorithms + grade[i].dataStructure << " "
		<< grade[i].algorithms << " " << grade[i].dataStructure
		<< std::endl;
	std::cout << r << std::endl; 
	return 0;
}

int sort ( Grade* g, int n ) {
	int count = 0;
	for ( int i = 1; i != n; ++i ) {
		for ( int j = i; j != 0; --j ) {
			if ( g[j] > g[j - 1] ) {
				++count;
				std::swap ( g[j], g[j - 1] );
			}
			else break;
		}
	}

	return count;
}