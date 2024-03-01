using namespace std;
template<typename T>
class BinaryTreeNode{
public:
    BinaryTreeNode<T>* left ;
    BinaryTreeNode<T>* right;
    T data;
    BinaryTreeNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

//class BST{
//public:
//    BinaryTreeNode<int>* node;
//
//public:
//    BST(){
//        node = NULL;
//    }
//
//
//
////delete Data
//private:
//    BinaryTreeNode<int>* deleteData_2(int data,BinaryTreeNode<int>* node){
//        if(node == NULL) return NULL;
//
//        if(node->data > data){
//            node->left = deleteData_2(data,node->left);
//            return node;
//        }
//        else if(node->data < data){
//            node->right = deleteData_2(data,node->right);
//            return node;
//        }
//        else{
//            if(node->right == NULL && node->left == NULL){
//                delete node;
//                return NULL;
//            }
//            else if(node->right == NULL){
//                BinaryTreeNode<int>* temp = node->left;
//                node->left = NULL;
//                delete node;
//                return temp;
//            }
//            else if(node->left == NULL){
//                BinaryTreeNode<int>* temp = node->right;
//                node->right = NULL;
//                delete node;
//                return temp;
//            }
//            else{
//                BinaryTreeNode<int>* minNode = node->right;
//                while(minNode->right != NULL){
//                    minNode = minNode->right;
//                }
//                int rightMin = minNode->data;
//                node->data = rightMin;
//                node->right = deleteData_2(rightMin,node->right);
//                return node;
//            }
//        }
//    }
//
//
//public:
//    void deleteData(int data){
//        this->node =  deleteData_2(data,node);
//        return;
//    }
//
//// insertion Node
//private:
//    BinaryTreeNode<int>* insert(int data,BinaryTreeNode<int> * node){
//        if(node == NULL){
//            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int> (data);
//            return newNode;
//        }
//
//        if(data > node->data){
//            BinaryTreeNode<int>* childNode = insert(data ,node->right);
//            node->right = childNode;
//            //we can directly put newNode->rigth = insert(data,newNode->right);
//            // & we can use else downside
//        }
//        if(data < node->data){
////            BinaryTreeNode<int>*childNode =  insert(data,node->left);
////            node->left = childNode;
//            node->left = insert(data,node->left);       // we can write both
//        }
//        return node;
//    }
//public:
//    void insert(int data){
//        this->node =  insert(data,this->node); //we can write directly
//
//    }
//
//
//
////check Data
//private:
//    bool hasData(int data,BinaryTreeNode<int>* root){
//        if(root == NULL) return false;
//        if(root->data == data){
//            return true;
//        }
//        else if(root->data > data){
//            return hasData(data,root->left);
//        }
//        else if(root->data < data){
//            return hasData(data,root->right);
//        }
//        return false;
//    }
//
//public:
//    bool hasData(int data){
//        return hasData(data,node);
//    }
//
//    ~BST(){
//        delete node;
//    }
//};
class BST {
    // Define the data members
    
   public:
    BinaryTreeNode<int>* node;
    BST() {
        // Implement the Constructor
        node = NULL;
    }

    /*----------------- Public Functions of BST -----------------*/

private:
    BinaryTreeNode<int>* helper_remove(BinaryTreeNode<int>* node,int data){
        if(node == NULL) return NULL;
        if(node->data > data){
            node->left  = helper_remove(node->left, data);
            return node;
        }
        if(node->data < data){
            node->right = helper_remove(node->right, data);
            return node;
        }
        if(node->data == data){
            if(node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            }
            if(node->left == NULL &&node-> right != NULL){
                BinaryTreeNode<int>* temp = node->right;
                node ->right =  NULL;
                delete node;
                return temp;
            }
            if(node->right == NULL && node->left != NULL){
                BinaryTreeNode<int>* temp = node->left;
                node->left= NULL;
                delete node;
                return temp;
            }
            if(node->right != NULL && node->left  != NULL){
                BinaryTreeNode<int>* minNode = node->right;

                while(minNode->left != NULL){
                    minNode = minNode->left;
                }
                int min_right = minNode->data;
                // delete temp;
                 node->data = min_right;
                node->right = helper_remove(node->right,min_right);
                return node;
            }
        }
        return node;
    }
public:
    void remove(int data) {
        // Implement the remove() function
        node = helper_remove(node,data);
        return ;
    }
    private:
    void print(BinaryTreeNode<int>* root){
        if(root == NULL) return ;
        cout<<root->data<<":";
        if(root->left != NULL){
            cout<<"L:"<<root->left->data;
        }
        if(root->right != NULL){
            cout<<",R:"<<root->right->data;
        }
        cout<<endl;
        print(root->left);
        print(root->right);
    
    }
public:
    void print() {
        // Implement the print() function
        return print(node);
    }
private:
BinaryTreeNode<int>* helper_insert(BinaryTreeNode<int>* node ,int data){
    if(node == NULL){
        BinaryTreeNode<int> * newNode = new BinaryTreeNode<int>(data);
        return newNode;
    }

    if (node->data > data) {
      BinaryTreeNode<int>* temp = helper_insert(node->left, data);
      node->left = temp;
      return node;
    }
    if (node->data < data) {
      node->right = helper_insert(node->right, data);
      return node;
    }
    return node;
}
public:
void insert(int data) {
  // Implement the insert() function
  this->node = helper_insert(node, data);
  return ;
}
private:
bool search_data(BinaryTreeNode<int> *root, int data){
    if(root == NULL) return false;
    if(root->data == data) return true;
    if(root->data > data){
        return search_data(node->left,data);
    }
    if(root->data < data){
        return search_data(node->right,data);
    }
    return false;
}


public:
    bool search(int data) {
  // Implement the search() function
  return search_data(node, data);
}
};
