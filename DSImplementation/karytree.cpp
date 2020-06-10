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



void traverse(int x){
    if(visited[x]==0)
    {
        visited[x]=1;
        cout<<x<<" ";
        for(int u:v[x])
        {
        traverse(u);
        }
    }
}

void deleteNode(int x){

    
}




void insertNode(int a, int b)
    {
    v[a].push_back(b);

    }

int main()
{
    int n=5;

    insertNode(1,2);
    insertNode(1,3);
    insertNode(2,4);
    insertNode(1,5);

    traverse(1);
return 0;
}




