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
pair<TreeNode<int>*, TreeNode<int>*> maxAndSecond(TreeNode<int>* root) {
    pair<TreeNode<int>*, TreeNode<int>*> result;
    result.first = root;
    result.second = NULL;
    for (int i = 0; i < root->children.size(); i++) {
        pair<TreeNode<int>*, TreeNode<int>*> childResult = maxAndSecond(root->children[i]);
        if (childResult.first->data > result.first->data) {
            result.second = result.first;
            result.first = childResult.first;
        } else if (childResult.first->data < result.first->data && result.second == NULL) {
            result.second = childResult.first;
        }
        if (childResult.second != NULL && (result.second == NULL || childResult.second->data > result.second->data)) {
            result.second = childResult.second;
        }
    }
    return result;
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    if (root == NULL) {
        return NULL;
    }
    pair<TreeNode<int>*, TreeNode<int>*> result = maxAndSecond(root);
    return result.second;
}
