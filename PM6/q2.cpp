#include<bits/stdc++.h>

typedef long long lli;
#define loop(i,s,n) for(int i=s;i<n;i++)
#define loopr(i,n,s) for(int i=n-1;i>=s;i--)
#define SIZE 100003


using namespace std;

int m;

unsigned long hash_(const char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c;

    return hash;
}



int hashFunction(string s){

    char *ch;
	unsigned long k = hash_(s.c_str());
	return k%m;
}



struct Node
{
    string x;

    Node* fptr;
    Node* bptr;

};

vector<Node*> HT;


Node* newNode(string s){
    Node* temp;
    temp = new Node();
    temp->fptr = nullptr;
    temp->bptr = nullptr;
    temp->x = s;

    return temp;
}

void AddFirst(int index, string x){
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




bool compF(string x, string s){
	int lx = x.size(),ls = s.size();
	if(lx!=ls) return false;

	loop(i,0,ls){
		if(x[i]!=s[i])
			return false;
	}

	return true;
}




Node* Search(int index, string a){
    Node *t;
    t = HT[index];
    while(t!=nullptr){

        if(compF(t->x,a)){
            return t;
        }
        t = t->fptr;
    }
    return nullptr;
}



void Delete(string k, Node* t){

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





Node* Search(string k){
    int index = hashFunction(k);

    return Search(index, k);

}

void insert(string k){
    int index = hashFunction(k);
    AddFirst(index, k);
}

void Delete(string k){
    Node* t = Search(k);

    if(t==nullptr){
        return;
    }

    Delete(k,t);
}




bool checkPal(string s){
	int len  = s.size();
	loop(i,0,len/2){
		if(s[i]!=s[len-1-i]){
			return false;
		}
	}

	return true;
}


void init_(){
    HT.resize(m, nullptr);
}




int main(){

    int n;
	cin>>n;
    m=SIZE;

	init_();

	insert("hekk");
    insert("hekl");
    insert("helk");
    insert("hikk");
    Search("hekk");
    Search("hikk");
    Search("ajhskjd");
    Delete("hikk");
    Search("hikk");



	string s;
	int f=0;
	loop(i,0,n){
		cin>>s;

		if(f==0)
		{
		
		if(checkPal(s)) continue;
		Node* itr = Search(s);
		
		if(itr==nullptr){
			reverse(s.begin(),s.end());
			insert(s);
		}
		else {
			f=1;
			continue;
		}
		
		
		}
	}
	
	if(f==1){
		cout<<"YES"<<endl;
	}
	else cout<<"NO"<<endl;





	return 0;
}