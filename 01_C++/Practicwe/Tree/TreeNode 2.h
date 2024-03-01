#include<vector>
#include<iostream>

class TreeNode{
public:
    int data;
    vector<TreeNode*> children;


    TreeNode(int data){
        this->data = data;
    }
    
};
