#include<bits/stdc++.h>

using namespace std;
#define MAX_SIZE 1000000

int a,b,m,n,p,a2,b2;

bool prime[MAX_SIZE + 1];
vector<int> vprime;



vector<int> HT;

int hashFunction1(int k){
    return ((a*k+b)%p);
}

int hashFunction2(int k){
    return ((a2*k+b2)%p);
}

int hashMix(int i, int k){
    return (hashFunction1(k)+i*hashFunction2(k))%p;
}

bool Insert(int k){
    int index = hashFunction1(k);
    int c=1;
    while(HT[index]!=-1&&c<m){
        index = hashMix(c,k);
        c++;
    }
    if(HT[index]!=-1){
        cout<<"INFINITY ERROR";
        return false;
    }
    else {
        HT[index]=k;
        return true;
    }
}

int Search(int k){
    int index = hashFunction1(k);
    int c=1;
    while(HT[index]!=-1&&c<m){
        if(HT[index]==k) {
            cout<<"Found "<<k<< " at "<<index<<endl;
            return index;
        }
        index = hashMix(c,k);
        c++;
    }
    cout<<"Not Found !!\n";
    return -1;
}


bool Delete(int k){
    int index = Search(k);
    if(index==-1){
        return false;
    }
    else {
        HT[index] = -1;
        return true;
    }
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

void printHT(){
    for(int i=0;i<m;i++){
        cout<<HT[i]<<" ";
    }cout<<endl;
}







void init_(){

    sieve();
    p = vprime[upper_bound(vprime.begin(), vprime.end(), n)-vprime.begin()];
    m = p;
    HT.resize(m,-1);
    b = rand()%p;
    b2 = rand()%p;
    a = rand()%(p-1)+1;
    a2 = rand()%(p-1)+1;
//    cout<<a<<" "<<a2<<" "<<b<<" "<<b2;
}


int main(){

	cin>>n;

    init_();

    Insert(1);
    printHT();
    Insert(2);
     printHT();
    Insert(3);
     printHT();
    Insert(4);
     printHT();
    Search(1);
    Search(4);
    Search(5);
    Delete(4);
     printHT();
    Search(4);





	return 0;
}
