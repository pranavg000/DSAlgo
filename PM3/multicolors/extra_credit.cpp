#include<iostream>
#include<vector>

using namespace std;

#define lli long long
#define loop(i,s,n) for(int i=s;i<n;i++)
#define loopr(i,n,s) for(int i=n-1;i>=s;i--)
#define pb push_back
#define N 1000

int col[N][N];
bool visited[N][N];
int m,n;

int size;
 
void dfs(int x, int y, int color){
    if(!visited[x][y]&&col[x][y]==color){
	    visited[x][y]=1;
	    size++;
	    //cout<<x<<" "<<y<<endl;
	    if(x+1<m) dfs(x+1,y,color);
	    if(x-1>=0) dfs(x-1,y,color);
	    if(y+1<n) dfs(x,y+1,color);
	    if(y-1>=0) dfs(x,y-1,color);
		}
}

int main(){

cin>>m>>n;
int big=-1;
int k;
cin>>k;
int x;
loop(i,0,m)
	loop(j,0,n){
	//cin>>x>>y;
	cin>>x;
	col[i][j]=x;
}




loop(i,0,m){
	loop(j,0,n){
		if(!visited[i][j]){
			size=0;
			dfs(i,j, col[i][j]);
			big = max(big, size);
		}
	}
}


cout<<big<<endl;




return 0;
}