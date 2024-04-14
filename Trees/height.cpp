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
int height(TreeNode<int>*root){
    int h =0; 
    for(int i =0;i<root->children.size();i++){
        int childheight= height(root->children[i]);
        if(childheight>h){
            h=childheight;
        }

    }
    return h+1;
}
int main(){
    TreeNode<int>*root=takeinputlevelwise();
    int h=height(root);
    cout<<"the height of the tree is "<<h<<endl;
}