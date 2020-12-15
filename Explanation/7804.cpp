//By Guo Wei
#include <iostream>
#include <cstdio>
using namespace std;
int Num[300];
int Pos[300];
int main()
{
	int c;
	for(int i = 0; i < 300; ++i)  {
		Num[i] = 0;
		Pos[i] = -1;
	}
	int pos = 0;
	while( (c = cin.get()) != EOF) {
		if( c!= ' ' && c!= '\r' && c!= '\n') {
			++Num[c];
			if( Pos[c] == -1)
				Pos[c] = pos;
			++ pos;
		}
	}
	int minP = 1 << 30;
	char cc;
	for(int i = 0;i < 260; ++i) 	{
		if( Num[i] == 1) {
			if( Pos[i] < minP) {
				minP = Pos[i];
				cc = i;
			}
		}
	}
	if( minP == 1 << 30)
		cout << "no" << endl;
	else
		cout << cc << endl;
	
	return 0;
}
