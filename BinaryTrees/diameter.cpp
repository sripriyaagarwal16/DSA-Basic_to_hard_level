#include<iostream>
#include<queue>
#include<algorithm>
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
int height(BinaryTreeNode<int>*root){
    if(root==NULL){
        return 0;
    }
    int leftheight=0;
    if(root->left!=NULL){
        leftheight=height(root->left);
    }
    int rightheight=0;
    if(root->right!=NULL){
        rightheight=height(root->right);
    }
    int h=max(leftheight,rightheight)+1;
    return h;
}
int diameter(BinaryTreeNode<int>*root){
    if(root==NULL){
        return 0;
    }
    int option1=height(root->left)+height(root->right);
    int option2=diameter(root->left);
    int option3=diameter(root->right);
    return max(option1,max(option2,option3));
}
//better approach to find diameter 
pair<int,int>heightdiameter(BinaryTreeNode<int>*root){
    if(root==NULL){
        pair<int,int>p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int>leftans=heightdiameter(root->left);
    pair<int,int>rightans=heightdiameter(root->right);
    int ld=leftans.second;
    int lh=leftans.first;
    int rh=rightans.first;
    int rd=rightans.second;
    int height=1+max(lh,rh);
    int diameter=max(lh+rh,max(ld,rd));
    pair<int,int>p;
    p.first=height;
    p.second=diameter;
    return p ;

}

int main(){
    BinaryTreeNode<int>*root=takeinputlevelwise();
    pair<int,int>d =heightdiameter(root);
    cout<<"the diameter of the tree is :"<<d.second<<endl;
}