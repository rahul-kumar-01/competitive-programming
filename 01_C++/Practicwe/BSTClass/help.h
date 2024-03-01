class BinaryTreeNode{
public:
    int data;
    BinaryTreeNode * leftNode;
    BinaryTreeNode * rightNode;
    
    BinaryTreeNode(int data){
        this->data = data;
        leftNode = NULL;
        rightNode = NULL;
    }
};

class BST{
    BinaryTreeNode* root ;
public:
    BST(){
        root = NULL;
    }
    
    
    
    BinaryTreeNode* deleteHelper(BinaryTreeNode* root ,int data){
        if(root == NULL) return NULL;
        
        else if(root->leftNode!=NULL && root->data > data){
            BinaryTreeNode* leftNode = deleteHelper(root->leftNode, data);
            root->leftNode = leftNode;
            return root;
        }
        else if(root->rightNode != NULL && root->data < data){
            BinaryTreeNode* rightNode = deleteHelper(root->rightNode, data);
            root->rightNode = rightNode;
            return root;
        }
        
        
        else if(root->data == data){
            if(root->rightNode!= NULL && root->leftNode!= NULL){
                BinaryTreeNode* temp = root->rightNode;
                while(temp -> leftNode != NULL){
                    temp = temp->leftNode;
                }
                root->data = temp->data;
                root->rightNode = deleteHelper(root->rightNode,temp->data);
                
                return root;
            }
            
            if(root->rightNode != NULL && root->leftNode == NULL){
                BinaryTreeNode* temp = root->rightNode;
                root->rightNode = NULL;
                delete root;
                return temp;
            }
            if(root->rightNode == NULL && root->leftNode != NULL){
                BinaryTreeNode* temp = root;
                root = root->leftNode;
                delete temp;
                return root;
            }
            if (root->rightNode== NULL && root->leftNode == NULL){
                delete root;
                return NULL;
            }
            
        }
        
        return root;
        
    }
    
    
    void deleteNode(int data){
        this->root = deleteHelper(root,data);
        return ;
    }
    
    BinaryTreeNode* helper(BinaryTreeNode * root,int data){
        if(root == NULL){
            BinaryTreeNode * newNode = new BinaryTreeNode(data);
            root=newNode;
        }
        else if(root->data > data){
            root->leftNode = helper(root->leftNode,data);
        }
        else{
            root->rightNode = helper(root->rightNode,data);
        }
        return root;
    }
    
    
    
    void insert(int data){
        this->root = helper(root,data);
        return;
    }
    
    
    
    void printHelper(BinaryTreeNode * root){
        if(root == NULL) return;
        queue<BinaryTreeNode*> pendingNode;
        pendingNode.push(root);
        while(pendingNode.size()!=0){
            BinaryTreeNode * front = pendingNode.front();
            pendingNode.pop();
            cout<<front->data<<" : ";
            if(front->leftNode!= NULL){
                cout<<"L : "<<front->leftNode->data<<" ";
                pendingNode.push(front->leftNode);
            }
            if(front->rightNode!=NULL){
                cout<<front->rightNode->data<<" ";
                pendingNode.push(front->rightNode);
            }
            cout<<endl;
        }
        
        return;
    }
    
    
    
    void print(){
        return printHelper(root);
    }
};


