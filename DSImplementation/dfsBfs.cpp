#include <bits/stdc++.h>

using namespace std;
#define uli unsigned long long int
#define lli long long int
#define Lf long double
#define mod 1000000007
#define SIZE 21
#define vi vector<int>
#define vl vector<long>
#define vll vector<long long>
#define vc vector<char>
#define ii <int, int>
#define ll <long, long>
#define lll <long long, long long>
#define loop(i,n) for(int i=0;i<n;i++)
#define loopr(i,n) for(int i=n-1;i>=0;i--)
#define N 1000


vi v[N];
int visited[N];
queue<int> q;





void dfs(int x){
    if(visited[x]==0)
    {
        visited[x]=1;
        cout<<x<<endl;
        for(int u:v[x])
        {
        dfs(u);
        }
    }
}


void bfs(int x){
    visited[x]=1;
    q.push(x);
   

    while(!q.empty())
    {
    int s = q.front(); q.pop();

    for(int u : v[s]){
    if(visited[u]==1) continue;
    visited[u]=1;
    cout<<u<<endl;

    q.push(u);
    }
    }

}




void addEdge(int a, int b)
    {
    v[a].push_back(b);
    v[b].push_back(a);
    }

int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    int x,y;
    for (int i = 0; i < m; i++)
    {
        cin>>x>>y;
        addEdge(x,y);
    }

    dfs(1);
    



return 0;
}




