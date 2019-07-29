#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){

vector<char> ca;
vector<char> cb;

char ch='1';

while(ch!='\n')
{
	scanf("%c", &ch);
	if(ch=='\n') break;
	ca.push_back(ch);
}
ch='1';
while(ch!='\n')
{
	scanf("%c", &ch);
	if(ch=='\n') break;
	cb.push_back(ch);
}



int la = ca.size();
int lb = cb.size();
vector<int> a(la);
vector<int> b(lb);
int x = min(la,lb);
int y= max(la,lb);
int f=0;
int ds;


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
vector<int> s(y+1);
int c=0;
for(int i=0;i<y; i++){
	if(f==1){
		a[y-i-1] = ca[i]-'0';

	}
	else if(f==2){
	a[y-i-1] = cb[i]-'0';

	}
}

for(int i=0;i<x; i++){
	if(f==1){
		b[x-i-1] = cb[i]-'0';

	}
	else if(f==2){
	b[x-i-1] = ca[i]-'0';

	}
}




for(int i=0;i<y;i++){
	
	{
		ds = a[i]-b[i]-c;
		// cout<<"$"<<" "<<ds<<endl;
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
// if(c!=0){
// 	s[y]=c;
// }
// cout<<c<<endl;
if(c!=0)
for(int i=s.size()-1;i>=0;i--){
	cout<<s[i];
}
int fir=1;
if(c==0){
	for(int i=s.size()-2;i>=0;i--){
		if(s[i]==0 && fir==1){
			continue;
		}
		else {
			cout<<s[i];
			fir=0;
		}

}
}

















return 0;}