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
    cout<<node->key<<" ";
}

void inorderTraversal(Node* root){
    if(root == nullptr) return;
    inorderTraversal(root->left);
    func(root);
    inorderTraversal(root->right);
}

//void inorder(Node* root)
//{
//    if (root)
//    {
//        inorder(root->left);
//        cout << "key: "<< root->key << " | rank_: %d "
//            << root->rank_;
//        if (root->left)
//            cout << " | left child: " << root->left->key;
//        if (root->right)
//            cout << " | right child: " << root->right->key;
//        cout << endl;
//        inorder(root->right);
//    }
//}


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
//	root = insert(root, 50);
//    root = insert(root, 30);
//    root = insert(root, 20);
//    root = insert(root, 40);
//    root = insert(root, 70);
//    root = insert(root, 60);
//    root = insert(root, 80);
//	// search(root, 1);
//	// search(root, 2);
//	// search(root, 3);
//	// search(root, 4);
//	inorder(root);
//
//	cout << "Inorder traversal of the given tree \n";
//    inorder(root);
//
//    cout << "\nDeletee 20\n";
//    root = Delete(root, 20);
//    cout << "Inorder traversal of the modified tree \n";
//    inorder(root);
//
//    cout << "\nDeletee 30\n";
//    root = Delete(root, 30);
//    cout << "Inorder traversal of the modified tree \n";
//    inorder(root);
//
//    cout << "\nDeletee max\n";
//    root = extractMax(root);
//    cout << "Inorder traversal of the modified tree \n";
//    inorder(root);
//
//
//    cout << "\nDeletee max\n";
//    root = extractMax(root);
//    cout << "Inorder traversal of the modified tree \n";
//    inorder(root);
//
//
//    cout << "\nDeletee max\n";
//    root = extractMax(root);
//    cout << "Inorder traversal of the modified tree \n";
//    inorder(root);
//
//    Node *res = search(root, 50);
//    (res == NULL)? cout << "\n50 Not Found ":
//                   cout << "\n50 found";
//


	return 0;
}
