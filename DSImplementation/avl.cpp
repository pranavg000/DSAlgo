#include<iostream>

using namespace std;

struct Node{
	int value;
    Node *left;
    Node *right;
    int height;
};

Node* newNode(int value){
    Node* node = new Node();
    node->value = value;
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
Node* insertMain(Node* node, int value)
{
    /* 1. Perform the normal BST insertion */
    if (node == nullptr){
        return(newNode(value));
    }

    if (value<node->value){
            node->left = insertMain(node->left, value);
        }
    else if (value>node->value){
            node->right = insertMain(node->right, value);
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
            if(getBalance(node->left)>=0){
                return rightRotate(node);
            }
            else if(getBalance(node->left)<0){
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }
        else if(balance<-1){
            f=1;
             if(getBalance(node->right)>0){

                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
            else if(getBalance(node->right)<=0){
                return leftRotate(node);
            }
        }

}
    return node;
}



Node* insert(Node* node, int value){
    f=-1;
    return insertMain(node, value);

}


Node* minimum(Node* node){
    while(node->left != nullptr){
        node = node->left;
    }
    return node;
}



Node* deleteNode(Node* node, int x){
    if (node == nullptr){
        cout<<"Not Found !!"<<endl;
        return nullptr;
    }
    else if(x > node->value){
        node->right = deleteNode(node->right, x);
    }
    else if(x < node->value){
        node->left = deleteNode(node->left, x);
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
            Node* temp  = minimum(node->right);
            node->value = temp->value;
            node->right = deleteNode(node->right, temp->value);
            return node;
        }
    }

    if (node == nullptr){
        return nullptr;
    }
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
     
     int balance = getBalance(node);

        if(balance>1){
            f=1;
            if(getBalance(node->left)>=0){
                return rightRotate(node);
            }
            else if(getBalance(node->left)<0){
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }
        else if(balance<-1){
            f=1;
             if(getBalance(node->right)>0){

                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
            else if(getBalance(node->right)<=0){
                return leftRotate(node);
            }
        }
        return node;

}






Node* search( Node* root, int x)
{
    if (root == nullptr)
       return nullptr;

    if(x == root->value)
    	return root;
    if (x>root->value)
       return search(root->right, x);

    else
    	return search(root->left, x);
}

void func(Node* node){
    cout<<node->value<<" ";
}


void preorderTraversal(Node* root){
    if(root == nullptr) return;
    func(root);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}





int main()
{
    
    return 0;
}
