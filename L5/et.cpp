#include<bits/stdc++.h>

using namespace std;

struct tree
{
	string data;
	tree *left;
	tree *right;
};

struct bstnode
{
    string var;
    int val;
    struct bstnode *left, *right;
};

int comparetwo(string ca, string cb){
int la = ca.size();
int lb = cb.size();

int f=0;
int ds;
string ans;

if(la>lb){
	f=1;
}
else if(la<lb){
	f=2;
}
else {
	for(int i=0;i<la;i++){
		if((ca[i]-'0')>(cb[i]-'0')){
			f=1; break;
		}
		if((ca[i]-'0')<(cb[i]-'0')){
			f=2; break;
		}

	}
}

return f;
}


bstnode* newbstNode(string x, int v)
{
    bstnode *temp =  new bstnode;
    temp->var = x;
    temp->val = v;
    temp->left = temp->right = nullptr;
    return temp;
}

bstnode* search( bstnode* root, string x)
{
    if (root == nullptr)
       return nullptr;

    if(x.compare(root->var)==0)
    	return root;
    if (x.compare(root->var)>0)
       return search(root->right, x);

    else
    	return search(root->left, x);
}

bstnode* insert(bstnode* node, string x, int v)
{int f=0;

    bstnode* temp = newbstNode(x,v);
    if (node == nullptr){
    	// cout<<temp->val<<" %";
    	return temp;
    }
  	bstnode* foo = node;

    while(node!=nullptr){
    if (x.compare(node->var)<0) {
    	if(node->left==nullptr)
    	// node=node->left;
    	{
    		f=1;
    	break;
    	}

    }
    else if (x.compare(node->var)>0)
    if(node->right==nullptr)
        // node=node->right;
    {

        f=2;
        break;}
    else {
    	cout<<"NOOO";
    }
}
    {
    	if (f==1) {
    	node->left=temp;

    }
    else if (f==2)
       node->right=temp;
    else {
    	cout<<"NOOO";
    }
    }

    return foo;
}

void deleteTree(auto node)
{
    if (node == NULL) return;

    deleteTree(node->left);
    deleteTree(node->right);



    free(node);
}


int powe(int l, int r){
	int temp=1;
	for(int i=0;i<r;i++){
		temp*=l;
	}
	return temp;

}
int isOperand(char c)
{   if(c=='#')
return 4;
if(c=='^')
	return 3;
else if(c=='*'||c =='/')
	return 2;
else if(c=='+'||c== '-')
	return 1;
else
	return -1;
}

int isOper(char c)
{   if((isOperand(c)==-1)&& c!='('&&c!=')')
return 1;
else return 0;
}

bstnode* root=nullptr;

tree* newNode(string v){
	tree *node;
	node = new tree;
	node->data= v;
	node->left = nullptr;
	node->right = nullptr;
	return node;
}

