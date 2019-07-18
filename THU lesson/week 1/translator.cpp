#include <iostream>
#include <string>

// class Speaker {
// private:
// 	std::string day;
// 	std::string plan;
// 	std::string item;

// public:
// 	virtual std::string say();
// 	virtual void read ( const std::string );
// };
std::string DAY[7] =  { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
class A {
private:
	std::string day;
	std::string plan;
	std::string item;

public:
	std::string say();
	void init();
	void read ( const std::string );
};
class B {
private:
	std::string day;
	std::string plan;
	std::string item;

public:
	std::string say();
	void init();
	void read ( const std::string );
};
class C {
private:
	std::string day;
	std::string plan;
	std::string item;

public:
	std::string say();
	void init();
	void read ( const std::string );
};


std::string translate ( const char, const std::string );
std::string translateA ( const std::string );
std::string translateB ( const std::string );
std::string translateC ( const std::string );

int main() {
	std::ios::sync_with_stdio ( false );
	A a; B b; C c;
	int n;
	std::cin >> n;
	std::string* s1 = new std::string[n];
	std::string* s2 = new std::string[n];
	for ( int i = 0; i != n; ++i ) {
		while ( !s1[i].size() ) std::getline ( std::cin, s1[i] );
	}
	for ( int i = 0; i != n; ++i )	{
		for ( int k = 4; k < s1[i].size(); ++k ) {
			s2[i] += s1[i][k];
		}
		switch ( s1[i][2] ) {
			case 'A': {
				a.read ( translate ( s1[i][0], s2[i] ) );
				std::cout << a.say() << std::endl;
				break;
			}
			case 'B': {
				b.read ( translate ( s1[i][0], s2[i] ) );
				std::cout << b.say() << std::endl;
				break;
			}
			case 'C': {
				c.read ( translate ( s1[i][0], s2[i] ) );
				std::cout << c.say() << std::endl;
				break;
			}
			default: break;
		}

	}
	

	return 0;
}

std::string translate ( const char who, const std::string s ) {
	std::string result;
	if ( s.size() ) {
		switch ( who ) {
			case 'A': {
				result = translateA ( s );
				break;
			}
			case 'B': {
				result = translateB ( s );
				break;
			}
			case 'C': {
				result = translateC ( s );
				break;
			}
			default: break;
		}
	}
	return result;
}

std::string translateA ( const std::string s ) {
	std::string result;
	switch ( s[0] ) {
		case 'T': {
			result += "d";
			for ( int i = 9; i != s.size() - 1; ++i )
				result += s[i];
			break;
		}
		case 'I': {
			result += "p";
			for ( int i = 10; i != s.size() - 1; ++i )
				result += s[i];
			break;
		}
		default: {
			result += "i";
			result += s[0];
			for ( int i = 2; s[i] != ','; ++i )
				result += s[i];
			break;
		}
	}
	return result;
}

std::string translateB ( const std::string s ) {
	std::string result;
	switch ( s[4] ) {
		case 'd': {
			result += 'd';
			result += DAY[s[8] - '0' - 1];
			break;
		}
		case 'p': {
			result += 'p';
			for ( int i = 10; i != s.size() - 2; ++i ) 
				result += s[i];
			break;
		}
		case 'i': {
			result += 'i';
			for ( int i = 10; i != s.size(); ++i )
				if ( s[i] == '=' ) {
					result += s[i + 1]; break;
				}
			for ( int i = 10; s[i] != '"'; ++i )
				result += s[i];
			break;
		}
		default: break;
	}
	return result;
}

std::string translateC ( const std::string s ) {
	std::string result;
		switch ( s[0] ) {
		case 'O': {
			result += "d";
			for ( int i = 75; i != s.size() - 1; ++i )
				result += s[i];
			break;
		}
		case 'M': {
			result += "p";
			for ( int i = 89; i != s.size() - 1; ++i )
				result += s[i];
			break;
		}
		case 'I': {
			result += "i";
			result += '1';
			int i = 11;
			for ( ; s[i] != ',' && s[i] != '.'; ++i )
				result += s[i];
			for ( int k = i; k < s.size(); ++k ) {
				if ( s[k] == 'a' )
					++result[1];
			}
			break;
		}
		default: break;
	}
	return result;
}

std::string A::say() {
	std::string s = "";
	if ( day.size() )
		s += ( "Today is " + day + "." );
	else if ( plan.size() )
		s += ( "I want to " + plan + "." );
	else if ( item.size() ) {
		s += item[0];
		s += " ";
		for ( int i = 1; i != item.size(); ++i )
			s += item[i];
		s += ",please.";
		
	}


	return s;
}

void A::init() {
	day = "", plan = "", item = "";
}

void A::read ( const std::string s ) {
	init();
	switch ( s[0] ) {
		case 'd': {
			for ( int i = 1; i != s.size(); ++i ) 
				day += s[i];
			break;
		}
		case 'p': {
			for ( int i = 1; i != s.size(); ++i )
				plan += s[i];
			break;
		}
		case 'i': {
			for ( int i = 1; i != s.size(); ++i )
				item += s[i];
			break;
		}
		default: break;
	}
}

std::string B::say() {
	std::string s = "Var ";
	if ( day.size() ) {
		s += "day=";
		switch ( day[1] ) {
			case 'o': s += '1'; break;
			case 'u': ( day[0] == 'T' ) ? s += '2' : s += '7' ; break;
			case 'e': s += '3'; break;
			case 'h': s += '4'; break;
			case 'r': s += '5'; break;
			case 'a': s += '6'; break;
		}
		s += ";";
	}
		
	else if ( plan.size() )
		s += ( "plan=\"" + plan +"\";" );
	else if ( item.size() ) {
		s += "item=\"";
		for ( int i = 1; i != item.size(); ++i )
			s += item[i];
		s += "\"; Var num=";
		s += item[0];
		s +=  ";";
	}


	return s;
}

void B::init() {
	day = "", plan = "", item = "";
}

void B::read ( const std::string s ) {
	init();
	switch ( s[0] ) {
		case 'd': {
			for ( int i = 1; i != s.size(); ++i ) 
				day += s[i];
			break;
		}
		case 'p': {
			for ( int i = 1; i != s.size(); ++i )
				plan += s[i];
			break;
		}
		case 'i': {
			for ( int i = 1; i != s.size(); ++i )
				item += s[i];
			break;
		}
		default: break;
	}
}

std::string C::say() {
	std::string s = "";
	if ( day.size() )
		s += ( "Oh, my god. that's incredible. You know what? I just found that today is " + day ) + "!";
	else if ( plan.size() )
		s += ( "My god! What should I do today? Let me see. Well, I have an excellent idea! Let us go to " + plan ) + ".";
	else if ( item.size() ) {
		s += "I want one ";
		for ( int i = 1; i != item.size(); ++i )
			s += item[i];
		for ( int i = item[0] - '0'; i != 1; --i )
			s += ",and one more";
		s += ".";
	}


	return s;
}

void C::init() {
	day = "", plan = "", item = "";
}

void C::read ( const std::string s ) {
	init();
	switch ( s[0] ) {
		case 'd': {
			day += s[1];
			day += s[1];
			for ( int i = 1; i != s.size(); ++i ) 
				day += s[i];
			break;
		}
		case 'p': {
			for ( int i = 1; i != s.size(); ++i )
				plan += s[i];
			break;
		}
		case 'i': {
			for ( int i = 1; i != s.size(); ++i )
				item += s[i];
			break;
		}
		default: break;
	}
}