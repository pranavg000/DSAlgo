#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

struct Node
{
	int x,y;

	Node* ptr;

};
Node* start = nullptr;

Node* newNode(int a, int b){
	Node* temp;
	temp = new Node();
	temp->ptr = nullptr;
	temp->x = a;
	temp->y = b;
	return temp;
}

void AddFirst(int x, int y){
	Node* p;
	Node *temp = newNode(x,y);
	if(start == nullptr){
		start = temp;

	}
	else{
		 p = start;
        start = temp;
        start->ptr = p;

	}
}


int DelFirst(){
	if(start==nullptr){
		return -1; //returns -1 if underflow
	}
	else {
		Node* t;
		t = start;
		delete start;
		start = t->ptr;
		return 0; // returns 0 if okay
	}
}

int Length(){
	Node *t;
	t = start;
	int c=0;
	while(t!=nullptr){
		c++;
		t = t->ptr;

	}
	return c;
}

int Search(double d){
	Node *t;
	t = start;
	int c=0;
	while(t!=nullptr){
		// cout<<sqrt(((long long)t->x*t->x+(long long)t->y*t->y))<<endl;
		if(sqrt(((long long)t->x*t->x+(long long)t->y*t->y))<=(d)){
			c++;
		}
		t = t->ptr;

	}
	return c;
}

bool Search(int a, int b){
	Node *t;
	t = start;
	while(t!=nullptr){

		if(t->x==a&&t->y==b){
			return true;
		}
		t = t->ptr;

	}
	return false;
}

int Del(int a, int b){
	Node *t, *prev, *p;
	prev = nullptr;
	t = start;
	int c=0;
	while(t!=nullptr){

		if(t->x==a&&t->y==b){
			if(c==0||Length()==1){ //If the found node is the first node.
				DelFirst();

		}
		else if(t->ptr==nullptr){ //If the found node is the last node.
			p = t;
			prev = nullptr;
			delete p;
		}
		else {	//If the found node is in between.
			p = t;
			prev->ptr = p->ptr;
			delete p;
		}
		return 0; //returns 0 if item deleted
		}



		prev = t;
		t = t->ptr;
		c++;
	}
	return -1; //returns -1 if item not found
}



int main(){




	long int q;
	vector<Node*> v;
	cin>>q;
	for(long int o=0;o<q;o++){
		int a,b,c;
		cin>>a;
		switch(a){
			case 1:
				cin>>b>>c;
				AddFirst(b,c);
				break;
			case 2:
			    {int d = DelFirst();
			    if(d==-1)
                    cout<<-1<<endl;
				break;}
			case 3:
				{cin>>b>>c;
				int d = Del(b,c);
				if(d==-1)
                    cout<<-1<<endl;}
				break;
			case 4:
				{cin>>b;
				int d = Search(b);
				if(d==0)
                    cout<<-1;
                else cout<<d;
				cout<<endl;
				break;}
			case 5:
				cin>>b>>c;
				if(Search(b,c)==1)
					cout<<"True"<<endl;
				else
					cout<<"False"<<endl;
				break;
			case 6:
				cout<<Length()<<endl;
				break;
		}
	}


	return 0;
}
