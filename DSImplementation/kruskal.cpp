#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define N 40005
#define pb push_back

int parent[N], rank_[N];

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
	int weight;
};

bool comp(Edge e1, Edge e2){
	return e1.weight<e2.weight;
}
vector<Edge> v, ansEdges;
int main(){
	int t;
	cin>>t;
	while(t--){
	    v.clear();
	    ansEdges.clear();

	    int n;
    	cin>>n;
//    	int m;
//    	cin>>m;


    	for (int i = 1; i < n+1; ++i){
    		makeSet(i);
    	}

    	int x,y,w;
    	for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                cin>>w;
                if(w!=-1 && i!=j) {Edge e1; e1.start=i;e1.destination=j; e1.weight=w;v.pb(e1);}
            }
    	}
    //	for (int i = 0; i < m; ++i)
    //	{
    //		cin>>x>>y>>w;
    //		v.pb({x,y,w});
    //	}

    	sort(v.begin(), v.end(), comp);

    	for(Edge i: v){
    		if(findSet(i.start)!=findSet(i.destination)){
    			unionSets(i.start, i.destination);
    			ansEdges.pb(i);
    		}
    	}
    	long long sum=0;
    	for(Edge x: ansEdges){
    		//cout<<x.start<<" -- "<<x.destination<<" wt: "<<x.weight<<endl;
    		sum+=x.weight;
    	}

    	cout<<sum<<endl;
	}



	return 0;
}
