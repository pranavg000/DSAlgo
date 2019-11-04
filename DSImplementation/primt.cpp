#include <bits/stdc++.h>
using namespace std;
 

typedef pair<int, int> p;  

vector<pair<pair<int, int>, int> > ansEdges;


void prim(vector<pair<int,int> > adjlist[], int n)
{
    int wt[n];
    int parent[n];
    int visited[n] = {0};
    for(int i=0;i<n;i++)
    {
        wt[i] = INT_MAX;
        parent[i] = -1;
    }
    
    wt[0] = 0;
    parent[0] = 0;
    
 
    priority_queue< p, vector <p> , greater<p> > pq;
    pq.push(make_pair(0,0));
    
    while(!pq.empty())
    {
        int cv = pq.top().second;
        int cvw = pq.top().first;
        pq.pop();
        visited[cv] = 1;
        for(int i=0;i<adjlist[cv].size();i++)
        {
            int ng = adjlist[cv][i].first;
            int ngw = adjlist[cv][i].second;
            if(!visited[ng] && wt[ng]>ngw)
            {
                wt[ng] = ngw;
                pq.push(make_pair(ngw,ng));
                parent[ng] = cv;
            }
        }
    }
    int sum=0;
    for(int i=1;i<n;i++)
    {
        ansEdges.push_back({{i+1,parent[i]+1},wt[i]});
        cout<<i+1<<" -- "<<parent[i]+1<<" wt: "<<wt[i]<<endl;
        sum+=wt[i];
    }

    cout<<"sum is : "<<sum<<endl;
    
    
}
 
int main()
{

    
    int v,e;
    cin>>v>>e;
    vector<pair<int,int> > adjlist[v];
    for(int i=0;i<e;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        int xt = x-1;
        int yt = y-1;
        adjlist[xt].push_back(make_pair(yt,w));
        adjlist[yt].push_back(make_pair(xt,w));
    }
    
    prim(adjlist,v);
    
    return 0;
}
