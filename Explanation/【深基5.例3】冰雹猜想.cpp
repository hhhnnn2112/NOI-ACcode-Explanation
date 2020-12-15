#include<bits/stdc++.h>
#include<stack>
using namespace std;
stack<int> s;
int main()
{
    int n;
    cin>>n;
    while(n!=1)
    {
        s.push(n);
        if(n%2==0)
        {
            n/=2;
        }
        else
        {
            n=n*3+1;
        }
    }
    s.push(1);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}