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
    if(px==py) return;
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






vector<int> parent, rank_,size_;
set<int> reps;
void makeSet(int x){
	parent[x]=x;
	rank_[x]=0;
	size_[x]=1;
	reps.insert(x);
}

int findSet(int x){
	if(x!=parent[x])
		parent[x]=findSet(parent[x]);

	return parent[x];
}

void unionSets(int x, int y){
	int px = findSet(x);
	int py = findSet(y);
    if(px==py) return;
	if(rank_[px]<rank_[py]){
		parent[px]=py;
		reps.erase(px);
		size_[py]+=size_[px];
	}
	else if(rank_[py]<rank_[px]){
		parent[py]=px;
		reps.erase(py);
		size_[px]+=size_[py];
	}
	else{
		parent[py]=px;
		rank_[px]++;
		reps.erase(py);
		size_[px]+=size_[py];
	}
}

















int main()
{
	int n;
	cin>>n;
	parent.resize(n+3);
	rank_.resize(n+3);

//	makeSet(1);
//	makeSet(3);
//	makeSet(6);
//	makeSet(5);
//
//	unionSets(3,6);
//	cout<<findSet(3);
//	cout<<findSet(6);
//	cout<<findSet(5);
//	unionSets(1,5);
//	cout<<findSet(5);

	return 0;
}
