//by Guo Wei
#include <iostream>
#include <cstring>
using namespace std;

struct Patient{
	char id[20];
	int age;
	int No;
} patients[110];

bool priority( Patient p1, Patient p2)
{ //返回值为 true则 p1比p2优先 
	if( p1.age >= 60 && p2.age < 60 )
		return true;
	if( p1.age < 60 && p2.age >= 60)
		return false;
	if( p1.age < 60 && p2.age < 60) 
		return p1.No < p2.No;
	if( p1.age >= 60 && p2.age >= 60)
		return p1.age > p2.age;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0;i < n; ++i) {
		cin >> patients[i].id >> patients[i].age;
		patients[i].No = i;
	}
	for(int i = n-1; i >= 0; --i) 
		for(int j = 0; j < i; ++ j) 
			if( priority(patients[j+1],patients[j])) {
					Patient tmp;
					tmp = patients[j];
					patients[j] = patients[j+1];
					patients[j+1] = tmp;
				}
	for(int i = 0;i < n; ++i)
		cout << patients[i].id << endl; 
	return 0;
}
