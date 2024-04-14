#include<iostream>
#include <vector>
#include<queue>
#include<algorithm>
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
TreeNode<int>* maxdata(TreeNode<int>*root){
    if(root==NULL){
        return root;
    }
    TreeNode<int>* maxNode=root;
   
    for(int i =0;i<root->children.size();i++){
         TreeNode<int>* childMax = maxdata(root->children[i]);

         if (childMax != nullptr && childMax->data > maxNode->data) {
           maxNode = childMax;
         }
         
    }
          return maxNode;


}
int main(){
    TreeNode<int>*root=takeinputlevelwise();
    TreeNode<int>*maxnode=maxdata(root);
    cout<<"the maxdata is"<<" "<<maxnode->data<<endl; 
}
