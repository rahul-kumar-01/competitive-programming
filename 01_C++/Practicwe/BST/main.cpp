#include<iostream>
using namespace std;
#include"BinaryTreeNode.h"

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

void print(Node* head){
    if(head == NULL) return;
    Node * temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

class bst{
public:
    int min;
    int max;
    bool isbst;
    bst(){
        min =  INT_MAX; max = INT_MIN;  isbst = true;
    }
};

pair<Node*, Node*> bstToLL(BinaryTreeNode* root){
    if(root == NULL){
        pair<Node*, Node*> p;
        p.first = NULL;
        p.second = NULL;
        return p;
    }
    
    Node* newNode = new Node(root->data);
    
    pair<Node*, Node*> ans1 = bstToLL(root->leftNode);
    pair<Node*, Node*> ans2 = bstToLL(root->rightNode);
    
    pair<Node*, Node*> output;
    
    
    if(ans1.first == NULL && ans2.first != NULL){
        newNode -> next = ans2.first;
        ans2.second->next = NULL;
        output.first = newNode;
        output.second = ans2.second;
    }
    else if(ans1.first != NULL && ans2.first == NULL){
        output.first = ans1.first;
        ans1.second = newNode;
        newNode->next = NULL;
        output.second = newNode;
    }
    else if(ans1.first == NULL && ans2.second == NULL){
        output.first = newNode;
        output.second = newNode;
        newNode->next = NULL;
    }
    else{
        output.first = ans1.first;
        ans1.second ->next = newNode;
        newNode->next = ans2.first;
        ans2.second->next= NULL;
        output.second = ans2.second;
    }
    return output;
}



bool isBST_3(BinaryTreeNode* root,int min,int max){
    if(root == NULL) return true;
    bool ans1 = false;
    bool ans2 = false;
    if(root->data > min && root->data < max){
        ans1 = isBST_3(root->leftNode,min,root->data);
        ans2 = isBST_3(root->rightNode,root->data,max);
    }
    return ans1 && ans2;
}
                                   



bst isBST_2(BinaryTreeNode* root){
    if(root == NULL){
        bst b;
        return b;
    }
    bst b1 = isBST_2(root->leftNode);
    bst b2 = isBST_2(root->rightNode);
    
    int leftMax = b1.max;
    int rightMin = b2.min;
    bool ans = true;
    if(leftMax < root->data && rightMin > root->data){
        ans =  b1.isbst && b2.isbst;
    }
    else{
        ans = false;
    }
    bst output;
    output.min = min(root->data,min(b1.min , b2.min));
    output.max = max(root->data ,max(b1.max,b2.max));
    output.isbst = ans;
    return output;
}


bool isBST(BinaryTreeNode* root){
    if(root == NULL) return true;
    if(maxData(root->leftNode) < root->data && minData(root->rightNode) > root->data){
        return isBST(root->leftNode) && isBST(root->rightNode) ;
    }
    else return false;
}
int main(){
    BinaryTreeNode * root = takeInputLevelWise();
//    cout<<minData(root)<<endl;
//    cout<<maxData(root)<<endl;
//    cout<<isBST(root)<<endl;
//    cout<<isBST_2(root).isbst<<endl;
//    int min = 0;
//    int max = INT_MAX;
//    cout<<isBST_3(root,min,max)<<endl;
    Node* head = bstToLL(root).first;
    print(head);
}
