#include<iostream>
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

void minSumHelper(BinaryTreeNode<int>* root, int sum, int& result) {
    if (root == NULL) {
        return;
    }
    sum += root->data;

    if (root->left == NULL && root->right == NULL) {
        if (sum < result) {
            result = sum;
        }
    }

    minSumHelper(root->left, sum, result);
    minSumHelper(root->right, sum, result);
}

int minSum(BinaryTreeNode<int>* root) {
    int result = INT_MAX;
    minSumHelper(root, 0, result);
    return result;
}