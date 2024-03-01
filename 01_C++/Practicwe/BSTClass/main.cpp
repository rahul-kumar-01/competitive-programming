//#include<iostream>
//#include<queue>
//
//using namespace std;
//#include"help.h"
//int main(){
//    BST b1;
//    b1.insert(100);
//    b1.insert(50);
//    b1.insert(500);
//    b1.insert(30);
//    b1.insert(200);
//    b1.insert(700);
//    b1.insert(32);
//    b1.insert(35);
//    b1.insert(38);
//    b1.insert(150);
//    b1.insert(250);
//    
//    
//    
//    
//    b1.print();
//    cout<<endl;
//    cout<<"--------------  *********    ------------"<<endl;
//    cout<<endl;
//    b1.deleteNode(50);
//    b1.print();
//}
//
//
///**********************************************************
//        Following is the Binary Tree Node class structure
//
//        template <typename T>
//        class BinaryTreeNode {
//        public :
//        T data;
//        BinaryTreeNode<T> *left;
//        BinaryTreeNode<T> *right;
//
//        BinaryTreeNode(T data) {
//                this -> data = data;
//                left = NULL;
//                right = NULL;
//        }
//        };
//
//***********************************************************/
//#include<climits>
//void merge_two_sorted_array(int input[], int start, int middle, int end) {
//  int p1[1000];
//  int i = start;
//  int j = middle + 1;
//  int k = start;
//  while (i <= middle && j <= end) {
//    if (input[i] >= input[j]) {
//      p1[k] = input[j];
//      ++j;
//      ++k;
//    } else {
//      p1[k] = input[i];
//      ++i;
//      ++k;
//    }
//  }
//  while (i <= middle) {
//    p1[k] = input[i];
//    ++i;
//    ++k;
//  }
//  while (j <= end) {
//    p1[k] = input[j];
//    ++j;
//    ++k;
//  }
//  for (int i = 0; i <= end; ++i) {
//    input[i] = p1[i];
//  }
//}
//
//void merge(int input[], int start, int end) {
//  if (start >= end)
//    return;
//  int middle = (start + end) / 2;
//  merge(input, start, middle);
//  merge(input, middle + 1, end);
//  merge_two_sorted_array(input, start, middle, end);
//}
//
//void mergesort(int input[], int size) { merge(input, 0, size - 1); }
//
//
//
//
//int len(BinaryTreeNode<int> *root) {
//  if (root == NULL) {
//    return 0;
//  }
//  return 1 + len(root->left) + len(root->right);
//}
//
//int *push_element_in_newArray(BinaryTreeNode<int> *root) {
//  if (root == NULL) {
//    int *output = new int[0];
//    return output;
//  }
//
//  int *output1 = push_element_in_newArray(root->left);
//  int *output2 = push_element_in_newArray(root->right);
//
//  int output1Size = len(root->left);
//  int output2Size = len(root->right);
//
//  int *finalOutput = new int[output1Size + output2Size + 1];
//  int k = 0;
//
//  for (int i = 0; i < output1Size; ++i) {
//    finalOutput[k] = output1[i];
//    ++k;
//  }
//  for (int i = 0; i < output2Size; ++i) {
//    finalOutput[k] = output2[i];
//    ++k;
//  }
//  finalOutput[k] = root->data;
//  return finalOutput;
//}
//void pairSum(BinaryTreeNode<int> *root, int sum) {
//  // Write your code here
//  if (root == NULL)
//    return;
//  int leng = len(root);
//  int *temp = push_element_in_newArray(root);
//  mergesort(temp, leng);
//
//  int i = 0;
//  int j = leng - 1;
//  while (i < j) {
//    if (temp[i] + temp[j] == sum) {
//      int count1 = 1;
//      int count2 = 1;
//      int a = i;
//      int b = j;
//      while(temp[a] == temp[a+1] && a<j){
//        ++a;
//        ++count1;
//      }
//      while (temp[b] == temp[b - 1] && b>i) {
//        --b;
//        ++count2;
//      }
//      for (int r = 0; r < (count1 * count2); ++r) {
//        cout << temp[i] << " " << temp[j] << endl;
//      }
//      i = i+count1;
//      j = j-count2;
//      
//
//    } else if (temp[i] + temp[j] > sum) {
//      --j;
//    } else {
//      ++i;
//    }
//  }
//  return;
//}
