#include<iostream>
#include<queue>
using namespace std;
#include"BinaryTreeNode.h"


int main(){
    BinaryTreeNode * root = takeInputLevelWise();
    printBinaryTreeLevelWise(root);
    cout<<height(root)<<endl;
    cout<<diameter(root)<<endl;
}



//***********************************************************
//BinaryTreeNode <int> * helper(int * preorder,int * inorder, int PreOrder_Si, int PreOrder_Ei, int InOrder_Si, int inOrder_Ei){
//    if(InOrder_Si > inOrder_Ei){
//        return NULL;
//    }
//    int root_data = preorder[PreOrder_Si];
//    BinaryTreeNode <int> * root  = new BinaryTreeNode<int>(root_data);
//
//
//    int root_index = -1;
//    for (int i = InOrder_Si; i <= inOrder_Ei; ++i){
//          if (inorder[i] == root_data) {
//            root_index = i;
//            break;
//          }
//}
//
//        int Left_preOrder_Si = PreOrder_Si + 1;
//        int Left_preOrder_Ei;
//        int Left_inOrder_Si = InOrder_Si;
//        int Left_inOrder_Ei = root_index - 1;
//        Left_preOrder_Ei = (Left_inOrder_Ei - Left_inOrder_Si) + Left_preOrder_Si;
//        int Right_preOrder_Si = Left_preOrder_Ei + 1;
//        int Right_preOrder_Ei = PreOrder_Ei;
//        int Right_inOrder_Si = root_index + 1;
//        int Right_inOrder_Ei = inOrder_Ei;
//
//        BinaryTreeNode<int> *child1 =
//            helper(preorder, inorder, Left_preOrder_Si, Left_preOrder_Ei,
//                   Left_inOrder_Si, Left_inOrder_Ei);
//        BinaryTreeNode<int> *child2 =
//            helper(preorder, inorder, Right_preOrder_Si, Right_preOrder_Ei,
//                   Right_inOrder_Si, Right_inOrder_Ei);
//        root->left = child1;
//        root->right = child2;
//
//        return root;
//}
//BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
//    // Write your code here
//     return helper(preorder,inorder,0,inLength-1,0,inLength-1);
//
//}
