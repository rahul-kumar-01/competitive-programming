
class BST{
    BinaryTreeNode<int>* node;

public:
    BST(){
        node = NULL;
    }

//delete Data
private:
    BinaryTreeNode<int>* deleteData(int data,BinaryTreeNode<int>* node){
        if(node == NULL) return NULL;

        if(node->data > data){
            node->left = deleteData(data,node->left);
            return node;
        }
        else if(node->data < data){
            node->right = deleteData(data,node->right);
            return node;
        }
        else{
            if(node->right == NULL && node->left == NULL){
                delete node;
                return NULL;
            }
            else if(node->right == NULL){
                BinaryTreeNode<int>* temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else if(node->left == NULL){
                BinaryTreeNode<int>* temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else{
                BinaryTreeNode<int>* minNode = node->right;
                while(minNode->left != NULL){
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteData(rightMin,node->right);
                return node;
            }
        }
    }


public:
    void deleteData(int data){
        node =  deleteData(data,node);
    }

// insertion Node
private:
    BinaryTreeNode<int>* insert(int data,BinaryTreeNode<int> * node){
        if(node == NULL){
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int> (data);
            return newNode;
        }
        if(data > node->data){
            BinaryTreeNode<int>* childNode = insert(data ,node->right);
            node->right = childNode;
            //we can directly put newNode->rigth = insert(data,newNode->right);
            // & we can use else downside
        }
        if(data < node->data){
            BinaryTreeNode<int>*childNode =  insert(data,node->left);
            node->left = childNode;
        }
        return node;
    }
public:
    void insert(int data){
        this->node =  insert(data,this->node); //we can write directly

    }



//check Data
private:
    bool hasData(int data,BinaryTreeNode<int>* root){
        if(root == NULL) return false;
        if(root->data == data){
            return true;
        }
        else if(root->data > data){
            return hasData(data,root->left);
        }
        else {
            return hasData(data,root->right);
        }
    }

public:
    bool hasData(int data){
        return hasData(data,node);
    }

    
};


