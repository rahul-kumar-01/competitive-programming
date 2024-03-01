#include<iostream>
#include<queue>
#include<stack>
using namespace std;
#include"BinaryTree.h"

BinaryTree<int>* takeInput(){
    int data;
    cout<<"Enter the root data : ";
    cin>>data;
    BinaryTree<int>* root = new BinaryTree<int>(data);
    queue<BinaryTree<int> *> pending_nodes;
    pending_nodes.push(root);
    while(pending_nodes.size() != 0){
        BinaryTree<int> * Front = pending_nodes.front();
        pending_nodes.pop();
        
        cout<<"Enter the left child data of " <<Front->data<<" : ";
        int left_data;
        cin>>left_data;
        if(left_data != -1){
            BinaryTree<int>* left_child = new BinaryTree<int>(left_data);
            Front->LeftNode = left_child;
            pending_nodes.push(left_child);
        }
        
        int right_data;
        cout<<"Enter the right child data of "<<Front->data<<" : ";
        cin>>right_data;
        if(right_data != -1){
            BinaryTree<int>* right_child = new BinaryTree<int>(right_data);
            Front->RightNode = right_child;
            pending_nodes.push(right_child);
        }
    }
    return root;
}

void print_binary_tree_level_wise(BinaryTree<int> * root){
    
    queue<BinaryTree<int> * > pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTree<int> * Front = pendingNodes.front();
        pendingNodes.pop();
        cout<<Front->data<<" : ";
        if(Front->LeftNode != NULL){
            cout<<" L : "<<Front->LeftNode->data;
            pendingNodes.push(Front->LeftNode);
        }
        if(Front->RightNode != NULL){
            cout<<" R : "<<Front->RightNode->data;
            pendingNodes.push(Front->RightNode);
        }
        cout<<endl;
    }
}

int countNodes(BinaryTree<int>* root){
    if(root==NULL) return 0;
    int ans1 = countNodes(root->LeftNode);
    int ans2 = countNodes(root->RightNode);
    return ans1 + ans2 + 1;
}

//first left child then root then right child

void print_in_order(BinaryTree<int>* root){
    if(root == NULL) return;
    print_in_order(root->LeftNode);
    cout<<root->data<<" ";
    print_in_order(root->RightNode);
}
void print_pre_order(BinaryTree<int>* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    print_pre_order(root->LeftNode);
    print_pre_order(root->RightNode);
}

void print_post_order(BinaryTree<int> * root){
    if(root == NULL) return;
    print_post_order(root->LeftNode);
    print_post_order(root->RightNode);
    cout<<root->data<<" ";
}


int height(BinaryTree<int> * root){
    if(root == NULL) return 0;
    int left_node_height = height(root->LeftNode);
    int right_node_height = height(root->RightNode);
    return 1+ max(left_node_height , right_node_height);
}

int diameter(BinaryTree<int> * root){
    if(root == NULL) return 0;
    int option1 = height(root->RightNode) + height(root->LeftNode);
    int option2 = diameter(root->LeftNode);
    int option3 = diameter(root->RightNode);
    return max(option1 ,max(option2,option3));
    
}

pair<int, int> heightDiameter (BinaryTree<int> * root){
    if(root == NULL){
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int,int> leftAns = heightDiameter(root->LeftNode);
    pair<int,int> rightAns = heightDiameter(root->RightNode);
    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;
    
    int height = 1 + max(lh,rh);
    int diameter = max(lh+rh , max(ld,rd));
    pair<int,int> p;
    p.first = height;
    p.second = diameter;
    return p;
}
    
void print_b(BinaryTree<int> * root){
    cout<<root->data<<endl;
    queue<BinaryTree<int> * > pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTree<int> * Front = pendingNodes.front();
        pendingNodes.pop();
        cout<<Front->data<<" : ";
        if(Front->LeftNode != NULL){
            cout<<" L : "<<Front->LeftNode->data;
            pendingNodes.push(Front->LeftNode);
        }
        if(Front->RightNode != NULL){
            cout<<" R : "<<Front->RightNode->data;
            pendingNodes.push(Front->RightNode);
        }
        cout<<endl;
    }
}

class Pair{
public:
    bool found;
    BinaryTree<int>* foundNode;
    Pair(){
        found = false;
        foundNode = NULL;
    }
};

BinaryTree<int>* isThere(BinaryTree<int>* root ,int a){
    if(root == NULL){
        return NULL;
    }
    if(root->data == a) {
        return root;
    }
    BinaryTree<int>* ans1 = isThere(root->LeftNode, a);
    BinaryTree<int>* ans2 = isThere(root->RightNode, a);
    if(ans1 == NULL) return ans2;
    return ans1;
}

BinaryTree<int>* makeArray(int n){
    int a = 0;
    int b =0;
    BinaryTree<int>* root = NULL;
    
    for(int i=0;i<n;++i){
        cin>>a>>b;
        if(root == NULL){
            root = new BinaryTree<int>(a);
            root->LeftNode = new BinaryTree<int> (b);
            continue;
        }
        
        BinaryTree<int>* tempNode = isThere(root,a);
        
        if(tempNode->LeftNode == NULL){
            tempNode->LeftNode = new BinaryTree<int> (b);
        }
        else{
            tempNode->RightNode = new BinaryTree<int>(b);
        }
        
        
    }
    return root;
}


int main(){
    
//    BinaryTree<int> * root = takeInput();
//    print_binary_tree_level_wise(root);
//
//        cout<<"No. of nodes : "<<countNodes(root)<<endl;
//
//    print_pre_order(root);
//    cout<<endl;
//    print_post_order(root);
//    cout<<endl;
//    print_in_order(root);
//    cout<<endl;
//
//    cout<<"Diamter of Tree Node : "<<diameter(root)<<endl;
//    cout<<"Height of Tree Node : "<<height(root)<<endl;
//
    
    int n;
    cin>>n;
    BinaryTree<int>* root =  makeArray(n);
    print_binary_tree_level_wise(root);
//    BinaryTree<int>* root = takeInput();
//    print_binary_tree_level_wise(root);
//    cout<<isThere(root, 3)<<endl;
}
