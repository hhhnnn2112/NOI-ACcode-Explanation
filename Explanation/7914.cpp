//by Guo Wei
#include <iostream>
#include <cstring>
using namespace std;

struct Student{
	int id;
	int score;
} students[5010];
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < n; ++i) 
		cin >> students[i].id >> students[i].score;
	for(int i = n-1; i >= 0; --i) 
		for(int j = 0; j < i; ++ j) 
			if( students[j].score < students[j+1].score ||
				students[j].score == students[j+1].score && 
				students[j].id > students[j+1].id) {
					Student tmp;
					tmp = students[j];
					students[j] = students[j+1];
					students[j+1] = tmp;
				}
	int k = m * 1.5;
	int lineScore = students[k-1].score;
	while( students[k].score == lineScore) 
		++k;
	cout <<lineScore <<   " " << k << endl;
	for(int i = 0;i < k; ++i)
		cout << students[i].id<< " " << students[i].score<< endl; 
	return 0;
}
