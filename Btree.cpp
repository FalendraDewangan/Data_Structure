#include <iostream>
using namespace std;

class Node
{
    int ele;
    Node *left = NULL;
    Node *right = NULL;
    int height = 0;
    friend class AVL_tree;
};

class AVL_tree
{
    Node *root;

public:
    AVL_tree()
    {
        root = NULL;
    }
    void insert(int obj)
    {
        Node *temp = new Node;
        temp->ele = obj;
        Node *temp_root = root;
        Node *parent = NULL;
        while (temp_root != NULL)
        {
            parent = temp_root;
            if (temp->ele < temp_root->ele)
                temp_root = temp_root->left;
            else
                temp_root = temp_root->right;
        }
        if (parent == NULL)
            this->root = temp;
        else if (temp->ele < parent->ele)
            parent->left = temp;
        else
            parent->right = temp;
    }

    // void insert(Node* &root , int x){
    //     if(root==NULL){
    //         root=new Node;
    //         root->ele=x;
    //     }
    //     if(x<root->ele)
    //         insert(root->left,x);
    //     else if(x>root->ele)
    //         insert(root->right,x);
    // }
    
    void delete_copy(int x){
        if(root==0)
            throw "Empty tree";
        Node* temp_root=root;
        Node* parent=NULL;
        while(temp_root!=0 && temp_root->ele!=x){
            parent=temp_root;
            if(x<temp_root->ele)
                temp_root=temp_root->left;
            else
                temp_root=temp_root->right;
        }
        if(temp_root==0)
            throw "Element is not present";
        
        if(parent!=0) 
            temp_root->ele=(x<parent->ele) ? true:false; // if left = true or if right = false

        // if deleted node is leaf node
        if(temp_root->left==0 && temp_root->right==0){
            if(parent==0){
                delete temp_root;
                root==0;
                return;
            }
            if(temp_root->ele) 
                parent->left=0;
            else 
                parent->right=0;
            delete temp_root;
        }

        // if deleted node has left only
        else if(temp_root->right==0){
            if(parent==0){
                root=temp_root->left;
                delete temp_root;
                return;
            }
            if(temp_root->ele)
                parent->left=temp_root->left;
            else 
                parent->right=temp_root->left;
        }

        // if deleted node has right only
        else if(temp_root->left==0){
            if(parent==0){
                root=temp_root->right;
                delete temp_root;
                return;
            }
            if(temp_root->ele)
                parent->left=temp_root->right;
            else 
                parent->right=temp_root->right;
            delete temp_root;
        }

        // if both children exist
        else
        {
            Node* q=temp_root->right;
            Node* fq=temp_root;
            while(q->left!=0){
                fq=q;
                q=q->left;
            }
            temp_root->ele=q->ele;
            if(q->ele<fq->ele)
                fq->left=q->right;
            // else
            //     fq->right=q->right;          left does not exist 
            delete q;
        }   
    }

    void updateHeight(Node* &node){
        if(node->left==0 && node->right==0)
            return;
        else if(node->left!=0 && node->right==0)
            updateHeight(node->left);
        else if(node->left==0 && node->right!=0)
            updateHeight(node->right);
        else{
            updateHeight(node->left);
            updateHeight(node->right);
        }
        node->height=1+(node->left->height > node->right->height ? node->left->height : node->right->height);
    }

    void balance(Node* &node , int x){
        
    }
};

int main()
{

    return 0;
}