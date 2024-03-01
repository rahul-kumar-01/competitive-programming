#include<queue>
using namespace std;
class BinaryTreeNode{
public:
    int data;
    BinaryTreeNode* leftNode;
    BinaryTreeNode* rightNode;
    
    
    BinaryTreeNode(int data){
        this->data = data;
        leftNode = NULL;
        rightNode = NULL;
    }
};
    
    BinaryTreeNode * takeInput(){
        int data;
        cout<<"enter the root data : ";
        cin>>data;
        BinaryTreeNode* root = NULL;
        if(data != -1){
            BinaryTreeNode * newNode = new BinaryTreeNode(data);
            if(root == NULL){
                root = newNode;
            }
            
            root -> leftNode = takeInput();
            root -> rightNode = takeInput();
        }
        return root;
    }


    void print(BinaryTreeNode* root){
        if(root == NULL ) return ;
        cout<<root->data<<" : ";
        if(root -> leftNode != NULL) cout<<root->leftNode->data<<" ";
        if(root -> rightNode != NULL) cout<<root->rightNode->data;
        cout<<endl;
        print(root->leftNode);
        print(root->rightNode);
    }


    void printBinaryTreeLevelWise(BinaryTreeNode* root){
        if(root == NULL) return ;
        queue<BinaryTreeNode*> pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty()){
            BinaryTreeNode *front = pendingNodes.front();
            pendingNodes.pop();
            cout<<front->data<<" : ";
            if(front->leftNode != NULL){
                cout<<" L : "<<front->leftNode->data<<" ";
                pendingNodes.push(front->leftNode);
            }
            if(front->rightNode != NULL){
                cout<<" R : "<<front->rightNode->data;
                pendingNodes.push(front->rightNode);
            }
            cout<<endl;
            
        }
    }

    BinaryTreeNode* takeInputLevelWise(){
        
        queue<BinaryTreeNode*> pendingNodes;
        int n;
        cout<<"enter the data ";
        cin>>n;
        BinaryTreeNode* root = new BinaryTreeNode(n);
        pendingNodes.push(root);
        while(pendingNodes.size() != 0){
            BinaryTreeNode* front = pendingNodes.front();
            pendingNodes.pop();
            
            int leftData,rightData;
            cout<<"enter the left Node data of " <<front->data << " : " ;
            cin>>leftData;
            cout<<"enter the right Node data " <<front->data << " : ";
            cin>>rightData;
            
            if(leftData != -1){
                BinaryTreeNode* leftChild = new BinaryTreeNode(leftData);
                front->leftNode = leftChild;
                pendingNodes.push(leftChild);
            }
            if(rightData != -1){
                BinaryTreeNode* rightChild = new BinaryTreeNode(rightData);
                front->rightNode = rightChild;
                pendingNodes.push(rightChild);
            }
            
        }
        return root;
    }

int minData(BinaryTreeNode* root){
    
    if(root == NULL) return INT_MAX;
   
    int a = minData(root->leftNode);
    int b = minData(root->rightNode);
    return min(root->data,min(a,b));
}

int maxData(BinaryTreeNode* root){
    if(root == NULL) return INT_MIN;
    int a = maxData(root->leftNode);
    int b = maxData(root->rightNode);
    return max(root->data,max(a,b));
}


    int height(BinaryTreeNode* root){
        if(root == NULL) return 0;
        return max(height(root->leftNode),height(root->rightNode))+1;
    }

    int diameter(BinaryTreeNode* root){
        if(root == NULL) return 0;
        int height1 = height(root->leftNode);
        int height2 = height(root->rightNode);
        int diameter1 = diameter(root->leftNode);
        int diameter2 = diameter(root->rightNode);
        return max(diameter1,max(diameter2,height1+height2));
    }

    pair<int, int> diameterBetter(BinaryTreeNode * root){
        if(root == NULL){
            pair<int,int> p;
            p.first = 0;
            p.second = 0;
            return p;
        }
        
        pair<int,int> p1 = diameterBetter(root->leftNode);
        pair<int,int> p2 = diameterBetter(root->rightNode);
        
        pair<int,int> output;
        output.first = max(p1.first , p2.first) + 1;
        output.second = max(p1.second,max(p2.second,p1.first+p2.first));
        return output;
    }




