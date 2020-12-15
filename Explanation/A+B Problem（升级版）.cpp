这里的A＋B是很奇特的。它是按质数的顺序来进位的。
例如：1,0+2,1＝1,0,1（用，来分隔每一位）。
个位是2进制，十位是3进制，百位是5进制，千位是7进制，万位是11进制……两个加数的最高位是万位（万位可能有两位）。

输入一个形如1,0+2,1字符串s。
1,0+2,1

1,0,1



#include<iostream>
#include<string>
using namespace std;
int a[9],b[9],c[9],num1=1,num2=1,p=0;
string s,s1,s2;
void print(int p[])//输出
{
    int fir=0;
    for(int i=9;i>=1;i--)
    {
        if((p[i]==0)&&(fir==0)){continue;}
        if(fir==0){cout<<p[i];}//如果第一位没出来就不输出逗号
        else{cout<<","<<p[i];}//否则输出逗号
        fir++;
    }
    cout<<"\n";
    return;
}
void pluss()
{
    for(int i=1;i<=9;i++){c[i]=a[i]+b[i];}//加法
    if(c[1]>=2){c[1]=c[1]-2,c[2]++;}//精度较小，手动进位
    if(c[2]>=3){c[2]=c[2]-3,c[3]++;}
    if(c[3]>=5){c[3]=c[3]-5,c[4]++;}
    if(c[4]>=7){c[4]=c[4]-7,c[5]++;}
    if(c[5]>=11){c[5]=c[5]-11,c[6]++;}
}
int ad(int sta,int endd,string ss)
{
    int s=sta,sum=0;
    while((s>=endd)&&(ss[s]>='0')&&(ss[s]<='9'))
    {
        sum=sum*10+ss[s]-48,//一位位取出累加
                s--;
    }
    if(ss[sta]=='0'){sum=sum*10;}//微小的特判，防止输入“10”
    return sum;
}
int main()
{
    cin>>s;
    while(s[p]!='+'){p++;}//找出加号位置
    for(int i=p-1;i>=0;i--)
    {
        if((s[i]>='0')&&(s[i]<='9'))
        {
            a[num1]=ad(i,0,s),//取出数字
                    num1++;
            if(a[num1-1]==10){i--;}//如果是10，跳位（其实是break，因为是最后一位……）
        }
    }
    for(int i=s.size()-1;i>p;i--)
    {
        if((s[i]>='0')&&(s[i]<='9'))
        {
            b[num2]=ad(i,p+1,s),//同上
                    num2++;
            if(b[num2-1]==10){i--;}
        }
    }
    pluss();
    print(c);
    return 0;
}