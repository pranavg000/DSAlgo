#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){


int t;
cin>>t;
for(int o=0;o<t;o++)
{


string ca;
string cb;

cin>>ca;
cin>>cb;


int la = ca.size();
int lb = cb.size();
int x = min(la,lb);
int y= max(la,lb);
vector<int> a(y,0);
vector<int> b(x,0);

int f=0;
int ds;
string ans;

if(la>lb){
	f=1;
}
else if(la<lb){
	f=2;
}
else {
	for(int i=0;i<la;i++){
		if((ca[i]-'0')>(cb[i]-'0')){
			f=1; break;
		}
		if((ca[i]-'0')<(cb[i]-'0')){
			f=2; break;
		}

	}
}
//cout<<f<<endl;
vector<int> s(y+1,0);
int c=0;
for(int i=0;i<y; i++){
	if(f==1){
		a[y-i-1] = ca[i]-'0';

	}
	else if(f==2){
	a[y-i-1] = cb[i]-'0';

	}
	else{
       a[y-i-1] = ca[i]-'0';
	}
}

for(int i=0;i<x; i++){
	if(f==1){
		b[x-i-1] = cb[i]-'0';

	}
	else if(f==2){
	b[x-i-1] = ca[i]-'0';

	}
	else{
       b[x-i-1] = cb[i]-'0';
	}
}
/*
for(int i=0;i<y;i++){
    cout<<a[i];
}cout<<endl;
for(int i=0;i<x;i++){
    cout<<b[i];
}cout<<endl;
exit(0);*/


for(int i=0;i<y;i++){
	if(i>=x){
		{
			ds = a[i]-c;
		if(ds>=0){
			s[i]=ds;
			c=0;
		}
		else{
			s[i]=ds+10;
			c=1;
		}

		}


	}
	else{
		ds = a[i]-b[i]-c;
		if(ds>=0){
			s[i]=ds;
			c=0;
		}
		else{
			s[i]=ds+10;
			c=1;
		}

		}
}
/*
if(c!=0){

	int fir=1;
{
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]==0 && fir==1){
			continue;
		}
		else {
		ans+= to_string(s[i]);

			fir=0;
		}

}
}
}*/

//if(c==0)
    {

int fir=1;
{
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]==0 && fir==1){
			continue;
		}
		else {
	ans += to_string(s[i]);

			fir=0;
		}

}
}
}



if(ans.size()>0)
cout<<ans;
else cout<<0;
cout<<endl;
}
return 0;}
