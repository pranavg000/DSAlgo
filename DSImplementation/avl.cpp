#include<iostream>

using namespace std;

struct Node{
	int val;
    Node *left;
    Node *right;
    int height;
};

Node* newNode(int val){
    Node* node = new Node();
    node->val = val;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return(node);
}

int getHeight(Node *node){
    if (node == nullptr)
        return 0;
    return node->height;
}

int hdiff(Node *node){
    if (node == nullptr)
        return 0;
    return getHeight(node->left)-getHeight(node->right);
}

Node *leftRotate(Node *x){
    Node *y = x->right;

    Node *T2 = y->left;
    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left),getHeight(x->right))+1;

    y->height = max(getHeight(y->left),getHeight(y->right))+1;

    return y;
}


Node *rightRotate(Node *y){
    Node *x = y->left;

    Node *T2 = x->right;
    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left),getHeight(y->right))+1;

    x->height = max(getHeight(x->left),getHeight(x->right))+1;

    return x;
}


int getBalance(Node *N)
{
    if (N == nullptr){
        return 0;
    }
    return getHeight(N->left)-getHeight(N->right);
}

int f=-1;
Node* insertMain(Node* node, int val)
{
    /* 1. Perform the normal BST insertion */
    if (node == nullptr){
        return(newNode(val));
    }

    if (val<node->val){
            node->left = insertMain(node->left, val);
        }
    else if (val>node->val){
            node->right = insertMain(node->right, val);
        }
    else{
            cout<<"Same value Found !!"<<endl<<"Aborting...";
            exit(0);
            return node;
        }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));



    if(f==-1){
        int balance = getBalance(node);

        if(balance>1){
            f=1;
            if(val<(node->left->val)){

                return rightRotate(node);
            }
            else if(val>(node->left->val)){
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }
        else if(balance<-1){
            f=1;
             if(val<(node->right->val)){

                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
            else if(val>(node->right->val)){
                return leftRotate(node);
            }
        }

}
    return node;
}



Node* insert(Node* node, int val){
    f=-1;
    return insertMain(node, val);

}


Node* minimum(Node* node){
    while(node->left != nullptr){
        node = node->left;
    }
    return node;
}



Node* deleteNode(Node* root, int x){
    if (root == nullptr){
        cout<<"Not Found !!"<<endl;
        return nullptr;
    }
    else if(x > root->value){
        root->right = deleteNode(root->right, x);
    }
    else if(x < root->value){
        root->left = deleteNode(root->left, x);
    }
    else {
        if(root->left == nullptr){
            Node* temp  = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr){
            Node* temp  = root->left;
            delete root;
            return temp;
        }
        else {
            Node* temp  = minimum(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
            return root;
        }
    }

    if (root == nullptr){
        return nullptr;
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    


}







Node* search( Node* root, int x)
{
    if (root == nullptr)
       return nullptr;

    if(x == root->val)
    	return root;
    if (x>root->val)
       return search(root->right, x);

    else
    	return search(root->left, x);
}

void func(Node* node){
    cout<<node->val<<" ";
}


void preorderTraversal(Node* root){
    if(root == nullptr) return;
    func(root);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}





int main()
{
    Node *root = NULL;

    /* Constructing tree given in
    the above figure */
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    /* The constructed AVL Tree would be
                30
            / \
            20 40
            / \ \
        10 25 50
    */
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preorderTraversal(root);

    return 0;
}
