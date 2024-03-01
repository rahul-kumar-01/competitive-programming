#include<iostream>
using namespace std;
#include"BinaryTree.h"

void print_BinaryTree(BinaryTree<int>* root){
    if(root == NULL) return;
    cout<<root->data;
    
    if(root->LeftNode != NULL){
        cout<<" : L -> "<<root->LeftNode->data;
    }
    if(root->RightNode != NULL){
        cout<<" : R -> "<<root->RightNode->data;
    }
    cout<<endl;
    print_BinaryTree(root->LeftNode);
    print_BinaryTree(root->RightNode);
    return;
}




int main(){
    BinaryTree<int> * root = new BinaryTree<int>(5);
    BinaryTree<int> * left_child = new BinaryTree<int>(10);
    BinaryTree<int> * right_child = new BinaryTree<int>(20);
    BinaryTree<int> * right_child2 = new BinaryTree<int>(40);
    root->LeftNode = left_child;
    root->RightNode = right_child;
    right_child->LeftNode = right_child2;
    print_BinaryTree(root);
//    cout<<"No. of nodes : "<<countNodes(root)<<endl;
    //int ans = countNodes(root);
   // cout<<"No. of nodes : "<<countNodes(root)<<endl;
    cout<<"hello world"<<endl;
    
    
    
}
