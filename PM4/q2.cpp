#include<bits/stdc++.h>

using namespace std;
#define lli long long
#define N 1000



class Graph{

public:
   int V;
   vector<int> v[N];
   bool visited[N]={0};
   queue<int> q;
   int color[N]={0};

   Graph(int V)
{
   this->V = V;

}

   void addEdge(int a, int b)
{
   v[a].push_back(b);
   v[b].push_back(a);
}

void oddCycle(int meme){
    int a,b,w;
for(int i=0;i<meme;i++){
		cin>>a>>b>>w;
		if(w%2==0){
            addEdge(a,V+1);
            addEdge(b,V+1);
            V++;
		}
		else {
            addEdge(a,b);
		}
	}
	bipartite();
}

void bipartite(){
	bfs(1);
}


void bfs(int x){
   visited[x]=1;
   q.push(x);
   color[x]=1;
   while(!q.empty())
   {
       int s = q.front();
       q.pop();

       for(int u : v[s]){
           if(visited[u]==1) {if(color[u]==(-1*color[s])) continue; else {cout<<"YES"; exit(0);} }
           visited[u]=1;
           //cout<<u<<endl;
           color[u]=-1*color[s];
           q.push(u);}}}



};

int main(){
	int n,m;
	cin>>n>>m;

	Graph G(n);
    G.oddCycle(m);


cout<<"NO"<<endl;




	return 0;
}
