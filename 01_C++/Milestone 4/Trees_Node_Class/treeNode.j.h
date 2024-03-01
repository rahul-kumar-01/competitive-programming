#include<vector>
using namespace std;
template <typename T>

class TreeNode{
public:
    T data;
    //Node <TreeNode*> children;
    //by default it assume if Node of T type is integer <T> is <int>
    //specify because my TreeNode class made of template
    
    
    vector <TreeNode <T> * > children;
    
    //vector is needed to store the address of children . The type is same as children
    // that is TreeNode
    
    TreeNode (T data){
        this->data = data;
    }
    
    ~TreeNode(){
        for(int i=0;i<children.size();++i){
            delete children[i];
        }
    }
};

