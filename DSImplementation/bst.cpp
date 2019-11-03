#include<iostream>
using namespace std;



struct BstNode
{
    int value;
    struct BstNode *left, *right;
};


BstNode* newBstNode(int x)
{
    BstNode *temp =  new BstNode;
    temp->value=x;
    temp->right = nullptr;
    temp->left=nullptr;
    return temp;
}

BstNode* search( BstNode* root, int x)
{
    if (root == nullptr)
    {
        cout<<"Not Found!!"<<endl;
        return nullptr;
    }

    if(x==(root->value))
    	return root;

    if (x>(root->value))
       return search(root->right, x);

    else
    	return search(root->left, x);
}

BstNode* insert(BstNode* node, int x)
{
    int f=0;
    BstNode* temp = newBstNode(x);
    if (node == nullptr){
    	return temp; //return root of the changed tree
    }
  	BstNode* foo = node;

    while(node!=nullptr){
    if (x < node->value)
    {
        if(node->left!=nullptr)
    	node = node->left;
        else {
            f=1;
            break;
        }

    }
    else if (x > node->value)
    {
        if(node->right!=nullptr)
        node = node->right;
        else{
            f=2;
            break;
        }
    }
    else {
        cout<<"Same value Found !!"<<endl<<"Aborting...";
        exit(0);
    }
    }
    {
    	if (f==1) {
    	node->left=temp;

    }
    else if (f==2)
       node->right=temp;
    else {
    	cout<<"Same value Found !!"<<endl<<"Aborting...";
        exit(0);
    }
    }

    return foo; //return root
}

BstNode* minimum(BstNode* node){
    while(node->left != nullptr){
        node = node->left;
    }
    return node;
}


BstNode* maximum(BstNode* node){
    while(node->right != nullptr){
        node = node->right;
    }
    return node;
}


//returns root of modified bst
BstNode* deleteBstNode(BstNode* root, int x){
    if (root == nullptr){
        cout<<"Not Found !!"<<endl;
        return nullptr;
    }
    else if(x > root->value){
        root->right = deleteBstNode(root->right, x);
    }
    else if(x < root->value){
        root->left = deleteBstNode(root->left, x);
    }
    else {
        if(root->left == nullptr){
            BstNode* temp  = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr){
            BstNode* temp  = root->left;
            delete root;
            return temp;
        }
        else {
            BstNode* temp  = minimum(root->right);
            root->value = temp->value;
            root->right = deleteBstNode(root->right, temp->value);
            return root;
        }
    }
}

void func(BstNode* node){
    cout<<node->value<<" ";
}

void inorderTraversal(BstNode* root){
    if(root == nullptr) return;
    inorderTraversal(root->left);
    func(root);
    inorderTraversal(root->right);
}

void preorderTraversal(BstNode* root){
    if(root == nullptr) return;
    func(root);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(BstNode* root){
    if(root == nullptr) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    func(root);
}


void deleteTree(auto node)
{
    if (node == NULL) return;

    deleteTree(node->left);
    deleteTree(node->right);
    free(node);
}




int main(){


    return 0;
}
