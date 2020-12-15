// By Guo Wei
#include <iostream>
#include <cstdio>
using namespace std;
int a[110];
int main()
{
	int N;
	cin >> N;
	for(int i = 0;i < N; ++i)
		cin >> a[i];
	int M;
	cin >> M;
	int num = 0;
	for(int i = 0;i < N; ++i)
		if( a[i] == M)
			++ num;
	cout << num;
	return 0;
}

