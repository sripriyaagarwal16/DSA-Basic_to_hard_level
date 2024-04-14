#include<iostream>
#include<queue>
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
//taking input level wise
BinaryTreeNode<int>* takeinputlevelwise(){
    int rootdata;
    cout<<"Enter the data"<<endl;
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int>*>pendingnodes;
    pendingnodes.push(root);
    while(!pendingnodes.empty()){
        BinaryTreeNode<int>*front=pendingnodes.front();
        pendingnodes.pop();
        cout<<"enter the left the child of the "<<front->data<<endl;
        int leftchilddata;
        cin>>leftchilddata;
        if(leftchilddata!=-1){
        BinaryTreeNode<int>*leftchild=new BinaryTreeNode<int>(leftchilddata);
        front->left=leftchild;
        pendingnodes.push(leftchild);
        }
        cout<<"enter the right the child of the "<<front->data<<endl;
        int rightchilddata;
        cin>>rightchilddata;
        if(rightchilddata!=-1){
        BinaryTreeNode<int>*rightchild=new BinaryTreeNode<int>(rightchilddata);
        front->right=rightchild;
        pendingnodes.push(rightchild);
        }


    }
    return root;
}
//printing level wise
void printlevelwise(BinaryTreeNode<int>*root){
    if(root==NULL){
        return;
    }
    queue<BinaryTreeNode<int>*>pendingnodes;
    pendingnodes.push(root);
    while(!pendingnodes.empty()){
        BinaryTreeNode<int>*front=pendingnodes.front();
        pendingnodes.pop();
        cout<<front->data<<":"<<endl;
        if(front->left!=NULL){
            cout<<"L"<<":"<<front->left->data<<endl;
            pendingnodes.push(front->left);
        }else{
            cout<<"L"<< ":"<<"-1"<<endl;
        }
        if(front->right!=NULL){
            cout<<"R"<<":"<<front->right->data<<endl;
            pendingnodes.push(front->right);
        }else{
            cout<<"R"<<":"<<"-1"<<endl;
        }
        cout<<endl;
    }
}
bool findnode(BinaryTreeNode<int>*root,int X){
    if(root==NULL){
        return false;
    }
    if(root->data==X){
        return true;
    }
    bool leftfound=findnode(root->left,X);
    if(leftfound){
        return true;
    }
    bool rightfound=findnode(root->right,X);
    return rightfound;
}
int main(){
    BinaryTreeNode<int>*root=takeinputlevelwise();
    int X;
    cout<<"Enter the number you want to find the tree"<<endl;
    cin>>X;
    bool found=findnode(root,X);
    cout<<found<<endl;

}