#include<iostream>
#include<vector>
#include<string>
using namespace std;


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



// cout<<ans<<"%"<<endl;



return ans;
}

int main(){
     int t;
cin>>t;
for(int o=0;o<t;o++)
{
string ca;
string cb;



// char ch='1';

// while(ch!='\n')
// {
// 	scanf("%c", &ch);
// 	if(ch=='\n') break;
// 	ca.push_back(ch);
// 	//cout<<ch<<endl;
// }
// // cout<<ca.size()<<" ";
// ch='1';
// while(ch!='\n')
// {
// 	scanf("%c", &ch);
// 	if(ch=='\n') break;
// 	cb.push_back(ch);
// }



cin>>ca;
cin>>cb;


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

// cout<<a.size()<<" ";
// cout<<b.size()<<endl;

for(int i=0;i<la;i++){
	string ans;
	vector<int> s(y+1);
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
// 	for(int i=0;i<la;i++)
// {
// 	cout<<a[i];
// }
// cout<<"&"<<endl;
// for(int i=0;i<lb;i++)
// {
// 	cout<<b[i];
// }
// cout<<"&"<<endl;
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
		ans+= to_string(s[i]);

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
	ans+= to_string(s[i]);

			fir=0;
		}

}
}

}
for(int k=0;k<i;k++){
	ans+=to_string(0);
}


// cout<<ans<<"$"<<endl;


// cout<<endl;
pro = sum(pro, ans);}


cout<<pro<<endl;





}






return 0;}
