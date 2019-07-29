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
else f=2;


int c=0;
for(int i=0;i<la; i++){
	a[la-i-1] = ca[i]-'0';
}

for(int i=0;i<lb; i++){
	b[lb-i-1] = cb[i]-'0';
}

for(int i=0;i<la;i++){
	vector<int> s(la+1);
	c=0;
	// if(i>=x){
	// 	if(f==1){
	// 		ds = a[i]+c;
	// 	if(ds<=9){
	// 		s[i]=ds;c=0;
	// 	}
	// 	else{
	// 		s[i]=ds%10;
	// 		c=ds/10;
	// 	}
	// 	}
	// 	if(f==2){
	// 		ds = b[i]+c;
	// 	if(ds<=9){
	// 		s[i]=ds;c=0;
	// 	}
	// 	else{
	// 		s[i]=ds%10;
	// 		c=ds/10;
	// 	}

	// 	}
		
	// }else
	for(int i=0;i<la;i++)
{
	cout<<a[i];
}
cout<<"&"<<endl;
for(int i=0;i<lb;i++)
{
	cout<<b[i];
}
cout<<"&"<<endl;
	for(int j=0;j<lb;j++){
		ds = a[i]*b[j]+c;
		if(ds<=9){
			s[j]=ds;
			c=0;
		}
		else{
			s[j]=ds%10;
			c=ds/10;
		}}
		if(c!=0){
			s[lb]=c;}

if(c!=0)
for(int i=s.size()-1;i>=0;i--){
	cout<<s[i];
}
if(c==0){
	for(int i=s.size()-2;i>=0;i--){
	cout<<s[i];
}
		
		}

cout<<endl;}

















return 0;}