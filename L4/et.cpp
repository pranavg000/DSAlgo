#include<bits/stdc++.h>

using namespace std;

struct tree
{
	string data;
	tree *left;
	tree *right;
};

int powe(int l, int r){
	int temp=1;
	for(int i=0;i<r;i++){
		temp*=l;
	}
	return temp;

}

int isOperand(char c)
{
	if(c=='^')
		return 3;
	else if(c=='*'||c =='/')
		return 2;
	else if(c=='+'||c== '-')
		return 1;
	else
		return -1;
}
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
			int d=2;
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



		int main(){

			int t;
			cin>>t;
			int n;
			for(int o=0;o<t;o++){
				string str;
				vector<string> pf;
				cin>>n;
				for(int i=0;i<n;i++){
					cin>>str;
					vector<string> m;
					string temp;

					for(int k=0;k<str.size();k++){
						if((str[k]=='(')){
							m.push_back(getString(str[k]));
							continue;
						}
						if((str[k]-'0')<10&&(str[k]-'0')>=0) {
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

					pf = intopo(m);


					tree* head = makeExpressionTree(pf);

					int ans = postOrder(head);
					cout<<ans<<endl;

				}
			}
			return 0;}
