#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cctype>

using namespace std;

const int N=20005;

string s,c;
int len,longlength;

void readString()
{
    string line;
    while(cin.getline(line,88))
    {
        strcat(org,line);
        strcat(org,"\n");
    }
}

void string_elementLower()
{
    for(int i=0;i<s.length();++i)
        if(s[i]>='A' && s[i]<='Z')
            s[i]+=32;
    return ;
}
/*
void Palindrome(int s,int e)
{
    for()
}
*/
int main()
{
    readString();
    cin>>s;
    string_elementLower();
    for(int i=0;i<s.length();++i)
        if(s[i]>='a' && s[i]<='z')
        {
            ++len;
            c+=s[i];
        }
    cout<<">> "<<s<<endl;
    for(int i=0;i<len;++i)
        cout<<c[i];
    cout<<"\n";
    /*
    for(int i=1;i<len;++i)
        for(int j=len;j>i;++j)
        {
            Palindrome(i,j);
        }
    */
    return 0;
}