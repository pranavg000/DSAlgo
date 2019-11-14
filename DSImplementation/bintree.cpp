#include <bits/stdc++.h>

using namespace std;



struct Node
{
public:
    int data;
    bool insertleft;
    Node *left, *right, *parent;


};


Node* newNode(int x){
    Node* t = new Node();
    t->data = x;
    t->left = nullptr;
    t->right = nullptr;
    t->parent = nullptr;
    t->insertleft = true;

    return t;
}

void insertnoderight(Node *parent, Node *node)
{
    node->right = parent->right;
    parent->right = node;
    node->parent = parent;
    node->insertleft = false;
    return;
}


void insertnodeleft(Node *parent, Node *node)
{
    node->left = parent->left;
    parent->left = node;
    node->insertleft = true;
    node->parent = parent;
    return;
}


void inorder(Node *temp)
{
    if (!temp)
        return;
    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
    return;
}


Node *depp(Node *temp)
{
    if (temp == nullptr)
        return nullptr;
    if ((temp->left == nullptr) && (temp->right == nullptr))
    {
        // cout<<temp->data;
        return temp;
    }
    else if(temp->left == nullptr){
        return depp(temp->right);
    }
    else if(temp->right == nullptr){
        return depp(temp->left);
    }
    else {
        return depp(temp->left);

    }
}


void deletenode(Node *temp)
{

    Node *t = depp(temp);
    if (t->parent == nullptr)
    {
        free(t);
        return;
    }
    temp->data = t->data;
    if ((t->insertleft) == true)
        {(t->parent)->left = nullptr;
        }
    else
        {(t->parent)->right = nullptr;}
    free(t);
}

int main()
{
    Node *n=newNode(50);
    Node *n1=newNode(16);
    Node *n2=newNode(23);
    Node *n3=newNode(14);
    // n.parent=&n;
    insertnoderight(n, n1);
    insertnodeleft(n, n2);
    insertnodeleft(n1, n3);
    // cout<<(n1.right==nullptr);
    // cout<<depp(&n)->data;

   // deletenode(n1);

    inorder(n);
    cout<<endl;
    deletenode(n1);
    inorder(n);
    return 0;
}
