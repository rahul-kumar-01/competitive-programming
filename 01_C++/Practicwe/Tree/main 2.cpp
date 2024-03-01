#include<iostream>
using namespace std;
#include"TreeNode.h"
#include<climits>
#include<queue>

TreeNode* takeInput(){
    int rootData;
    cout<<"enter the root data : ";
    cin>>rootData;
    TreeNode* root = new TreeNode(rootData);
    int noOfChildren;
    cout<<"No of children of "<<rootData<<" : ";
    cin>>noOfChildren;
    for(int i=0;i<noOfChildren;++i){
        TreeNode* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void print(TreeNode* root){
    if(root == NULL) return;
    cout<<root->data<<" : ";
    for(int i=0;i<root->children.size();++i){
        cout<<root->children[i]->data<<" ";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();++i){
        print(root->children[i]);
    }
}

TreeNode* takeInputLevelWise(){
    int rootData;
    cout<<"enter the root data : ";
    cin>>rootData;
    TreeNode* root = new TreeNode(rootData);
    queue<TreeNode*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode* front = pendingNodes.front();
        pendingNodes.pop();
        int noOfChildren;
        cout<<"enter the no of children of " <<front->data<<" : ";
        cin>>noOfChildren;
        for(int i=0;i<noOfChildren;++i){
            int childData;
            cout<<"enter the "<<i+1<<" th "<<"child data of "<<front->data<<" :";
            cin>>childData;
            TreeNode* child = new TreeNode(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void printLevelWise(TreeNode * root){
    if(root == NULL) return;
    queue<TreeNode*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode*front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<" : ";
        for(int i=0;i<front->children.size();++i){
            cout<<front->children[i]->data<<" ";
            pendingNodes.push(front->children[i]);
        }
        cout<<endl;
    }
    return;
}

void deleteTree(TreeNode* root){
    for(int i=0;i<root->children.size();++i){
        deleteTree(root->children[i]);
    }
    delete root;
}

int sumOfNode(TreeNode* root){
    int sum = root->data;
    for(int i=0;i<root->children.size();++i){
        sum += sumOfNode(root->children[i]);
    }
    return sum;
}

TreeNode* maxDataNode(TreeNode* root){
    int max = root->data;
    TreeNode * output = root;

    for(int i=0;i<root->children.size();++i){
       TreeNode* ans = maxDataNode(root->children[i]);
        if(max < ans->data){
            max = ans->data;
            output = ans;
        }
    }
    return output;
}


int getHeight(TreeNode* root){
    if(root == NULL) return 0;
    int max = 0;
    for(int i=0;i<root->children.size();++i){
        int ans = getHeight(root->children[i]);
        if(max < ans){
            max = ans;
        }
    }
    return max + 1;
}

int getLeafNodeCount(TreeNode* root){
    if(root->children.size()==0) return 1;
    int max = 0;
    for(int i=0;i<root->children.size();++i){
        max += getLeafNodeCount(root->children[i]);
    }
    return max;
}

TreeNode * nodeWithMaxSum(TreeNode* root){
    if(root == NULL) return NULL;
    int max = root->data;
    TreeNode*output = root;
    for(int i=0;i<root->children.size();++i){
        max += root->children[i]->data;
    }
    for(int i=0;i<root->children.size();++i){
        TreeNode* help =  nodeWithMaxSum(root->children[i]);
        int ans =help->data;
        for(int i=0;i<help->children.size();++i){
            ans += help->children[i]->data;
        }
        if(ans > max){
            max = ans;
            output = help;
        }
    }
    return output;
}


bool allIndentical(TreeNode* root1,TreeNode* root2){
    if(root1 == NULL && root2 == NULL) return true;
    if(root1->children.size()==0 ^ root2->children.size()==0) return false;

        if(root1->data == root2->data && root1->children.size()==root2->children.size()){
            for(int i=0;i<root1->children.size();++i){
                if(root1->children[i]->data != root2->children[i]->data){
                    return false;
                }
            }
        }
        else return false;

    for(int i=0;i<root1->children.size();++i){
        bool output = allIndentical(root1->children[i], root2->children[i]);
        if(output == false) return false;
    }
    return true;


}

TreeNode* nextLargest(TreeNode* root,int x){
    if(root == NULL) return NULL;

    TreeNode* output = NULL;
    int min = INT_MAX;
    if(root->data > x){
        output = root;
        min = root->data;
    }
    

    for(int i=0;i<root->children.size();++i){
        TreeNode * temp = nextLargest(root->children[i],x);
        if(temp != NULL){
            if( min == INT_MAX){
                min = temp->data;
                output = temp;
            }
            else if(min>temp->data){
                min = temp->data;
                output = temp;
            }
        }
        
    }
    return output;
}



pair<TreeNode*, TreeNode*> helper(TreeNode* root){
    if(root == NULL){
        pair<TreeNode*, TreeNode*> p;
        p.first = NULL;
        p.second = NULL;
        return p;
    }
    
    TreeNode * largest = root;
    TreeNode * secondLargest = NULL;
 
    
    for(int i=0;i<root->children.size();++i){
        pair<TreeNode*, TreeNode*> p = helper(root->children[i]);
        
        if( p.first != NULL && largest->data < p.first->data){
            if(p.second != NULL && p.second->data > largest->data){
                secondLargest = p.second;
            }
            else{
                secondLargest = largest;
            }
            largest = p.first;
        }
        else{
            if(secondLargest != NULL && p.first != NULL){
                if(secondLargest->data < p.first->data){
                    secondLargest = p.first;
                }
            }
            else{
                secondLargest = p.first;
            }
        }
    }
    pair<TreeNode*, TreeNode*> output;
    output.first = largest;
    output.second = secondLargest;
    return output;
}
TreeNode* getSecondLargest(TreeNode* root){
    return helper(root).second;
}

void helper_2(TreeNode* root,int n){
    if(root == NULL) return ;
    root->data = n;
    for(int i=0;root->children.size();++i){
        helper_2(root->children[i] , n+1);
    }
    return;
}


void replaceWithDepth(TreeNode* root){
    helper_2(root,0);
}

int main(){
//    TreeNode * root = takeInput();
//    print(root);
    TreeNode * root = takeInputLevelWise();
//    printLevelWise(root);
    TreeNode* output = maxDataNode(root);
    cout<<output->data<<endl;
    TreeNode* output2 = nextLargest(root, 10);
    cout<<output2->data<<endl;
    TreeNode * output3 = getSecondLargest(root);
    cout<<output3->data<<endl;
}
