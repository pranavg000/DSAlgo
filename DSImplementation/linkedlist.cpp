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

Node* GetLast(){
	return tail;
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


Node* Search(int a){
	Node *t;
	t = start;
	while(t!=nullptr){

		if(t->x==a){
			return t;
		}
		t = t->ptr;

	}
	return nullptr;
}






int Del(int a){
	Node *t, *prev;
	prev = nullptr;
	t = start;
	int c=0;
	while(t!=nullptr){

		if(t->x==a){
			if(c==0||Length()==1){ //If the found node is the first node.
				DelFirst();

		}
		else if(t->ptr==nullptr){ //If the found node is the last node.
			delete(t);
			prev->ptr = nullptr;
			tail = prev;
		}
		else {	//If the found node is in between.
			Node* p;
			p = t;
			prev->ptr = p->ptr;
			delete p;
		}
		length--;
		return 0; //returns 0 if item deleted
		}



		prev = t;
		t = t->ptr;
		c++;
	}
	return -1; //returns -1 if item not found
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



int main(){

//AddLast(4);
//cout<<LengthO1();
//   AddFirst(2);
//cout<<LengthO1();
//   AddFirst(5);
//   AddLast(3);
//cout<<LengthO1();
//
//
//
//   PrintLL();
//   cout<<endl;
//Del(4);
//cout<<LengthO1();
//   PrintLL();

	return 0;
}
