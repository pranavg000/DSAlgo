#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

static const long long int mod = (long long)(1e9 + 7);
#define N 1000
#define pb push_back
#define lli long long

inline lli modadd(lli n,lli m){
    lli sum = ((n+m)%mod+mod)%mod;
    return sum;
}

inline lli modsub(lli n,lli m){
    lli diff = ((n-m+mod)%mod+mod)%mod;
    return diff;
}

inline lli modpro(lli n,lli m){
    lli pro = ((n*m)%mod+mod)%mod;
    return pro;
}


vector<int> parent, rank_;

void makeSet(int x){
	parent[x]=x;
	rank_[x]=0;
}

int findSet(int x){
	if(x!=parent[x])
		parent[x]=findSet(parent[x]);

	return parent[x];
}

void unionSets(int x, int y){
	int px = findSet(x);
	int py = findSet(y);

	if(rank_[px]<rank_[py]){
		parent[px]=py;
	}
	else if(rank_[py]<rank_[px]){
		parent[py]=px;
	}
	else{
		parent[py]=px;
		rank_[px]++;
	}

}

struct Edge
{
	int start;
	int destination;
	lli weight;
};

bool comp(Edge e1, Edge e2){
	return e1.weight>=e2.weight;
}

int main(){

	vector<Edge> v;

	int n;
	cin>>n;
	int m;
	cin>>m;
	parent.resize(n+1);
	rank_.resize(n+1);

	for (int i = 1; i < n+1; ++i)
	{
		makeSet(i);
	}

	int x,y;
	lli w;
	for (int i = 0; i < m; ++i)
	{
		cin>>x>>y>>w;
		v.pb({x,y,w});
	}

	sort(v.begin(), v.end(), comp);
    lli ans=1;
	for(Edge i: v){
		if(findSet(i.start)!=findSet(i.destination)){
			unionSets(i.start, i.destination);
			ans=modpro(i.weight,ans);
		}
	}

	cout<<ans<<endl;
	return 0;
}
