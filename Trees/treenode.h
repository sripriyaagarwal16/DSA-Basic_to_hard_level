#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class TreeNode{
    T data;
    vector<TreeNode<T>*>children;
    public:
    TreeNode(T data){
        this->data=data;
    }

};