#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin >> n;
	cout << 32 - __builtin_clz(n) << endl;
	return 0;
}