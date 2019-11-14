#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	int rank_;

	Node *left, *right;
};

Node* newNode(int k){
	Node* temp = new Node();
	temp->key = k;
	temp->left = nullptr;
	temp->right = nullptr;
	temp->rank_ = rand()%100;

	return temp;
}


Node* leftRotate(Node *x){
    Node *y;
    y = x->right;
    Node *z;
    z = y->left;
    y->left = x;
    x->right = z;
    return y;
}


Node* rightRotate(Node *x){
    Node *y;
    y = x->left;
    Node *z;
    z = y->right;
    y->right = x;
    x->left = z;
    return y;
}


Node* insert(Node* root, int key){
	if(root == nullptr){
		return newNode(key);
	}

	if(root->key > key){
		root->left = insert(root->left,key);
		if(root->rank_ < root->left->rank_){
			root = rightRotate(root);
		}
	}
	else if(root->key < key){
		root->right = insert(root->right,key);
		if(root->rank_ < root->right->rank_){
			root = leftRotate(root);
		}
	}
	else {
		cout<<"sdfsjdfkl";
	}

	return root;
}


Node* search(Node* root,int key){

	if(root == nullptr){
		cout<<"NOT FOUND"<<endl;
		return root;
	}

	else if (root->key == key){
		cout<<"FOUND "<<key<<endl;
		return root;
	}
	if(root->key > key){
		return search(root->left, key);
	}
	else {
		return search(root->right, key);
	}
}

void func(Node* node){
    cout<<node->key<<" ("<<node->rank_<<")"<<endl;
}

void inorderTraversal(Node* root){
    if(root == nullptr) return;
    inorderTraversal(root->left);
    func(root);
    inorderTraversal(root->right);
}

void postorderTraversal(Node* root){
    if(root == nullptr) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    func(root);
}

void preorderTraversal(Node* root){
    if(root == nullptr) return;
    func(root);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}


Node* Delete(Node* node, int key){
 if (node == nullptr){
        cout<<"Not Found !!"<<endl;
        return nullptr;
    }
    else if(key > node->key){
        node->right = Delete(node->right, key);
    }
    else if(key < node->key){
        node->left = Delete(node->left, key);
    }
    else {
        if(node->left == nullptr){
            Node* temp  = node->right;
            delete node;
            return temp;
        }
        else if(node->right == nullptr){
            Node* temp  = node->left;
            delete node;
            return temp;
        }
        else {
           if(node->left->rank_ < node->right->rank_){
           		node = leftRotate(node);
           		node->left = Delete(node->left, key);
           }
           else {
           		node = rightRotate(node);
           		node->right = Delete(node->right, key);
           }
        }
    }

    return node;
}


Node* extractMax(Node* root){
	root = Delete(root, root->key);
	return root;
}


int main(){

	Node* root = nullptr;
	root = insert(root, 13);
	root = insert(root, 15);
	root = insert(root, 7);
	root = insert(root, 17);
	root = insert(root, 11);
	root = insert(root, 5);
	root = insert(root, 3);
	search(root, 1);
	search(root, 3);
	inorderTraversal(root);
	cout<<endl;
	preorderTraversal(root);




	return 0;
}
