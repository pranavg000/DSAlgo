#include<iostream>
#include<vector>
#include<math.h>

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


int DelLast(){
	if(start==nullptr){
		return -1;  //returns -1 if underflow
	}
	else if(start==tail){
		delete start;
		start=nullptr;
		tail = nullptr;
		length--;
		return 0; // returns 0 if okay
	}
	else {
		Node* t;
		t = start;
		while((t->ptr)->ptr!=nullptr){
		t = t->ptr;
		}
		delete t->ptr;
		t->ptr = nullptr;
		tail = t;

		length--;
		return 0; // returns 0 if okay
	}
}

void AddLast(int x){
	Node* temp = newNode(x);
	if(start==nullptr){
		start = temp;
		tail = temp;
		// return 0; //returns 0 if ok
	}
	else {
		Node* t;
		t = start;
		while(t->ptr!=nullptr){
		t = t->ptr;
		}
		t->ptr = temp;
		tail = temp;
		// return 0; // returns 0 if okay
	}
		length++;

}

void AddLastO1(int x){
	Node* temp = newNode(x);
	if(start==nullptr){
		start = temp;
		tail = temp;
		// return 0;
	}
	else {
		tail->ptr = temp;
		tail = temp;
		// return 0;
	}
		length++;

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
		cout<<t->x<<" ";
		t = t->ptr;
		}
		cout<<endl;

}


Node* Dequeue(){


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


int Front(){
	return GetFirst()->x;
}


void Enqueue(int x){
	AddLastO1(x);
}


void PrintQueue(){
	PrintLL();
}


int main(){
//	cout<<LengthO1()<<endl;
//	Enqueue(10);
//	Enqueue(1);
//	Enqueue(2);
//    PrintQueue();
//    cout<<Front()<<endl;
//    Dequeue();
//    PrintQueue();
//    cout<<Front();
	return 0;
}
