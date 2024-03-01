#include<iostream>
#include<queue>
#include<climits>
using namespace std;
#include"BinaryTreeNode_2.h"
#include"BST.h"

class isBST{
public:
    int maxi;
    int mini;
    bool isbst;
    
    
};


BinaryTreeNode<int>* takeInput(){
    int data;
    cout<<"Enter the root data : ";
    cin>>data;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);
    queue<BinaryTreeNode<int> *> pending_nodes;
    pending_nodes.push(root);
    while(pending_nodes.size() != 0){
        BinaryTreeNode<int> * Front = pending_nodes.front();
        pending_nodes.pop();
        
        cout<<"Enter the left child data of " <<Front->data<<" : ";
        int left_data;
        cin>>left_data;
        if(left_data != -1){
            BinaryTreeNode<int>* left_child = new BinaryTreeNode<int>(left_data);
            Front->left = left_child;
            pending_nodes.push(left_child);
        }
        
        int right_data;
        cout<<"Enter the right child data of "<<Front->data<<" : ";
        cin>>right_data;
        if(right_data != -1){
        BinaryTreeNode<int>* right_child = new BinaryTreeNode<int>(right_data);
            Front->left = right_child;
            pending_nodes.push(right_child);
        }
    }
    return root;
}



//int maximum(BinaryTreeNode<int> * root){
//    if(root == NULL) return INT_MIN;
//    int maxLeft = maximum(root->left);
//    int maxRight = maximum(root->right);
//    return max(root->data,max(maxLeft,maxRight));
//}
//
//int minimum(BinaryTreeNode<int> * root){
//    if(root == NULL) return INT_MAX;
//    int miniLeft = minimum(root->left);
//    int miniRight = minimum(root->right);
//    return min(root->data,min(minLeft,minRight));
//}
//
//bool isBST(BinaryTreeNode<int> * root){
//    if(root == NULL) return true;
//
//    if(isBST(root->left)== true && isBST(root->right)==true && minimum(root->right)>root->data && maximum(root->left) < root->data){
//        return true;
//    else return false;
//
//
//
//}

isBST helper(BinaryTreeNode<int>* root){
    if(root == NULL){
        isBST b;
        b.isbst = true;
        b.maxi = INT_MIN;
        b.mini = INT_MAX;
        return b;
    }
    isBST b1 = helper(root->left);
    isBST b2 = helper(root->right);
    
    
    if(b1.isbst == true && b2.isbst == true && b1.maxi < root->data && b2.mini > root->data){
        isBST output;
        output.isbst = true;
        output.mini = min(b1.mini , b2.mini);
        output.maxi = max(b1.maxi , b2.maxi);
        return output;
    }
    else{
        isBST output;
        output.isbst = false;
        output.mini =  min(b1.mini,b2.mini);
        output.maxi = max(b1.maxi,b2.maxi);
        return output;
    }
}




bool isBST_better(BinaryTreeNode<int>* root){
    return helper(root).isbst;
}




int heightOfLargestBST(BinaryTreeNode<int> * root){
    return 0;
}
int main(){
    BinaryTreeNode<int>* root = takeInput();
    cout<<isBST_better(root)<<endl;
//    int ans = heightOfLargestBST(root);
//    return ans;
}



