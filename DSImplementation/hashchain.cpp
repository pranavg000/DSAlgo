#include<bits/stdc++.h>

using namespace std;
#define MAX_SIZE 1000000

int a,b,m,n,p;

bool prime[MAX_SIZE + 1];
vector<int> vprime;



struct Node
{
    int x;

    Node* fptr;
    Node* bptr;

};

vector<Node*> HT;

int hashFunction(int k){
    return ((a*k+b)%p)%m;
}

Node* newNode(int a){
    Node* temp;
    temp = new Node();
    temp->fptr = nullptr;
    temp->bptr = nullptr;
    temp->x = a;

    return temp;
}

void AddFirst(int index, int x){
    Node* p;
    Node *temp = newNode(x);
    if(HT[index] == nullptr){
        HT[index] = temp;
    }
    else{
        p = HT[index];
        HT[index] = temp;
        HT[index]->fptr = p;
        p->bptr = temp;
    }
}


Node* Search(int index, int a){
    Node *t;
    t = HT[index];
    while(t!=nullptr){

        if(t->x==a){
            return t;
        }
        t = t->fptr;
    }
    return nullptr;
}



void Delete(int k, Node* t){

    Node *prev, *next;
    prev = t->bptr;
    next = t->fptr;

    if(prev == nullptr){
        int index = hashFunction(k);
        HT[index] = next;

    }

    else {
        prev->fptr = next;
    }

    if(next!=nullptr){
    next->bptr = prev;
    }
    delete t;
}



void sieve()
{

    for (int p=2; p*p <= MAX_SIZE; p++) {
	if (prime[p] == false) {
    for (int i = p*p; i <= MAX_SIZE; i+=p)
                prime[i] = true;
        }
    }
    for(int i=2;i<=MAX_SIZE;i++){
        if(!prime[i])
            {
                vprime.push_back(i);
            }
        }
}










Node* Search(int k){
    int index = hashFunction(k);

    Node* t = Search(index, k);

    if(t==nullptr){
        cout<<"Not Found !!\n";
        return nullptr;
    }
    else{
        cout<<"Found !!\n";
    }
    return t;
}

void insert(int k){
    int index = hashFunction(k);
    AddFirst(index, k);
}

void Delete(int k){
    Node* t = Search(k);

    if(t==nullptr){
        return;
    }

    Delete(k,t);
}


void init_(){
    HT.resize(m, nullptr);
    sieve();
    p = vprime[upper_bound(vprime.begin(), vprime.end(), n)-vprime.begin()];

    b = rand()%p;
    a = rand()%(p-1)+1;
}


int main(){

	cin>>n;
    cin>>m;
//n=4;m=2;
    init_();

    insert(1);
    insert(2);
    insert(3);
    insert(4);
    Search(1);
    Search(4);
    Search(5);
    Delete(4);
    Search(4);



	return 0;
}
