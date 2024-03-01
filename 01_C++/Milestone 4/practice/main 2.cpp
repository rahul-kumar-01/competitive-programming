#include<iostream>
#include<queue>
using namespace std;
template<typename T>
class BinaryTree{
public:
    T data;
    BinaryTree<T> * left;
    BinaryTree<T> * right;
public:
    BinaryTree(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
    
};

void printInput(BinaryTree<int> * root){
    
    cout<<"root data is : "<<root->data<<endl;
    queue <BinaryTree <int> * > pendingNodes ;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTree<int> * front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<" ";
        if(front->left != NULL){
            cout<<" L"<<" : "<<front->left->data;
            pendingNodes.push(front->left);
        }
        if(front->right != NULL){
            cout<<" R" <<" : "<<front->right->data;
            pendingNodes.push(front->right);
        }
        cout<<endl;
        
        
    }
}

BinaryTree<int> *  take_input_level_wise(){
    int n;
    cout<<"enter the root data : ";
    cin>>n;
    BinaryTree<int> * root = new BinaryTree<int>(n);
    queue<BinaryTree <int>* > pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTree <int> * front = pendingNodes.front();
        pendingNodes.pop();
        int leftchild;
        cout<<"enter the left child of "<<front->data<<" : " ;
        cin>>leftchild;
        if(leftchild != -1){
            BinaryTree<int> * left1 = new BinaryTree<int> (leftchild);
            front->left = left1;
            pendingNodes.push(left1);
        }
        
        int rightchild;
        cout<<"enter the right child of "<<front->data<<" : ";
        cin>>rightchild;
        if(rightchild != -1){
            BinaryTree<int> * right1 = new BinaryTree <int> (rightchild);
            front->right = right1;
            pendingNodes.push(right1);
        }
     
    }
    return root;
}
    

//void print_BinaryTree_level_wise(BinaryTree<int>* root){
//    }
    
int main(){
    BinaryTree<int> * d = take_input_level_wise();
    printInput(d);
    
}
