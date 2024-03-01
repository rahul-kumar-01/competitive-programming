//same as previous nothing has changed don't need to refer


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

BinaryTree<int>* takeInputLevelWise(){
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
