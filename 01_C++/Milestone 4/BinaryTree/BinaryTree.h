template <typename T>
class BinaryTree{
public:
    T data;
    BinaryTree<T> * LeftNode;
    BinaryTree<T> * RightNode;
    
    BinaryTree(T data){
        this->data = data;
        LeftNode = NULL;
        RightNode = NULL;
    }
    
    //destructor cannot have any parameter
    
    ~BinaryTree(){
        delete LeftNode ;
        delete RightNode;
    }
};
