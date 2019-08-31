#include<bits/stdc++.h>
using namespace std;
#define lli unsigned long long int

power(lli a,lli d,lli n)
{lli pro=1;
a=a%n;
    while(d>0)
    {if(d%2!=0)
    {
        pro=(pro*a)%n;
        d--;
    }
        d=d/2;
        a=(a*a)%n;


    }
    return pro;
}

bool miller(lli n,lli d)
{
    lli a=2+rand()%(n-3);

lli x=power(a,d,n);
    if(x==1||x==n-1) return true;

    while(d!=n-1)
    {
        x=x*x%n;
        d*=2;
        if(x==1) return false;
        if(x==n-1) return true;
    }
    return false;
}
bool prime(lli n,int p)
{
    if(n<=1)
    return false;
    if(n<=3)
    return true;
    if(n%2==0)
    return false;


    lli l=n-1;
    while(l%2==0)
        l=l/2;
    for(int i=0;i<p;i++)
        if(!miller(n,l)) return false;
    return true;
}
int main()
{int t;
cin>>t;
for(int o=0;o<t;o++)
{
   lli n,p=4;
   cin>>n;
   if(prime(n,p))
    cout<<"Prime"<<endl;
   else
   cout<<"Not prime"<<endl;
}
    return 0;
}
