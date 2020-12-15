// By Guo Wei
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n,g,s,b;
	int sg = 0,ss = 0,sb = 0,total = 0;
	
	cin >> n;
	while(n--) {
		cin >> g >> s >> b;
		sg += g;
		ss += s;
		sb += b;
		total += g + s + b;
	}
	cout << sg << " " << ss << " " << sb << " " << total;
	return 0;
}

