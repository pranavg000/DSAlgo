#include<bits/stdc++.h>
using namespace std;

#define N 1000
#define pb push_back
#define MAX 1000000000
#define x first
#define y second
#define loop(i,s,n) for(int i=s;i<n;i++)



vector<pair<int, int> > v[N];
vector<int> dist;
vector<bool> visit;


void djst(int u, int n){
	dist.assign(n+2,MAX);
	visit.assign(n+2,false);
	dist[u]=0;
	set<pair<int, int> > s;
	s.insert({0,u});

	pair<int, int> *temp;
	while(!s.empty()){	
		int vt = s.begin()->y;
		s.erase(s.begin());


		for(auto ti: v[vt]){
			int dest = ti.y;
			int wt = ti.x;

			if(dist[dest]>dist[vt]+wt){
				s.erase({dist[dest], dest});
				dist[dest] = dist[vt]+wt;
				s.insert({dist[dest], dest});
			}
		}
	}
	
	loop(i,1,n+1){
		cout<<dist[i]<<" ";
	}

}

struct Edge
{
	int weight;
	int destination;
};

void addEdge(int a, int b, int w)
{
    v[a].push_back({w,b});
    v[b].push_back({w,a});
}

int main(){

	int n;
	cin>>n;
	int m;
	cin>>m;
	int x,y,w;

	loop(i,0,m){
		cin>>x>>y>>w;
		addEdge(x,y,w);
	}


	djst(1,n);




}