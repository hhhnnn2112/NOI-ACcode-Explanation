#include<bits/stdc++.h>
using namespace std;
long long n,k,a[5000010];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    nth_element(a,a+k,a+n);//使第k小整数就位 
    printf("%d",a[k]);//调用第k小整数
}