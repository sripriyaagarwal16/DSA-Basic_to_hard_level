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
    if(root->data==data){
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
template <typename T>
class Node {
public:
    T data;
    Node<T> *next;
    Node<T> *prev;
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class listinfo {
public:
    Node<int> *head;
    Node<int> *tail;
};

listinfo *constructSortedLinkedList(BinaryTreeNode<int> *root) {
    listinfo *LL = new listinfo;
    if (root == NULL) {
        LL->head = NULL;
        LL->tail = NULL;
        return LL;
    }

    listinfo *leftInfo = constructSortedLinkedList(root->left);
    Node<int> *newNode = new Node<int>(root->data);
    listinfo *rightInfo = constructSortedLinkedList(root->right);

    if (leftInfo->tail != NULL) {
        leftInfo->tail->next = newNode;
        newNode->prev = leftInfo->tail;
    }

    if (rightInfo->head != NULL) {
        rightInfo->head->prev = newNode;
    }

    newNode->next = rightInfo->head;
    LL->head = (leftInfo->head != NULL) ? leftInfo->head : newNode;
    LL->tail = (rightInfo->tail != NULL) ? rightInfo->tail : newNode;

    delete leftInfo;  // Free memory
    delete rightInfo; // Free memory

    return LL;
}




void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    if(root==NULL){
        return ;
    }
    listinfo *LL = constructSortedLinkedList(root);
    // hello
   
    while (LL->head != NULL && LL->tail != NULL&&LL->head != LL->tail) {
        if ((LL->head->data + LL->tail->data) > s) {
            LL->tail = LL->tail->prev;
        } else if ((LL->head->data + LL->tail->data) < s) {
            LL->head = LL->head->next;
        } else if ((LL->head->data + LL->tail->data) == s) {
            if (LL->head->data <LL-> tail->data) {
              cout << LL->head->data << " " << LL->tail->data << endl;
            }
            LL->head = LL->head->next;
            LL->tail = LL->tail->prev;
        }
    }

    delete LL; 
}



