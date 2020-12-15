#include <iostream>
using namespace std;
const int MX = 10010;
int flags[MX];
int main()
{
	int L,M;
	for(int i = 0;i < MX; ++i)
		flags[i] = 1;
	cin >> L >> M;
	for(int i = 0;i < M; ++i) {
		int s,e;
		cin >> s >> e;
		for(int k = s; k <= e; ++k)
			flags[k] = 0; 
	}
	int total = 0;
	for(int i = 0;i <= L; ++i)
		total += flags[i];
	cout << total;
	
	return 0;
}
