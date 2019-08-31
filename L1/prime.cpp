#include<bits/stdc++.h>
using namespace std;
#define lli unsigned long long int



bool isprime(lli n)
{
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0)return false;
    if(n%3==0)return false;

    for(lli i=5;(i*i)<=n;i+=2){

        if((n%i)==0){
            return false;
        }
    }

    return true;
}
int main()
{ int t;
cin>>t;
for(int o=0;o<t;o++)
{
   lli n;
   cin>>n;
   if(isprime(n)) cout<<"Prime"<<endl;
   else cout<<"Not a Prime"<<endl;
}
    return 0;
}
