#include<bits/stdc++.h>

using namespace std;

// struct Node{
// 	 int user;
// 	 int val;
//     Node *left;
//     Node *right;
//     int height;
// };

// Node* newNode(int user, int val)
// {
//     Node* node = new Node();
//     node->user = user;
//     node->val = val;
//     node->left = NULL;
//     node->right = NULL;
//     node->height = 1;
//     return(node);
// }

// int height(Node *node)
// {
//     if (node == NULL)
//         return 0;
//     return node->height;
// }

// int hdiff(Node *node)
// {
//     if (node == NULL)
//         return 0;
//     return height(node->left) - height(node->right);
// }

// Node *leftRotate(Node *x)
// {
//     Node *y = x->right, *T2 = y->left;

//     y->left = x;
//     x->right = T2;

//     x->height = max(height(x->left),height(x->right)) + 1;
//     y->height = max(height(y->left),height(y->right)) + 1;

//     return y;
// }


// Node *rightRotate(Node *y)
// {
//     Node *x = y->left;
//     Node *T2 = x->right;

//     x->right = y;
//     y->left = T2;

//     y->height = max(height(y->left),height(y->right)) + 1;
//     x->height = max(height(x->left),height(x->right)) + 1;
//     return x;
// }
// int getBalance(Node *N)
// {
//     if (N == NULL)
//         return 0;
//     return height(N->left) - height(N->right);
// }
// Node* insert(Node* node, int user, int val)
// {
//     /* 1. Perform the normal BST insertion */
//     if (node == NULL)
//         return(newNode(user, val));

//     if (user < node->user)
//         node->left = insert(node->left, user, val);
//     else if (user > node->user)
//         node->right = insert(node->right, user, val);
//     else // Equal users are not allowed in BST
//         return node;

//     /* 2. Update height of this ancestor node */
//     node->height = 1 + max(height(node->left),
//                         height(node->right));

//     /* 3. Get the balance factor of this ancestor
//         node to check whether this node became
//         unbalanced */
//     int balance = getBalance(node);

//     // If this node becomes unbalanced, then
//     // there are 4 cases

//     // Left Left Case
//     if (balance > 1 && user < node->left->user)
//         return rightRotate(node);

//     // Right Right Case
//     if (balance < -1 && user > node->right->user)
//         return leftRotate(node);

//     // Left Right Case
//     if (balance > 1 && user > node->left->user)
//     {
//         node->left = leftRotate(node->left);
//         return rightRotate(node);
//     }

//     // Right Left Case
//     if (balance < -1 && user < node->right->user)
//     {
//         node->right = rightRotate(node->right);
//         return leftRotate(node);
//     }

//     /* return the (unchanged) node pointer */
//     return node;
// }


// Node* search( Node* root, int x)
// {
//     if (root == nullptr)
//        return nullptr;

//     if(x==root->user)
//     	return root;
//     if (x>root->user)
//        return search(root->right, x);

//     else
//     	return search(root->left, x);
// }

int binarySearch(vector<int> &vec, int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;


		if (vec[mid] == x)
			return mid;


		if (vec[mid] > x)
			return binarySearch(vec, l, mid - 1, x);


		return binarySearch(vec, mid + 1, r, x);
	}


	return -1;
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


int partition (vector<int> &vec, int low, int high)
{
	int pivot = vec[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (vec[j] < pivot)
		{
			i++;
			swap(&vec[i], &vec[j]);
		}
	}
	swap(&vec[i + 1], &vec[high]);
	return (i + 1);
}

void quickSort(vector<int> &vec, int low, int high)
{
	if (low < high)
	{

		int pi = partition(vec, low, high);

		quickSort(vec, low, pi - 1);
		quickSort(vec, pi + 1, high);
	}
}




int main(){
	int n,option,user,recharge;
	cin>>n;
	int t,q=0;
	vector<int> a,ud[2];
	int buser=-1,big=-1;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>option;
		if(option==1){
			cin>>user>>recharge;
			a.push_back(user);
			ud[0].push_back(user);
			ud[1].push_back(recharge);
			
			q++;
		}
		else {
			ud[0].push_back(1);
			ud[1].push_back(-1);
			
		}

	}

	vector<int> uid;
	vector<int> totrecharge;
// 	for(int i=0;i<q;i++){
// 	cout<<a[i]<<" ";
// }cout<<endl;
	quickSort(a,0,q-1);

// for(int i=0;i<q;i++){
// 	cout<<a[i]<<" ";
// }cout<<endl;

	for(int i=0;i<q-1;i++){
		if(a[i]!=a[i+1]){
			uid.push_back(a[i]);
			totrecharge.push_back(0);

		}

	}
	uid.push_back(a[q-1]);
	totrecharge.push_back(0);

	// for(int i=0;i<totrecharge.size();i++){
	// 	cout<<uid[i]<<" "<<totrecharge[i]<<endl<<endl;
	// }

	for(int i=0;i<t;i++){
		if(ud[1][i]==-1){
			if(buser!=-1)
				cout<<buser<<endl;
			else cout<<"No data available."<<endl;
		}
		else {
			int x = binarySearch(uid, 0, uid.size()-1, ud[0][i]);
			if(x!=-1){
				totrecharge[x]+=ud[1][i];
				if(big<totrecharge[x]){
					big = totrecharge[x];
					buser = uid[x];
				}
			}
		}
	}

	return 0;
}
