/*
请填空，使得程序按要求输出

输入数据：
第一行是整数t
接下来是t个整数
再接下来是t个不带空格的字符串，长度不超过20
 
输出数据：

按原样输出t个整数和t个字符串 

输入样例
2
12
24
abcd
ef

输出样例
12
24
abcd
ef
 


*/
#include <iostream>
using namespace std;
void Memcpy(char * src,char * dest,int n)
{
//your code starts here	
	for(int i = 0; i < n; ++i)
		dest[i] = src[i];	
//your code ends here		
}
int Strlen(char * s)
{	
	int i;
	for( i = 0; s[i]; ++i);
	return i;
}
int main()  
{
	int a;
	char s1[30];
	char s2[30];
	int t;
	cin >> t;
	for(int i = 0;i < t; ++i) {
		cin >> a;
		int b = 99999999;
		Memcpy((char*)&a,(char *) &b,sizeof(int));
		cout << b << endl;
	}
	for(int i = 0;i < t; ++i) {
		cin >> s1;
		Memcpy(s1,s2,Strlen(s1)+1);
		cout << s2 << endl;
	}
	return 0;
}

