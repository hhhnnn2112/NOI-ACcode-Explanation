#include <bits/stdc++.h>
using namespace std;
long long x, y, z;
int main() {
	cin >> x >> y;
	while (y > 0) {
		z += x / y * y * 4;
		x %= y;
		swap(x, y);
	}
	cout << z << endl;
	return 0;
}