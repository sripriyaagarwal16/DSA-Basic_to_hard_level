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
int numnodes(TreeNode<int>*root,int x ){
    if(root==NULL){
        return 0;
    }
    int total_count=0;
    if(root->data>x){
        total_count=1;
    }
     int child_count=0;
    for(int i =0;i<root->children.size();i++){
         child_count=numnodes(root->children[i],x);

    }
    return total_count+child_count;
}
int main(){
    TreeNode<int>*root=takeinputlevelwise();
    int x ;
    cout<<"Enter the number you want to the greater node of "<<endl;
    cin>>x;
    

    int total_count=numnodes(root,x);
    cout<< "the total number of nodes greater than "<<x<<"is: "<<total_count<<endl;
}
