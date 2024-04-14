#include<iostream>
#include <vector>
#include<queue>
using namespace std;
template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*>children;
    //constructor
    TreeNode(T data){
        this->data=data;
    }
    //destructor
    ~TreeNode(){
        for(int i =0;i<children.size();i++){
            delete children[i];
        }
    }


};
//taking input from users 
TreeNode<int>*Takeinput(){
    int rootdata;
    cout<<"Enter data"<<endl; 
    cin>>rootdata;
    TreeNode<int>* root= new TreeNode<int>(rootdata);
    int n ;
    cout<<"enter the number of children you want"<<endl ;
    cin>>n; 
    for(int i =0;i<n;i++){
        TreeNode<int>* child=Takeinput();
        root->children.push_back(child);
    }
    return root;
}
//taking input level wise 
TreeNode<int>*takeinputlevelwise(){
    int rootdata;
    cout<<"Enter the data"<<endl;
    cin>>rootdata;
    TreeNode<int>*root= new TreeNode<int>(rootdata);
    queue<TreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int>*front=pendingNodes.front();
        pendingNodes.pop();
        int n;
        cout<<"enter the number of childs"<<endl;
        cin>>n;
        for(int i =0;i<n;i++){
            int childdata;
            cout<<"enter"<<i<<" "<<"th"<<" "<<"child of the "<<front->data<<endl;
            cin>>childdata;
            TreeNode<int>*child=new TreeNode<int>(childdata);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root; 

}
//recursive print 
//preorder traversal 
void printtree(TreeNode<int>*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":"<<endl;
    for(int i =0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i =0;i<root->children.size();i++){
        printtree(root->children[i]);
    }

}
//destructor
void deleteTree(TreeNode<int>*root){
    for(int i =0;i<root->children.size();i++){
        deleteTree(root->children[i]);
    }
    delete root;
}
int main(){
   TreeNode <int>*root=takeinputlevelwise();
   printtree(root);
   delete root;



}