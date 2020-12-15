#pragma GCC optimize(3)
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

const int N=2005,M=4005;

string s1,s2;
int a[N],b[N],ans[M],l,tot;

void multiplication()
{
    int lena=s1.length();
    int lenb=s2.length();
    for(int i=0;i<lenb;++i)
        for(int j=0;j<lena;++j)
            ans[i+j]+=a[j]*b[i];
    /*
    for(int i=0;i<tot;++i)
        printf("%d\n",ans[i]);
    */
    for(int i=0;i<tot;++i)
    {
        ans[i+1]+=ans[i]/10;
        ans[i]%=10;
    }
    /*
    for(int i=0;i<=tot;++i)
        printf("%d\n",ans[i]);
    */
}

bool cmp(string a,string b)
{
    if(a.length() != b.length())
        return a.length()>b.length();
    else
        return a>=b;
}

int main()
{
    cin>>s1>>s2;
    if(!cmp(s1,s2))
        swap(s1,s2);
    l=s1.length();
    tot+=l;
    for(int i=0;i<l;++i)
        a[i]=s1[l-i-1]-'0';
    l=s2.length();
    tot+=l-1;
    for(int i=0;i<l;++i)
        b[i]=s2[l-i-1]-'0';
    multiplication();
    while(!ans[tot] && tot>0)
        --tot;
    for(int i=tot;i>=0;--i)
        printf("%d",ans[i]);
    printf("\n");
    return 0;
}
/*
   1 2 3
*    9 9
---------
         9   18   27
    9   18   27 
    9   27   45   27
*/