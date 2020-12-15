#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char line[100];
int main()
{
	cin.getline(line,90);
	for(int i = 0; line[i]; ++i) {
		if( line[i] >= 'a' && line[i] <= 'y' || line[i] >= 'A' && line[i] <= 'Y')
			++line[i];
		else if( line[i] == 'z')
			line[i] = 'a';
		else if( line[i] == 'Z')
			line[i] = 'A';
	}
	cout << line;
	return 0;
}

