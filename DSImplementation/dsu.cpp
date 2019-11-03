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

struct Node{
	Node* parent;
	int rank;
	int val;
}


Node* createNode(int v){
	Node* temp = new Node();
	temp->rank = 0;
	temp->val = v;
	temp->parent = nullptr;
	return temp;
}

Node* findRoot(Node* x){
	if(x->parent!=nullptr){
		x->parent = findRoot(x->parent);
	}

	return x->parent;
}


Node* Union(Node* x, Node* y){
	Node* rootx = findRoot(x);
	Node* rooty = findRoot(y);

	if(rootx->rank < rooty->rank){
		rootx->parent = rooty;
		return rooty;
	}
	else if(rootx->rank > rooty->rank){
		rooty->parent = rootx;
		return rootx;
	}
	else {
		rootx->parent = rooty;
		rooty->rank++;
		return rooty;
	}
}





int main()
{
	return 0;
}