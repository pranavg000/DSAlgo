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
{
   lli n;
   cin>>n;
   if(isprime(n)) cout<<"prime"<<endl;
   else cout<<"not prime"<<endl;

    return 0;
}
