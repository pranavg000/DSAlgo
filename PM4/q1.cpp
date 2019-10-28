#include<bits/stdc++.h>

using namespace std;
#define lli long long
#define N 1000



class Graph{


   int V;
   vector<int> v[N];
   bool visited[N]={0};
   queue<int> q;
   int color[N]={0};

public:
   Graph(int V)
{
   this->V = V;

}

   void addEdge(int a, int b)
{
   v[a].push_back(b);
   v[b].push_back(a);
}

void dfs(int x){
       if(visited[x]==0)
   {visited[x]=1;
   //cout<<x<<endl;
   for(int u:v[x])
   {
       dfs(u);
   }}
    }

void bipartite(){
  for(int i=1;i<V+1;i++){
    if(visited[i]) continue;
    else {
      color[i]=1;
      bfs(i);
    }

   }
	
}

void printColor(){
  for(int i=1;i<V+1;i++){
      cout<<color[i]<<" ";
  }
}


void bfs(int x){
   visited[x]=1;
   q.push(x);
   while(!q.empty())
   {
       int s = q.front();
       q.pop();

       for(int u : v[s]){
           if(visited[u]==1) 
            {if(color[u]==(-1*color[s])) continue; 
             else {cout<<"NO"; exit(0);} }
           visited[u]=1;
           color[u]=-1*color[s];
           q.push(u);
         }
         }
  }

int connectedcomponents(int n){
   int ans=0;
   for(int i=1;i<n+1;i++){
       if(!visited[i]){
           ans++;
           dfs(i);
       }
   }
   return ans;
}
};

int main(){
	int n,m;
	cin>>n>>m;
	int a,b;
	Graph G(n);
	for(int i=0;i<m;i++){
		cin>>a>>b;
		G.addEdge(a,b);
	}

	G.bipartite();
cout<<"YES"<<endl;





	return 0;
}