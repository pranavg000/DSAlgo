#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

#define N 1000
#define pb push_back


const int INF = 1000000000;

struct Edge {
    int weight, to;
    bool operator<(Edge const& other) const {
        return weight < other.weight;
    }
};

int n;
vector<Edge> adj[N];

void prim() {
    int total_weight = 0;
    vector<Edge> min_e(n+3);
    for (int i = 0; i < n+3; i++)
    {
        min_e[i].to = -1;
        min_e[i].weight = INF;
    }
    
    min_e[0].weight = 0;
    set<Edge> s;
    s.insert({0, 0});
    vector<bool> selected(n+3, false);
    for (int i = 0; i < n; ++i) {
        if (s.empty()) {
            cout<<"NO";
            exit(0);
        }

        int v = s.begin()->to;
        selected[v] = true;
        total_weight += s.begin()->weight;
        s.erase(s.begin());

        if (min_e[v].to != -1){
            cout << v << " " << min_e[v].to << endl;
        }

        for (Edge e : adj[v]) {
            if (!selected[e.to] && e.weight < min_e[e.to].weight) {
                s.erase({min_e[e.to].weight, e.to});
                min_e[e.to] = {e.weight, v};
                s.insert({e.weight, e.to});
            }
        }
    }

    cout << total_weight << endl;
}


void addEdge(int x, int y, int w){
	adj[x].pb({w,y});
	adj[y].pb({w,x});

}

int main(){

	cin>>n;
	int m;
	cin>>m;

	int x,y,w;


	for(int i=0;i<m;i++){
		cin>>x>>y>>w;
        addEdge(x,y,w);
	}
    prim();


	return 0;
}