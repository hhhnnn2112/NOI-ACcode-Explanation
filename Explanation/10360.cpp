/*
����գ�ʹ�ó���Ҫ�����

�������ݣ�
��һ��������t
��������t������
�ٽ�������t�������ո���ַ��������Ȳ�����20
 
������ݣ�

��ԭ�����t��������t���ַ��� 

��������
2
12
24
abcd
ef

�������
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
