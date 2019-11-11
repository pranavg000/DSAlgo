#include<bits/stdc++.h>

typedef long long lli;
#define loop(i,s,n) for(int i=s;i<n;i++)
#define loopr(i,n,s) for(int i=n-1;i>=s;i--)

using namespace std;


bool checkPal(string s){
	int len  = s.size();
	loop(i,0,len/2){
		if(s[i]!=s[len-1-i]){
			return false;
		}
	}

	return true;
}



int main(){

	set<string> se;
	int n;
	cin>>n;
	string s;
	int f=0;
	loop(i,0,n){
		cin>>s;

		if(f==0)
		{
		
		if(checkPal(s)) continue;
		auto itr = se.find(s);
		
		if(itr==se.end()){
			reverse(s.begin(),s.end());
			se.insert(s);
		}
		else {
			f=1;
			continue;
		}
		
		
		}
	}
	
	if(f==1){
		cout<<"YES"<<endl;
	}
	else cout<<"NO"<<endl;


	return 0;
}