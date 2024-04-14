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


void printelementrange(BinaryTreeNode<int>*root,int k1,int k2 ){
     if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        if (k1 <= root->data && root->data <= k2) {
            cout << root->data << " ";
        }
        return;
    }

    if (root->data < k1) {
        elementsInRangeK1K2(root->right, k1, k2);
    } else if (root->data > k2) {
        elementsInRangeK1K2(root->left, k1, k2);
    } else {
        elementsInRangeK1K2(root->left, k1, k2);
        cout << root->data << " ";
        elementsInRangeK1K2(root->right, k1, k2);
    }
}