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
void printtreelevelwise(TreeNode<int>*root){
    queue<TreeNode<int>*>pendingnodes;
    pendingnodes.push(root);
    while(!pendingnodes.empty()){
        TreeNode<int>*front=pendingnodes.front();
        pendingnodes.pop();
        cout<<front->data<<":"<<endl;
        for(int i =0;i<front->children.size();i++){
            cout << front->children[i]->data;
            pendingnodes.push(front->children[i]);

            if (i < front->children.size() - 1) {
                cout << ",";
            }
        }
        cout<<endl;
    }
}
void replacedepth(TreeNode<int>*root,int depth){
    if(root==NULL)
    {
        return ;
    }
    root->data=depth;
    for(int i =0;i<root->children.size();i++){
        replacedepth(root->children[i],depth+1);
    }

}
void replacedepthvalue(TreeNode<int>*root){
     replacedepth(root,0);
}
int main(){
    TreeNode<int>*root=takeinputlevelwise();
    replacedepthvalue(root);
    printtreelevelwise(root);



}