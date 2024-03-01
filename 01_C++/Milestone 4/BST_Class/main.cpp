#include<iostream>
#include"BinaryTreeNode.h"
#include"Header.h"
#include<queue>
using namespace std;
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
            Front->right = right_child;
            pending_nodes.push(right_child);
        }
    }
    return root;
}

void print_binary_tree_level_wise(BinaryTreeNode<int> * root){
    
    queue<BinaryTreeNode<int> * > pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int> * Front = pendingNodes.front();
        pendingNodes.pop();
        cout<<Front->data<<" : ";
        if(Front->left != NULL){
            cout<<" L : "<<Front->left->data;
            pendingNodes.push(Front->left);
        }
        if(Front->right != NULL){
            cout<<" R : "<<Front->right->data;
            pendingNodes.push(Front->right);
        }
        cout<<endl;
    }
    }
int main(){
    BST b1;
    b1.insert(5);
    b1.insert(6);
    b1.insert(9);
    b1.insert(7);
    b1.insert(8);
    
    print_binary_tree_level_wise(b1.node);
}

