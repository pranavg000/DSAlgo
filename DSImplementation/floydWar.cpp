#include <iostream>

#define N 300

using namespace std;

#define INT_MAX 2147483647

int am[N][N];

class Graph{
   int V;

public:
   Graph(int V)
{
   this->V = V;

}

void addEdge(int a, int b, int wt)
{
  am[a-1][b-1]=wt;
  
}

void floyd(){

	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			if(am[i][j]==0){
				if(i!=j){
					am[i][j]=INT_MAX;
				}
			}
		}
	}


	for(int k=0;k<V;k++){
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				if(i!=j && i!=k && j!=k && am[i][k]!=INT_MAX && am[k][j]!=INT_MAX){
					am[i][j]=min(am[i][j],am[i][k]+am[k][j]);
				}
			}
		}
	}

	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			if(am[i][j]!=INT_MAX)
			cout<<am[i][j]<<" ";
			else cout<<-1<<" ";
		}cout<<endl;
	}
}

};




int main(){
int V,E;
cin>>V>>E;
Graph G(V);
int x,y,w;
for(int i=0;i<E;i++){
	cin>>x>>y>>w;
	G.addEdge(x,y,w);
}
G.floyd();
return 0;
}