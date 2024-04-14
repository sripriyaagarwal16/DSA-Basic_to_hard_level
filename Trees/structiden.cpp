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
bool identical(TreeNode<int>*root1,TreeNode<int>*root2){
    if(root1==NULL||root2==NULL){
        return false;
    }
    if(root1==NULL&&root2==NULL){
        return true;
    }
    bool iden=true;
    if(root1->data==root2->data&&root1->children.size()==root2->children.size()){
        for(int i =0;i<root1->children.size();i++){
            iden=identical(root1->children[i],root2->children[i]);
        }
    }else{
        return false;
    }
    return iden;
}
int main(){
    TreeNode<int>*root1=takeinputlevelwise();
    TreeNode<int>*root2=takeinputlevelwise();
    bool iden=identical(root1,root2);
    cout<<iden<<endl;
}