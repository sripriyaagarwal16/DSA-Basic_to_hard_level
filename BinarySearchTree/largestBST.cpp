#include<climits>

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
class solution{
	public:
	int minimum ;
	int maximum ;
	int height; 
	bool isBST;
};
solution largestBSTSubtreehelper(BinaryTreeNode<int> *root) {
    // Write your code here
	if(root==NULL){
		solution output;
		output.minimum=INT_MAX;
		output.maximum=INT_MIN;
		output.height=0;
		output.isBST=true;
		return output;
	}
	
   solution lefttree= largestBSTSubtreehelper(root->left);
   solution righttree= largestBSTSubtreehelper(root->right);
   solution output;
   output.minimum=min(root->data,min(lefttree.minimum,righttree.minimum));
   output.maximum=max(root->data,max(lefttree.maximum,righttree.maximum));
   if(root->data>lefttree.maximum&&root->data<=righttree.minimum&&lefttree.isBST&&righttree.isBST){
	   output.isBST=true;
	   output.height=max(lefttree.height,righttree.height)+1;
   }else{
	   output.isBST=false;
	   output.height=max(lefttree.height,righttree.height);
   }
   return output;
}
int largestBSTSubtree(BinaryTreeNode<int> *root){
	solution answer=largestBSTSubtreehelper(root);
	return answer.height;
}

