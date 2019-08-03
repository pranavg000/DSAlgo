#include<iostream>
#include<vector>
#include<string>
using namespace std;


int comparetwo(string ca, string cb){


int la = ca.size();
int lb = cb.size();
vector<int> a(la);
vector<int> b(lb);
int x = min(la,lb);
int y= max(la,lb);
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

return f;
}
string sum(string ca, string cb){



int la = ca.size();
int lb = cb.size();
vector<int> a(la);
vector<int> b(lb);
int x = min(la,lb);
int y= max(la,lb);
int f=0;
int ds;
string ans;

if(la>lb){
	f=1;
}
else f=2;
vector<int> s(y+1);
int c=0;
for(int i=0;i<la; i++){
	a[la-i-1] = ca[i]-'0';
}

for(int i=0;i<lb; i++){
	b[lb-i-1] = cb[i]-'0';
}

for(int i=0;i<y;i++){
	if(i>=x){
		if(f==1){
			ds = a[i]+c;
		if(ds<=9){
			s[i]=ds;c=0;
		}
		else{
			s[i]=ds%10;
			c=ds/10;
		}
		}
		if(f==2){
			ds = b[i]+c;
		if(ds<=9){
			s[i]=ds;c=0;
		}
		else{
			s[i]=ds%10;
			c=ds/10;
		}

		}

	}
	else {
		ds = a[i]+b[i]+c;
		if(ds<=9){
			s[i]=ds;
			c=0;
		}
		else{
			s[i]=ds%10;
			c=ds/10;
		}

		}
}
if(c!=0){
	s[y]=c;
}
if(c!=0){
// 	for(int i=s.size()-1;i>=0;i--){
// 	ans += to_string(s[i]);
// }
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

if(c==0){
// 	for(int i=s.size()-2;i>=0;i--){
// 	ans+= to_string(s[i]);
// }
	int fir=1;
{
	for(int i=s.size()-2;i>=0;i--){
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






return ans;
}

string diff(string ca, string cb){


int la = ca.size();
int lb = cb.size();
vector<int> a(la);
vector<int> b(lb);
int x = min(la,lb);
int y= max(la,lb);
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
}

if(c==0){

int fir=1;
{
	for(int i=s.size()-2;i>=0;i--){
		if(s[i]==0 && fir==1){
			continue;
		}
		else {
	ans+= to_string(s[i]);

			fir=0;
		}

}
}
}







return ans;
}



string mult(string ca, string cb){

int la = ca.size();
int lb = cb.size();
vector<int> a(la);
vector<int> b(lb);
int x = min(la,lb);
int y= max(la,lb);
int f=0;
int ds;
string ans;

if(la>lb){
	f=1;
}
else f=2;

string pro="0";

int c=0;
for(int i=0;i<la; i++){
	a[la-i-1] = ca[i]-'0';
}

for(int i=0;i<lb; i++){
	b[lb-i-1] = cb[i]-'0';
}


for(int i=0;i<la;i++){
	string ans;
	vector<int> s(y+1);
	c=0;

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
}

if(c==0){

int fir=1;
{
	for(int i=s.size()-2;i>=0;i--){
		if(s[i]==0 && fir==1){
			continue;
		}
		else {
	ans+= to_string(s[i]);

			fir=0;
		}

}
}

}
for(int k=0;k<i;k++){
	ans+=to_string(0);
}

pro = sum(pro, ans);}


return pro;
}


int main(){
string ca;
string cb;




cin>>ca;
cin>>cb;


int la = ca.size();
int lb = cb.size();
// vector<int> a(la);
// vector<int> b(lb);
string a,b;
int x = min(la,lb);
int y= max(la,lb);
int f=0;
int ds;
string ans;
/*
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
}*/
f=1;
vector<int> s(y+1);
int c=0;
for(int i=0;i<y; i++){
	if(f==1){
		a+=to_string(ca[i]-'0');

	}
	else if(f==2){
	a+=to_string(cb[i]-'0');

	}
}

for(int i=0;i<x; i++){
	if(f==1){
		b+=to_string(cb[i]-'0');

	}
	else if(f==2){
		b+=to_string(ca[i]-'0');

	}
}
string temp="";
string quo="";
int g=0,te=0;
while(c<y){
    te=0;
	// if((c+x-1)<y)
	{
		while(temp.size()<x){
			if(c>=y) {g=1;break;}
		temp+=(a[c]);
		//cout<<c<<"&";
		c++;te++;
	}
//cout<<temp<<"^";
	}

	if(g==1){
		break;
	}
		if(comparetwo(temp,b)==2){
			if((c)<y){
		temp+=(a[c]);

		c++;te++;
	}
	else {g=1;break;}

	}
	if(g==1){
		break;
	}

    for(int i=1;i<te;i++){
            if(quo.size()>0)
        quo+=to_string(0);
    }

	for(int i=9;i>0;i--){
		string mul=mult(b,to_string(i));
		//cout<<mul<<"#"<<temp<<"!";
		if((comparetwo(mul,temp))!=1){
			temp = diff(temp,mult(b,to_string(i)));
			quo+=to_string(i);
//cout<<temp<<" "<<quo<<"*"<<i<<endl;
break;
		}

	}

}
if(temp.size()>0)
cout<<"Quotient : "<<quo<<endl<<"Remainder : "<<temp<<endl;

else
cout<<"Quotient : "<<quo<<endl<<"Remainder : "<<0<<endl;
return 0;}
