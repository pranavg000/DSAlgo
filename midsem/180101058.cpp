#include<iostream>

using namespace std;
#define N 5000000

int mod = 10000001;
int dp[N]={0};

int modadd(int x, int y){
    int r = ((x+y)%mod+mod)%mod;
    return r;
}


int main(){

    int n;
    cin>>n;
    int t;
    cin>>t;


    dp[1]=1;
    dp[4]=1;
    dp[6]=1;
    dp[7]=1;
    dp[8]=1;

    for(int i=9;i<=n;i++){
        dp[i]=modadd(modadd(dp[i-3],dp[i-5]),dp[i-7]);
    }
    int c,d;
    while(t--){
        cin>>c>>d;
        //c=-1;
        //d=t+2;
        if(c==-1) cout<<dp[d]<<endl;
        else cout<<dp[(n+1-d)]<<endl;
    }





return 0;}
