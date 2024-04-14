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
BinaryTreeNode<int>* buildtreedata(int *preorder, int prestart, int preend, int *inorder, int instart, int inend) {
    if ( instart >inend) {
        return NULL;
    }

  

    int rootdata=preorder[prestart];
    int rootindex=-1;
     for(int i=instart;i <= inend;i++) {
        if (inorder[i] == rootdata) {
            rootindex=i;
            break;
        }
        
    }
    int inorderleftstart=instart;
    int inorderleftend = rootindex - 1;
    int preorderleftstart=prestart+1;
    int preorderleftend = inorderleftend-inorderleftstart+preorderleftstart;
    int inorderrightstart = rootindex + 1;
    int inorderrightend = inend;
    int preorderrightstart = preorderleftend + 1;
    int preorderrightend = preend;
   BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);
   root->left = buildtreedata(preorder, preorderleftstart, preorderleftend, inorder, inorderleftstart, inorderleftend);
   root->right = buildtreedata(preorder, preorderrightstart, preorderrightend, inorder, inorderrightstart, inorderrightend);

   return root;
 }

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
     return buildtreedata(preorder, 0, preLength - 1, inorder, 0, inLength - 1);
 }