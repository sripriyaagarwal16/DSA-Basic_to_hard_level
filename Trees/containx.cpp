#include<iostream>
#include <vector>
#include<queue>
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
bool containsx(TreeNode<int>*root,int x){
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    for(int i =0;i<root->children.size();i++){
        bool childfound=containsx(root->children[i],x);
        if(childfound){
            return true;
        }
    }
    return false;
}
int main(){
    TreeNode<int>*root=takeinputlevelwise();
    int x ; 
    cout<<"enter the number you want in the tree"<<endl;
    cin>>x;
    bool found=containsx(root,x);
    cout<<found<<endl;
}
