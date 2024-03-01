class BinaryTreeNode{
public:
    int data;
    BinaryTreeNode * left;
    BinaryTreeNode * right;
    
    BinaryTreeNode(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST{
public:
    BinaryTreeNode * root;
    
    BST(){
        root = NULL;
    }
private:
    BinaryTreeNode* helper_insert(BinaryTreeNode* root ,int data){
        if(root == NULL){
            BinaryTreeNode* root = new BinaryTreeNode (data);
            return root;
        }
        if(root->data > data){
            BinaryTreeNode*leftchild =  helper_insert(root->left ,data);
            root->left = leftchild;
            return root;
        }
        else{
            BinaryTreeNode*rightchild =  helper_insert(root->right, data);
            root->right = rightchild;
            return root;
        }
    }
public:
    void insert(int data){
        this->root =  helper_insert(root,data);
        return;
    }
private:
    BinaryTreeNode* helper_delete(BinaryTreeNode* root ,int data){
        if(root == NULL) return NULL;
        
        if(root->data > data){
            BinaryTreeNode* temp_left = helper_delete(root->left, data);
            root->left = temp_left;
            return root;
        }
        if(root->data < data){
            BinaryTreeNode * temp_right = helper_delete(root->right,data);
            root->right = temp_right;
            return root;
        }
        else{
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            
            if(root->left == NULL){
                BinaryTreeNode* temp_right = root->right;
                delete root;
                return temp_right;
            }
            if(root->right == NULL){
                BinaryTreeNode* temp_left = root->left;
                delete root;
                return temp_left;
            }
            else{
                BinaryTreeNode* minNode = root->right;

                while(minNode->left != NULL){
                    minNode = minNode->left;
                }
                int min_right = minNode->data;
                // delete temp;
                root->data = min_right;
                root->right = helper_delete(root->right,min_right);
                return root;
            }
        }
    }
public:
    void deleteData(int data){
        root =  helper_delete(root,data);
        return ;
    }
    
private:
    bool helper_hasData(int data,BinaryTreeNode* root){
        if(root == NULL) return false;
        if(root->data == data){
            return true;
        }
        if(root->data > data){
            return helper_hasData(data, root->left);
        }
        else{
            return helper_hasData(data, root->right);
        }
                              
    }
    
    
    
public:
    bool hasData(int data){
        return helper_hasData(data,root);
    }
    
};
