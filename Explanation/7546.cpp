#include <iostream>
using namespace std;
char line[400];
int main()
{
	cin.getline(line,300);
	int total = 0;
	for(int i = 0; line[i]; ++i) {
		if( line[i] >= '0' && line[i] <= '9')
			++ total;
	}
	cout << total;
	return 0;
}
