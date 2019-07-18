#include <cstdio>

struct State {
	int A;
	int B;
	int C;
} state;

void Ato0 ( State state ) { state.A = 0; }
void Bto0 ( State state ) { state.B = 0; }
void Cto0 ( State state ) { state.C = 0; }
void AtoM ( State state ) { state.A = 80; }
void BtoM ( State state ) { state.B = 50; }
void CtoM ( State state ) { state.C = 30; }
void AtoB ( State state ) { 
	if ( state.A > ( 50 - state.B ) )
		state.A -= ( 50 - state.B ), state.B = 50;
	else 
		state.A = 0, state.B += state.A;
}
void BtoA ( State state ) {
	if ( state.B > ( 80 - state.A ) )
		state.B -= ( 80 - state.A ), state.A = 80;
	else
		state.B = 0, state.A += state.B;
}
void AtoC ( State state ) { 
	if ( state.A > ( 30 - state.C ) )
		state.A -= ( 30 - state.C ), state.C = 50;
	else 
		state.A = 0, state.B += state.A;
}
void CtoA ( State state ) {
	if ( state.C > ( 80 - state.A ) )
		state.C -= ( 80 - state.A ), state.A = 80;
	else
		state.C = 0, state.A += state.C;
}
void BtoC ( State state ) { 
	if ( state.B > ( 30 - state.C ) )
		state.B -= ( 30 - state.C ), state.C = 50;
	else 
		state.A = 0, state.B += state.A;
}
void CtoB ( State state ) {
	if ( state.C > ( 80 - state.B ) )
		state.C -= ( 80 - state.B ), state.B = 80;
	else
		state.C = 0, state.B += state.C;
}
int main() {
	void pouring ( 0 );
	return 0;
}