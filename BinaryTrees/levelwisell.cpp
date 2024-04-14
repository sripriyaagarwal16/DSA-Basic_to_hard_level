#include<iostream>
#include<queue>
#include<algorithm>
#include<climits>
#include<vector>
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
class Node{
    public:
    T data;
    Node<T>*next;
    Node(T data){
        this->data=data;
        next=NULL;
    }
}
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

vector<Node<int>>*linkedlistlevelwise(BinaryTreeNode<int>*root){
    if(root==NULL){
        return NULL;
    }
    vector<Node<int>>*result;
    queue<BinaryTreeNode<int>>*p;
   
    p.push(root);
    while(!p.empty()){
        levelsize=p.size();
        Node<int>*levelhead=NULL;
        Node<int>*leveltail=NULL;
        for(int i =0;i<levelsize;i++){
            BinaryTreeNode<int>*front=p.front();
            p.pop();
            Node<int>*newnode=new Node(front->data);
            if(leveltail==NULL){
                leveltail=newnode;
                levelhead=newnode;
            }else{
                leveltail->next=newnode;
                leveltail=newnode;
            }
            if(front-left!=NULL){
                p.push(front->left);
            }
            if(front->right!=NULL){
                p.push(front->right);

            }
        }
        result.push_back(levelhead);
    }
   return result;
}
int main(){
   BinaryTreeNode<int>*root=takeinputlevelwise();
   vector< Node<int>>*result=linkedlistlevelwise(root);
   for(int i=0;i<result.size();i++){
    for(int j=0;j<result.size();j++){
     cout<<"the level"<<i<<"is"<<" "<<result[i][j]<<endl;
    }
   }
}