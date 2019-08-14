#include <iostream>
#include<string>
#include <stack>

using namespace std;



char rev(char ch){
if(ch==')'){
	return '(';
}
if(ch=='}'){
	return '{';
}
if(ch==']'){
	return '[';
}
if(ch=='>'){
	return '<';
}
if(ch=='|'){
	return '|';
}
cout<<ch<<"%";
}



int main(){
int t;
string str;
int f=0;
stack<char> s;
cin>>t;
for(int o=0;o<t;o++){
	f=0;
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]=='('||str[i]=='{'||str[i]=='['||str[i]=='<')
	{
		s.push(str[i]);
	}
		else if(str[i]=='|'){
			if(s.empty()){
				s.push(str[i]);
			}
			else if(s.top()==str[i]){
				s.pop();
			}
			else {
				s.push(str[i]);
			}
		}
		else {
			char r = rev(str[i]);
			if((!s.empty())&&(s.top()==r)){
				s.pop();

			}
			else {
				f=-1; break;
			}
		}

	}
	if(s.size()>0) {
		f=-1;
	}
	if(f==-1){
		cout<<"NO"<<endl;
	}
	else cout<<"YES"<<endl;

	while(!s.empty()){
		s.pop();
	}	
}




	return 0;
}