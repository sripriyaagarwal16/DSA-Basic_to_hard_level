#include<iostream>
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
//takeinput
BinaryTreeNode<int>* takeinput(){
    int rootdata;
    cout<<"Enter the  data"<<endl;
    cin>>rootdata;
    if(rootdata=-1){
        return NULL;
    }
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootdata);
    BinaryTreeNode<int>*node1=takeinput();
    BinaryTreeNode<int>*node2=takeinput();
    root->left=node1;
    root->right=node2;
    return root;

}
//print tree 
void printtree(BinaryTreeNode<int>*root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<":"<<endl;
    if(root->left!=NULL){
         cout<<"L"<<" "<<":"<<root->left->data<<" ";
    }
    if(root->right!=NULL){
        cout<<"R"<<" "<<":"<<root->right->data;
    }
    cout<<endl;
    printtree(root->left);
    printtree(root->right);
}
int main(){
BinaryTreeNode<int>*root=takeinput();
printtree(root);

}