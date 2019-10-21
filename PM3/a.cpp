#include<bits/stdc++.h>

using namespace std;

#define lli long long
#define loop(i,s,n) for(int i=s;i<n;i++)
#define loopr(i,n,s) for(int i=n-1;i>=s;i--)
#define pb push_back
#define N 1000


struct Point
{
	lli x;
	lli y;
	Point(lli x_, lli y_){
		x=x_;
		y=y_;
	}
	
};

vector<Point> col;
vector<bool> visited;
int size;
lli m,n,k;

bool comp(Point p, Point q){
	if(p.x!=q.x){
		return p.x<=q.x;
	}
	return p.y<=q.y;
}

int bin_search(Point p){
	int l=0,r=k,mid;
	int f=-1;
	while(l<=r){
		mid=l+(r-l)/2;
		if(p.x==col[mid].x&&p.y==col[mid].y){
			f=1;
			l=mid; break;
		}
		else if(p.x==col[mid].x&&p.y<col[mid].y){
			r=mid-1;
		}
		else if(p.x==col[mid].x&&p.y>col[mid].y){
			l=mid+1;
		}
		else if(p.x<col[mid].x){
			r=mid-1;
		}
		else if(p.x>col[mid].x){
			l=mid+1;
		}
		else {
			cout<<"NOOOOOOOOO";
		}
		//cout<<l<<" "<<r<<" "<<mid<<endl;
	}
	if(f==1){
		return l;
	}
	else {
		return -1;
	}
}

void dfs(int x){
    if(!visited[x]){
	    visited[x]=1;
	    size++;
	    int temp;
	    //cout<<x<<" "<<y<<endl;
	    if(col[x].x+1<m) 
	    	{temp = bin_search({col[x].x+1,col[x].y});
	    		if(temp!=-1)
	    	dfs(temp);
			}
	    if(col[x].x-1>=0) {temp = bin_search({col[x].x-1,col[x].y});
	    		if(temp!=-1)
	    	dfs(temp);
			}
	    if(col[x].y+1<n) {temp = bin_search({col[x].x,col[x].y+1});
	    		if(temp!=-1)
	    	dfs(temp);
			}
	    if(col[x].y-1>=0) {temp = bin_search({col[x].x,col[x].y-1});
	    		if(temp!=-1)
	    	dfs(temp);
			}
		}
}








int main(){

cin>>m>>n;
int big=-1;

cin>>k;
lli x,y;
loop(i,0,k)
{
	cin>>x>>y;
	col.pb({x,y});
	visited.pb(0);

}


sort(col.begin(),col.end(),comp);

loop(i,0,k){
	if(!visited[i]){
		size=0;
		dfs(i);
		big = max(big, size);
	}
}


cout<<big<<endl;




return 0;
}
