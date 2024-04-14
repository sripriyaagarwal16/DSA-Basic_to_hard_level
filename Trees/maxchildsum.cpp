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
int subtreesum(TreeNode<int>*root){
    int sum=root->data;
    for(int i =0;i<root->children.size();i++){
        sum+=root->children[i]->data;
    }
    return sum;
}
TreeNode<int>*maxchildsum(TreeNode<int>*root){
    if(root==NULL){
        return NULL;
    }
    int maxroot=subtreesum(root);
    TreeNode<int>*maxnode=root;
    for(int i =0;i<root->children.size();i++){
        TreeNode<int>*child=maxchildsum(root->children[i]);
        int childmax=subtreesum(child);
        if(maxroot<childmax){
            maxroot=childmax;
            maxnode=child;
            
        }

    }
    return maxnode;
}
int main(){
    TreeNode<int>*root=takeinputlevelwise();
    TreeNode<int>*maxnode=maxchildsum(root);
    cout<<"the maxchildsum of the tree is :"<<maxnode->data<<endl;
}