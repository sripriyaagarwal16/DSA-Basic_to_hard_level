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
void printpath(const vector<int>&path){
    for(int i =0;i<path.size();i++){
        cout<<path[i]<<" ";

    }
    
}
void printroottoleafpathhelper(BinaryTreeNode<int>*root,int k ,vector<int>&path,int currentsum){
    if(root==NULL){
        return ;
    }
    currentsum+=root->data;
    path.push_back(root->data);
    if(root->left==NULL&&root->right==NULL&&currentsum==k){
        printpath(path);
    }
    printroottoleafpathhelper(root->left,k ,path,currentsum);
    printroottoleafpathhelper(root->right,k ,path,currentsum);
    path.pop_back();
}
void printtoleafpath(BinaryTreeNode<int>*root,int k){
    vector<int>path;
    printroottoleafpathhelper(root,k ,path,0);

}
int main(){
    BinaryTreeNode<int>*root=takeinputlevelwise();
    int k ;
    cout<<"enter the number"<<endl;
    cin>>k;
    printtoleafpath(root,k);
}