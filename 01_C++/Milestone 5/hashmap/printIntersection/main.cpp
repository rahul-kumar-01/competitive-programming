#include<iostream>
#include<unordered_map>
#include<cmath>
using namespace std;

void printIntersection(int arr1[],int arr2[],int size1,int size2){
    unordered_map<int, int> part1;
    unordered_map<int, int> part2;
   

    for(int i=0;i<size1;++i){
        ++part1[arr1[i]];
    }
   
    for(int i=0;i<size2;++i){
        ++part2[arr2[i]];
    }
    
    for(int i=0;i<size1;++i){
        if(part1[arr1[i]]>0 && part2[arr1[i]]>0){
            cout<<arr1[i]<<" ";
            --part1[arr1[i]];
            --part2[arr1[i]];
//            cout<<part1.count(arr1[i])<<part1.count(arr2[i])<<endl;
        }
    }
    cout<<endl;
}

int main(){
    int arr1[15] = {2,2,23,3,2,2,2,2,2,2,2,2,2,2,2};
    int arr2[10] = {2,2,2,3,23,2,2,2,2,2};
    int size1 = 15;
    int size2 = 10;
    printIntersection(arr1,arr2,size1,size2);
}
