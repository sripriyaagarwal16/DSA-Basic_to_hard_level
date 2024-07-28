#include<iostream>
#include<vector>
using namespace std; 
template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T>*left;
    BinaryTreeNode<T>*right;
    BinaryTreeNode(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }

};
class BST{
   BinaryTreeNode<int>*root;
   public:
   BST(){
    root=NULL;
   }
   ~BST(){
    delete root;
   }
   private:
   bool hasdata(int data,BinaryTreeNode<int>*node){
    if(node==NULL){
        return false;
    }
    if(root->data==data){
        return true;
    }
    bool leftfound=hasdata( data,node->left);
    if(leftfound){
        return true;
    }else{
        bool rightfound=hasdata( data,node->right);
        return rightfound;
    }
   }
    BinaryTreeNode<int>*insert(int data,BinaryTreeNode<int>*node){
        if(node==NULL){
            BinaryTreeNode<int>*newnode=new BinaryTreeNode<int>(data);
            return newnode;
        }
        if(data<node->data){
           node->left=insert( data,node->left);
        }
        else{
            node->right=insert(data,node->right);
        }
        return node;

    
   }
   BinaryTreeNode<int>* remove(int data, BinaryTreeNode<int>* node) {
        if (node == NULL) {
            return NULL;
        }

        if (data < node->data) {
            node->left = remove(data, node->left);
        } else if (data > node->data) {
            node->right = remove(data, node->right);
        } else {
            if (node->right == NULL && node->left == NULL) {
                // Case 1: Node has no children
                delete node;
                return NULL;
            } else if (node->right == NULL) {
                // Case 2: Node has only left child
                BinaryTreeNode<int>* temp = node->left;
                delete node;
                return temp;
            } else if (node->left == NULL) {
                // Case 3: Node has only right child
                BinaryTreeNode<int>* temp = node->right;
                delete node;
                return temp;
            } else {
                // Case 4: Node has both left and right children
                BinaryTreeNode<int>* minNode = node->right;
                while (minNode->left != NULL) {
                    minNode = minNode->left;
                }
                node->data = minNode->data;
                node->right = remove(minNode->data, node->right);
                return node;
            }
        }
        return node;
    }

   public:
   bool hasdata(int data){
      return hasdata(data,this->root);
   }
   BinaryTreeNode<int>*insert(int data){
     return insert(data,this->root);
   }
   BinaryTreeNode<int>* deletedata(int data){


   }


};