tree* makeExpressionTree(vector<string> pf){

	stack<tree*> s;
	tree* l,*r, *head;
	for(int i=0;i<pf.size();i++){

		if(isOperand(pf[i][0])!=-1){

			if(isOperand(pf[i][0])!=4)
			{

				r = s.top();
				s.pop();
				l = s.top();
				s.pop();
				head = newNode(pf[i]);
				head->left = l;
				head->right = r;
				s.push(head);
			}
			else {

				l = s.top();

				s.pop();
				head = newNode(pf[i]);
				head->left = l;
				s.push(head);
			}
		}
		else {
			tree *temp = newNode(pf[i]);
			s.push(temp);
		}

	}

	return head;}

	int postOrder(tree* he){

		if(he->left!=nullptr&&he->right!=nullptr)
			{int r = postOrder(he->right);
				int l = postOrder(he->left);
				int d;
				switch((he->data)[0]){

					case '+':{
						d = l+r;
						break;
					}
					case '-':{
						d = l-r;
						break;
					}
					case '*':{
						d = l*r;
						break;
					}
					case '/':{
						d = l/r;
						break;
					}
					case '^':{
						d = powe(l,r);
						break;
					}

				}
				return d;

			}

			if(he->left!=nullptr&&he->right==nullptr){
				int l = postOrder(he->left);
				int d;
				switch((he->data)[0]){

					case '#':{
						d = (-1)*l;
						break;
					}


				}
				return d;
			}

			else return stoi(he->data);

		}



		string getString(char x)
		{

			string s(1, x);

			return s;
		}



		vector<string> intopo(vector<string> str){
			int len = str.size();
			stack<char> s;
			vector<string> pf;
			for(int i=0;i<len;i++){
				if((str[i].size()==1)&&isOperand(str[i][0])!=-1){

					if(s.empty()) s.push(str[i][0]);
					else if (isOperand(str[i][0])==3){
						if(isOperand(str[i][0])>=isOperand(s.top())){
							s.push(str[i][0]);
						}
						else {while(!s.empty()&&(isOperand(str[i][0])<isOperand(s.top()))){
							pf.push_back(getString(s.top()));
							s.pop();
						}
						s.push(str[i][0]);}
					}
					else if(isOperand(str[i][0])>isOperand(s.top())){
						s.push(str[i][0]);
					}
					else {while(!s.empty()&&(isOperand(str[i][0])<=isOperand(s.top()))){
						pf.push_back(getString(s.top()));
						s.pop();
					}
					s.push(str[i][0]);}

				}
				else if(str[i][0]=='('){
					s.push(str[i][0]);
				}
				else if(str[i][0]==')'){

					while(s.top()!='('){
						pf.push_back(getString(s.top()));
						s.pop();

					}
					if(s.top()=='('){
						s.pop();
					}

				}
				else {
					pf.push_back(str[i]);
				}
			}
			while(!s.empty()){

				pf.push_back(getString(s.top()));
				s.pop();

			}
			return pf;
		}


		string unaryMinus(string str){
			if(str[0]=='-'){
				str[0]='#';
			}
			for(int i=1;i<str.size();i++){
				if(str[i]=='-'&& (((!isOper(str[i-1]))||(str[i-1]=='='))))
				{
					str[i]='#';
				}

			}

			return str;
		}

		int numsvectoans(vector<string> m){
			int ans;
			vector<string> pf;

			pf = intopo(m);
			if(pf.size()==1) {
				ans=stoi(pf[0]);
			}
			else  {
				tree* head = makeExpressionTree(pf);

				ans = postOrder(head);
				deleteTree(head);
			}
			return ans;

		}
		int kvartoans(vector<string> m,int st){


				for(int i=st;i<m.size();i++){
					if(isOper(m[i][0])&&(!((m[i][0]-'0')<10&&(m[i][0]-'0')>=0))){

						bstnode* t;
						t = search(root,m[i]);
						if(t==nullptr){
							return (-2147483647);
						}
						else {
							m[i]=to_string(t->val);
						}
					}
				}

                vector<string> mt;
                for(int i=st;i<m.size();i++){
                mt.push_back(m[i]);}

				return numsvectoans(mt);

			}


			int main(){

				int t;
				cin>>t;
				int n;
				for(int o=0;o<t;o++){
					string str;
					cin>>n;
					for(int u=0;u<n;u++){
						cin>>str;

						str=unaryMinus(str);

						vector<string> m;
						string temp;




						for(int k=0;k<str.size();k++){
							if((str[k]=='(')){
								m.push_back(getString(str[k]));
								continue;
							}
							if(isOper(str[k])&&str[k]!='=') {
								temp+=str[k];
							}
							else {
								if(temp!="")
									m.push_back(temp);
								m.push_back(getString(str[k]));
								temp="";
							}

						}
						if(temp!="")
							m.push_back(temp);
						temp="";







						int f=1;


						for(int i=0;i<m.size();i++){
							if(m[i][0]=='=')
							{
								f=2;
							}
						}
						 // for(int i=0;i<m.size();i++){
						 // 	cout<<m[i]<<" ";}
						// 	cout<<"*"<<endl;


							if(f==2){
								for(int i=0;i<m.size()-1;i++){
								if(((m[i][0]-'0')<10&&(m[i][0]-'0')>=0)){
								f=-1; break;
								}
									if(isOper(m[i][0])&&(!((m[i][0]-'0')<10&&(m[i][0]-'0')>=0))){
										//cout<<"-="<<m[i+1]<<endl;

										if((i<(m.size()-1))&&(m[i+1][0]=='=')){


											int tem = kvartoans(m,i+2);

											if(tem != (-2147483647)){
												bstnode* t;
												t = search(root,m[i]);
												if(t==nullptr){
													root = insert(root,m[i],tem);
												}
												else {
													t->val = tem;
												}
												break;
											}
											else {
												f=-1;
												break;
											}

										}

									}
								}
							}




							if(f==1)
							{

								int ans = kvartoans(m,0);
								if(ans != (-2147483647)){

									cout<<ans<<endl;}
									else cout<<"CANT BE EVALUATED"<<endl;
								}
								else if(f==-1){
									cout<<"CANT BE EVALUATED"<<endl;
								}


							}
							deleteTree(root);
							root=nullptr;

						}
						return 0;}
