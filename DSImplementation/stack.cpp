#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	int x;

	Node* ptr;

};
Node* start = nullptr;
Node* tail = nullptr;
int length;


Node* newNode(int a){
	Node* temp;
	temp = new Node();
	temp->ptr = nullptr;
	temp->x = a;

	return temp;
}

void AddFirst(int x){
	Node* p;
	Node *temp = newNode(x);
	if(start == nullptr){
		start = temp;
		tail = temp;

	}
	else{
		p = start;
        start = temp;
        start->ptr = p;
	}
	length++;
}



int DelFirst(){
	if(start==nullptr){
		return -1; //returns -1 if underflow
	}
	else if (start==tail){

		delete start;
		start = nullptr;
		tail = nullptr;
		length--;
		return 0; // returns 0 if okay
	}
	else {
		Node* t;
		t = start;
		delete start;
		start = t->ptr;
		length--;
		return 0; // returns 0 if okay
	}
}






Node* GetFirst(){
	return start;
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

int LengthO1(){
	return length;
}



void PrintLL(){
	Node* t;
		t = start;
		while(t!=nullptr){
		cout<<t->x<<endl;
		t = t->ptr;
		}

}


void Push(int x){
	AddFirst(x);
}


Node* Pop(){
	if(LengthO1()==0){
		cout<<"underflow"<<endl;
		exit(0);
	}
	else {
		Node* temp = GetFirst();
		DelFirst();
		return temp;
	}
	return nullptr;
}

int Top(){
	return GetFirst()->x;
}

void PrintStack(){
	PrintLL();
}




int main(){
//    Push(2);
//    Push(3);
//    Push(4);
//    cout<<Top()<<endl;
//    PrintStack();
//    Pop();
//    Pop();
//    cout<<Top()<<endl;

	return 0;
}
