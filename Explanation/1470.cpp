#pragma GCC optimize(3)
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>

using namespace std;

const int N=200005;

string in,s;
map <string,bool> a;
int len;

int main()
{
    while(cin>>in)
    {
        if(in==".")
            break;
        a[in]=true;
        len=max(int(in.length()),len);
    }
    while(cin>>in)
        s+=in;
    for(int i=1;i<=s.length();++i)
    {
        string cur="";
        for(int j=i;j<=s.length();++j)
            cur+=s[j];
    }
    return 0;
}