#include <bits/stdc++.h>

using namespace std;

#define N 1000


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



int main()
{
	int n;
	cin>>n;
	parent.resize(n+3);
	rank_.resize(n+3);

	makeSet(1);
	makeSet(3);
	makeSet(6);
	makeSet(5);

	unionSets(3,6);
	cout<<findSet(3)<<endl;
	cout<<findSet(6)<<endl;
	cout<<findSet(5)<<endl;
	unionSets(1,5);
	cout<<findSet(5)<<endl;

	return 0;
}
