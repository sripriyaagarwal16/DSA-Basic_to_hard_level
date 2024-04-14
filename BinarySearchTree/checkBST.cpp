#include<iostream>
#include<queue>
#include<climits>
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
class IsBSTReturn{
    public:
    int mininmum;
    int maximum;
    bool isBST;
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

int minimum(BinaryTreeNode<int> *root){
	if(root==NULL){
		return INT_MAX;
	}
	return min(root->data,min(minimum(root->left),minimum(root->right)));
}
int maximum(BinaryTreeNode<int> *root){
	if(root==NULL){
		return INT_MIN;
	}
	return max(root->data,max(maximum(root->left),maximum(root->right)));
}

bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
	if(root==NULL){
		return true;
	}
	int leftmax=maximum(root->left);
	int rightmin=minimum(root->right);
	bool output=(root->data>leftmax)&&(root->data<=rightmin)&&isBST(root->left)&&isBST(root->right);
	return output;
	
}
//check BST2
bool checkBST2(BinaryTreeNode<int>*root){
    if(root==NULL){
        IsBSTReturn output;
        output.maximum=INT_MIN;
        output.minimum=INT_MAX;
        output.isBST=true;
        return output;
    }
    bool leftBST=checkBST2(root->left);
    bool righttBST=checkBST2(root->right);
    int maximum=max(root->data,max(rightBST.maximum,leftBST.maximum));
    int minimum=min(root->data,min(rightBST.minimum,leftBST.minimum));
    bool ISBst=(root->data>leftBST.maximum)&&(root->data<=rightBST.minimum)&&leftBST.isBST&&rightBST.isBST;
    IsBSTReturn output;
    output.maximum=maximum;
    output.minimum=minimum;
    output.isBST=ISBst;
    return output;

}
//Check BST3
bool checkBST3(BinaryTreeNode<int>*root,int min =INT_MIN,int max=INT_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data<min||root->data>max){
        return false;
    }
    bool isleftOK= checkBST3(root->left,min,root->data-1);
    bool isrightOK= checkBST3(root->right,root->data,max);
    return isleftOK&&isrightOK;

}