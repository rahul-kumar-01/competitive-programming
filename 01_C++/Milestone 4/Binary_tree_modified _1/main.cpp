#include<iostream>
using namespace std;
#include"BinaryTree.h"

BinaryTree<int>* takeInput(){
    int data;
    cout<<"enter the data : ";
    cin>>data;
    if(data == -1) return NULL;
    BinaryTree<int>* root = new BinaryTree<int> (data);
    BinaryTree<int>* Left_child = takeInput();
    BinaryTree<int>* Right_child = takeInput();
    root->LeftNode = Left_child;
    root->RightNode = Right_child;
    return root;
}
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
    BinaryTree<int> * root = takeInput();
    print_BinaryTree(root);
}
