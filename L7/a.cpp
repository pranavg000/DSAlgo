#include <bits/stdc++.h>
using namespace std;


int mycomp(string s1, string s2){
	string t1 = s1+s2;
	string t2 = s2+s1;
	int l1 = t1.size(),l2 = t2.size();
	int f=0;

		for(int i=0;i<l1;i++){
			if(t1[i]<t2[i]){
				f=1;
				return 1;
			}
			else if(t1[i]>t2[i]){
				f=2;
				return 2;
			}

		}
		if(f==0) return 0;
}


void swap(string* a, string* b)
{
	string temp = *a;
	*a = *b;
	*b = temp;
}


int partition (vector<string> &v, int l, int h)
{
	string p = v[h];
	int i = (l-1);

	for (int j = l; j <= h - 1; j++)
	{
		if (mycomp(v[j],p)==1)
		{	i++;
			swap(&v[i], &v[j]);
		}
	}
	swap(&v[i+1], &v[h]);
	return (i+1);
}

void qsort(vector<string> &v, int l, int h)
{
	if (l < h)
	{
		int p = partition(v,l,h);
		qsort(v, l, p - 1);
		qsort(v, p + 1, h);
	}
}

vector<string> v;

int main(){
	int t,n;
	string str;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>str;
			v.push_back(str);
		}
		qsort(v,0,v.size()-1);
		for(int i=v.size()-1;i>=0;i--){
			cout<<v[i];
		}
		cout<<endl;
		v.clear();
	}

}
