#include<iostream>
#include<queue>
#include<utility>
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
class BST{
   BinaryTreeNode<int>*root;
   public:
   BST(){
    root=NULL;
   }
   ~BST(){
    delete root;
   }
   private:
   bool hasdata(int data,BinaryTreeNode<int>*node){
    if(node==NULL){
        return false;
    }
    if(node->data==data){
        return true;
    }
    bool leftfound=hasdata( data,node->left);
    if(leftfound){
        return true;
    }else{
        bool rightfound=hasdata( data,node->right);
        return rightfound;
    }
   }
    BinaryTreeNode<int>*insert(int data,BinaryTreeNode<int>*node){
        if(node==NULL){
            BinaryTreeNode<int>*newnode=new BinaryTreeNode<int>(data);
            return newnode;
        }
        if(data<node->data){
           node->left=insert( data,node->left);
        }
        else{
            node->right=insert(data,node->right);
        }
        return node;

    
   }
   BinaryTreeNode<int>* remove(int data, BinaryTreeNode<int>* node) {
        if (node == NULL) {
            return NULL;
        }

        if (data < node->data) {
            node->left = remove(data, node->left);
        } else if (data > node->data) {
            node->right = remove(data, node->right);
        } else {
            if (node->right == NULL && node->left == NULL) {
                // Case 1: Node has no children
                delete node;
                return NULL;
            } else if (node->right == NULL) {
                // Case 2: Node has only left child
                BinaryTreeNode<int>* temp = node->left;
                delete node;
                return temp;
            } else if (node->left == NULL) {
                // Case 3: Node has only right child
                BinaryTreeNode<int>* temp = node->right;
                delete node;
                return temp;
            } else {
                // Case 4: Node has both left and right children
                BinaryTreeNode<int>* minNode = node->right;
                while (minNode->left != NULL) {
                    minNode = minNode->left;
                }
                node->data = minNode->data;
                node->right = remove(minNode->data, node->right);
                return node;
            }
        }
        return node;
    }

   public:
   bool hasdata(int data){
      return hasdata(data,this->root);
   }
   BinaryTreeNode<int>*insert(int data){
     return insert(data,this->root);
   }
   BinaryTreeNode<int>*deletedata(int data){
      return remove(data,this->root);

   }


};

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
BinaryTreeNode<int>* hasdata(int data,BinaryTreeNode<int>*root){
    if(root==NULL){
        return NULL;
    }
    if(root->data==data){
        return root;
    }
    BinaryTreeNode<int>*leftfound =hasdata( data,root->left);
    if(leftfound){
        return leftfound;
    }else{
        BinaryTreeNode<int>*rightfound=hasdata( data,root->right);
        return rightfound;
    }
   }
void pairsum(BinaryTreeNode<int>*root,int S, vector<pair<int,int>>sumpair){
    if(root==NULL){
        return ;
    }
   
    int complement=S- root->data;
    BinaryTreeNode<int>*temp= hasdata( complement,root);
    if(temp!=NULL){
       sumpair.push_back(make_pair(root->data, complement));
    }
    pairsum(root->left, S,sumpair);
    pairsum(root->right, S,sumpair);
     

}
void printPairsWithFirstLessThanSecond(const vector<pair<int, int>>& sumpair) {
    for (const auto& p : sumpair) {
        if (p.first < p.second) {
            cout << "(" << p.first << ", " << p.second << ")" << endl;
        }
    }
}
void Pair(BinaryTreeNode<int>*root,int S){
     vector<pair<int,int>>sumpair;
     pairsum(root,S,sumpair);
     printPairsWithFirstLessThanSecond( sumpair);
}
int main(){
    BinaryTreeNode<int>*root=takeinputlevelwise();
    int s;
    cout<<"the sum you want to find"<<endl;
    cin>>s;
    Pair(root,s);
   
}