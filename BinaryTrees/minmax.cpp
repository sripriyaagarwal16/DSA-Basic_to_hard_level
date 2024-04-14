#include<iostream>
#include<queue>
#include<algorithm>
#include<climits>
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
pair<int,int>minmax(BinaryTreeNode<int>*root){
    if(root==NULL){
        pair<int,int>p;
        p.first=INT_MAX;
        p.second=INT_MIN;
        return p;
    }
    if(root->left==NULL&&root->right==NULL){
        pair<int,int>p;
        p.first=root->data;
        p.second=root->data;
        return p;
    }
    pair<int,int>leftans=minmax(root->left);
    pair<int,int>rightans=minmax(root->right);
    int lmin=leftans.first;
    int lmax=leftans.second;
    int rmin=rightans.first;
    int rmax=rightans.second;
    int rootdata=root->data;
    int minimum=min(rootdata,min(lmin,rmin));
    int maximum=max(rootdata,max(lmax,rmax));
    pair<int,int>p;
    p.first=minimum;
    p.second=maximum;
    return p;
}
int main(){
    BinaryTreeNode<int>*root=takeinputlevelwise();
    pair<int,int>p=minmax(root);
    cout<<"the maximum element in the binarytree is :"<<p.second<<endl;
    cout<<"the minimum element in the binarytree is :"<<p.first<<endl;
    


}