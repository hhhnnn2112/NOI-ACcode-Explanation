

#include<iostream>         //输入输出流，不需要解释
using namespace std;
int main()
{
    int a[12],totm=0,tot=0;    //totm是存的钱，tot是除了存的剩下的
    for (int i=0;i<=11;++i)        //循环模拟每个月的经济流动
    {
        tot+=300;                  //妈妈先给了jj300元
        cin>>a[i];                 //接收这个月的预算
        if(tot-a[i]<0){            //如果预算超过了jj手中的钱……
            cout<<"-"<<i+1<<endl; //输出这是第几个月
            return 0;             //直接结束程序
        }
        tot-=a[i];            //如果钱够，算出jj用完后剩下的钱
        while(tot>100)        //如果jj手上有整百的
        {
            tot-=100;    //jj给妈妈，妈妈加上100
            totm+=100;   //不断循环，直到手上没整百的为止
        }
    }
    cout<<1.2*totm+tot<<endl; //输出妈妈给的本息，还有12月剩下的钱
    return 0;
}