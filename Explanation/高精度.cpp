/////////////////高精度剑法///////////
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 10010;
int len1, len2;
int a[maxn], b[maxn];
string s1, s2;
void swap(string &a, string &b)  //交换两个字符串
{
    string t;
    t = a;
    a = b;
    b = t;
}
bool compare(string a, string b) //判断a是否小于b
{
    if (a.size() < b.size()) return true;  //当a的位数比b小时，a比b小
    if (a.size() > b.size()) return false; //当a的位数比b大时，a比b大
    for (int i = 0; i < a.size(); ++i)     //剩余情况就是a的位数与b相同
    {
        if (a[i] > b[i]) return false;     //逐位比较
        if (b[i] > a[i]) return true;
    }
    return false; //最后当a与b的各个位的数字都相同时，a等于b
}
int main()
{
    cin >> s1;           //读入不解释
    cin >> s2;
    if (compare(s1, s2)) //如果s1小于s2，就输出符号，并交换它们
    {
        swap(s1, s2);
        putchar('-');
    }
    len1 = s1.size();
    len2 = s2.size();
    for (int i = 0; i < len1; ++i) a[len1 - i] = s1[i] - '0';
    for (int i = 0; i < len2; ++i) b[len2 - i] = s2[i] - '0';
    //将字符转化为数字
    for (int i = 1; i <= len1; ++i) //从低位算到高位，模拟竖式的运算过程
    {
        a[i] -= b[i];               //直接用a储存结果：a[i]=a[i]-b[i]
        if (a[i] < 0)               //如果不够减（减完是负数）
        {
            a[i + 1]--;             //就向高位借一
            a[i] += 10;
        }
    }
    while (a[len1] == 0 && len1 > 1) len1--; //去除前导零
    //注意不能把单个零给去掉
    for (int i = len1; i >= 1; --i)          //从高位到低位输出
        printf("%d", a[i]);
    return 0;
}


///////////////////////////高精度加法


#include<bits/stdc++.h>
using namespace std;
int x,y;
int i,j;
char ab[100001],bc[100001];
int a[100001],b[100001];
int jw;
int maxn,maxj;
int main( )
{
    cin>>ab>>bc;
    x=strlen(ab);
    y=strlen(bc);
    for(i=0;i<x;i++)
        a[i]=ab[x-i-1]-'0';
    for(i=0;i<y;i++)
        b[i]=bc[y-i-1]-'0';
    maxn=max(x,y);
    for(i=0;i<maxn;i++)
    {
        a[i]=a[i]+b[i]+jw;
        jw=a[i]/10;
        a[i]%=10;
    }
    if(jw==1) cout<<jw;
    for(i=maxn-1;i>=0;i--)
    {
        cout<<a[i];
    }
    return 0;
}


///////////////////////////高精度乘法
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    char a1[100],b1[100];
    int a[100],b[100],c[100],lena,lenb,lenc,i,j,x;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    gets(a1);gets(b1);
    lena=strlen(a1);lenb=strlen(b1);
    for (i=0;i<=lena-1;i++) a[lena-i]=a1[i]-48;
    for (i=0;i<=lenb-1;i++) b[lenb-i]=b1[i]-48;
    for (i=1;i<=lena;i++)
    {
        x=0;                                               //用于存放进位
        for (j=1;j<=lenb;j++)                     //对乘数的每一位进行处理
        {
            c[i+j-1]=a[i]*b[j]+x+c[i+j-1]; //当前乘积+上次乘积进位+原数
            x=c[i+j-1]/10;
            c[i+j-1] %= 10;
        }
        c[i+lenb]=x;                                  //进位
    }
    lenc=lena+lenb;
    while (c[lenc]==0&&lenc>1)       //删除前导0
        lenc--;
    for (i=lenc;i>=1;i--)
        cout<<c[i];
    cout<<endl;
    return 0;
}


///////////////////2的n次方
#include<iostream>
using namespace std;
#define MAXNUM 2000
int arr[MAXNUM];
int main() {
    int n, index, i;
    cin >> n;
    index = 0;
    for (i = 0; i < MAXNUM; i++) {
        arr[i] = 0;
    }
    arr[0] = 2;
    for (i = 1; i < n; i++) {
        int jinwei = 0;
        for (int j = 0; j <= index; j++) {
            int temp = 1;
            if (j == 0) {
                temp = arr[j] * 2;
                if (temp >= 10) {
                    jinwei = 1;
                }
            } else {
                temp = arr[j] * 2;
                if (jinwei == 1) {
                    temp = temp + 1;
                }
                if (temp >= 10) {
                    jinwei = 1;
                } else {
                    jinwei = 0;
                }
            }
            arr[j] = temp % 10;
        }
        if (jinwei == 1) {
            index++;
            arr[index] = 1;
        }
    }
    for (i = index; i >= 0; i--) {
        cout << arr[i];
    }
    cout << endl;
    return 0;
}