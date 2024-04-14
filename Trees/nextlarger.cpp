#include<iostream>
#include <vector>
#include<queue>
#include<climits>
using namespace std;
template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*>children;
    TreeNode(T data){
        this->data=data;
    }

};
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
TreeNode<int>*nextlarger(TreeNode<int>*root,int n){
    if(root==NULL){
        return NULL;
    }
    int nextdata=INT_MAX;
    TreeNode<int>* nextnode=NULL;
    if(root->data>n&&root->data<nextdata){
        nextdata=root->data;
        nextnode=root;
    }
    for(int i =0;i<root->children.size();i++){
        TreeNode<int>*childnode=nextlarger(root->children[i], n);
        if(childnode!=NULL){
        int childdata=childnode->data;
        if(childdata<nextdata&&childdata>n){
            nextdata=childdata;
            nextnode=childnode;
        }
    }
    }
    return nextnode;

}
int main(){
    TreeNode<int>*root=takeinputlevelwise();
    int x;
    cout<<"enter the number"<<endl;
    cin>>x;
    TreeNode<int>*node=nextlarger(root, x);
    cout<<node->data<<endl;
}