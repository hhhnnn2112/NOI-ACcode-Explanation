// By Guo Wei
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
int main()
{
	int age1 = 0, age2 = 0, age3 = 0 ,age4 = 0;
	int n;
	cin >> n;
	int total = 0;
	for(int i = 0;i< n; ++i ) {
		int age;
		cin >> age;
		
		//按照0-18、19-35、36-60、61以上（含61）四个年龄段输出该段患病人数占总患病人数的比例，以百分比的形式输出，精确到小数点后两位。每个年龄段占一行，共四行。
		
		
		if( age >= 0 && age <= 18 ) 
			++age1;
		else if( age >=19 && age <=35)
			++age2;
		else if( age >= 36 && age <= 60 )
			++age3;
		else 
			++age4;
		++ total;
	}
	cout << setiosflags(ios::fixed) << setprecision(2);  //设置为保留小数点后面2位 
	cout << (double)age1/total * 100 << "%" << endl;
	cout << (double)age2/total * 100 << "%" << endl;
	cout << (double)age3/total * 100 << "%" << endl;
	cout << (double)age4/total * 100 << "%" << endl;
	return 0;
}

