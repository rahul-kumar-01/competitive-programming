#include<iostream>
#include<queue>
#include"treeNode.j.h"
using namespace std;


//RECURSION call is not necessary because if root has no children there is no recursive call further but if some one give root == NULL it show compiler error at 1 line so to deal with edge case we have to write root == null return ; but it is not recursion call its edge case

void printTreeLevelWise(TreeNode<int> * root){
    queue <TreeNode<int> * > pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode <int> * Front = pendingNodes.front();
        pendingNodes.pop();
        
        cout<<Front->data<<" : ";
        int i=0;
        for(i=0;i<Front->children.size();++i){
            cout<<Front->children[i]->data <<" , ";
            pendingNodes.push(Front->children[i]);
        }
        cout<<endl;
    }
}
void printTree(TreeNode <int> * root){
    if(root == NULL) return ;
    cout<<root->data<<" : ";
    
    for(int i=0;i<root->children.size();++i){
        cout<<root->children[i]->data<<" , ";
    }
    cout<<endl;
    
    for(int i=0;i<root->children.size();++i){
        printTree(root->children[i]);
    }
}
TreeNode <int> * takeInputLevelWise(){
    int rootData;
    cout<<"Enter the root data : ";
    cin>>rootData;
    TreeNode <int> * root = new TreeNode <int> (rootData);
    
    queue <TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode <int> * Front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout<<"Enter the no of child of "<<Front->data <<" : ";
        cin>>numChild;
        for(int i=0;i<numChild;++i){
            int childData;
            cout<<"Enter the "<<i+1<<" th child of "<<Front->data<<" ";
            cin>>childData;
            TreeNode <int> * child = new TreeNode <int> (childData);
            pendingNodes.push(child);
            Front->children.push_back(child);
        }
    }
    return root;
}
TreeNode<int> * takeInput(){
    int rootData;
    cout<<"Enter the data : ";
    cin>> rootData;
    TreeNode <int> * root = new TreeNode <int> (rootData);
    int noOfChildren;
    cout<<"Enter the no of children of "<<rootData<<" : ";
    cin>> noOfChildren;
    for(int i=0;i<noOfChildren;++i){
        TreeNode <int> * child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

//PREORDER : first root tell print me first then my children
void preorder(TreeNode<int> * root){
    if(root==NULL) return ;     //special case
    cout<<root->data<<" ";
    for (int i=0;i<root->children.size();++i){
        preorder(root->children[i]);
    }
}

//POSTORDER : root tell first print my children then me
void postorder(TreeNode<int> * root){
    for(int i=0;i<root->children.size();++i){
        postorder(root->children[i]);
    }
    cout<<" : "<<root->data<<endl;
}


//first we have to delete children then root
void deleteTree(TreeNode<int>* root){
    for(int i=0;i<root->children.size();++i){
        deleteTree(root->children[i]);
    }
    delete root;
}

//sum of nodes :
int sumOfNodes(TreeNode<int>* root) {
    // Write your code here
    int sum = root->data;
    for(int i=0;i<root->children.size();++i){
        sum += sumOfNodes(root->children[i]);
    }
    return sum;
}


//Return node which has max data
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
    if(root == NULL) return NULL;
    int max = root->data;
    TreeNode <int> * temp = root;
    long no_of_children = root->children.size();

    for(int i=0;i<no_of_children;++i){
        TreeNode <int> * result =  maxDataNode(root->children[i]);
        if(result->data > max){
            max = result->data;
            temp = result;
        }

    }


    return temp;
}

//height of Tree :
int getHeight(TreeNode<int>* root) {
    int height = 1;
    for(int i=0;i<root->children.size();++i){
        int result = getHeight(root->children[i]);
        if(result>height){
            height = result;
        }
    }
    if(root->children.size()==0) return height;
    return height+1;
}

//count leaf Nodes : nodes have no children
int getLeafNodeCount(TreeNode<int>* root) {
    if(root->children.size() == 0) return 1;
    int ans = 0;
    for(int i=0;i<root->children.size();++i){
         ans += getLeafNodeCount(root->children[i]);
    }
    return ans ;
}

int main(){
    
    
//    TreeNode <int> * root = new TreeNode <int> (1);
//    TreeNode <int> * node1 = new TreeNode <int> (2);
//    TreeNode <int> * node2 = new TreeNode <int> (3);
//
//    root->children.push_back(node1);
//    root->children.push_back(node2);
    TreeNode<int> * root = takeInputLevelWise();
    printTreeLevelWise(root);
    
    
    
    
    
    printTreeLevelWise(root);
    
    //when we call delete keyword
    //destructor called of that object
}
