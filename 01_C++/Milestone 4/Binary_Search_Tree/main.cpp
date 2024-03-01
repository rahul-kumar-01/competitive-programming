#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
#include"binary_search_tree.h"

//without increasing order
void element_in_range_k1_k2 (BinaryTree<int>* root){
    
}

//START


int maximum(BinaryTree<int>* root){
    if(root == NULL) return INT_MIN;
    int ans1 = maximum(root->LeftNode);
    int ans2 = maximum(root->RightNode);
    return max(root->data,max(ans1,ans2));
}

int minimum(BinaryTree<int>* root){
    if(root == NULL) return INT_MAX;
    return min(root->data, min(minimum(root->LeftNode) , minimum(root->RightNode)));
}
 
// time complexity T(n) = 2T(n/2) + kn = O(n*log(n))
// if there is only element in right side node or left side node
// time complexity T(n) = T(n-1) + kn = = O(n^2) =O(n*h)

bool isBST_1(BinaryTree<int>* root){
    if(root == NULL) return true;
    int maxLeft = maximum(root->LeftNode);
    int minRight = minimum(root->RightNode);
    return maxLeft < root->data && minRight >= root->data &&                                    isBST_1(root->LeftNode) && isBST_1(root->RightNode);
}

// 2nd part
// time complexity o(n)(n) in above case


class isBSTClass{
public:
    int minimum;
    int maximum;
    bool isBST;
};


//time complexity T(n) = 2T(n/2) + k = O(n)
isBSTClass isBST_2(BinaryTree<int> * root){
    if(root == NULL){
        isBSTClass output;
        output.isBST = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        return output;
    }
    isBSTClass leftOutput = isBST_2(root->LeftNode);
    isBSTClass rightOutput = isBST_2(root->RightNode);
    int minimum = min(root->data,min(leftOutput.minimum,rightOutput.minimum));
    int maximum = max(root->data,max(leftOutput.maximum,rightOutput.maximum));
    bool isBSTFinal = leftOutput.isBST && rightOutput.isBST && (root->data >leftOutput.maximum)  && root->data < rightOutput.minimum;
    
    
    isBSTClass temp;
    temp.minimum = minimum;
    temp.maximum = maximum;
    temp.isBST = isBSTFinal;
    return temp;
}


//3rd part
bool isBST_3 (BinaryTree<int> * root,int min = INT_MIN, int max = INT_MAX){
    if(root == NULL){
        return true;
    }
    if(root->data < min || root->data > max){
        return false;
    }
    bool is_left_okay = isBST_3(root->LeftNode,min,root->data);
    bool is_right_okay = isBST_3(root->RightNode,root->data,max);
    return is_left_okay && is_right_okay;
}





int main(){
    BinaryTree<int> * root = takeInputLevelWise();
    cout<<isBST_1(root)<<endl;
    cout<<isBST_2(root).isBST<<endl;
    cout<<isBST_3(root)<<endl;
    delete root;
}












