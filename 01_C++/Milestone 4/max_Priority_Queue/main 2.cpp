#include<iostream>
using namespace std;
#include"max.pq.h"
int main(){
    PriorityQueue p;
    p.insert(100);
    p.insert(10);
    p.insert(20);
    p.insert(40);
    p.insert(200);
    p.insert(30);
    p.insert(70);
    p.insert(20);
    
    cout<<p.getSize()<<endl;
    cout<<p.isEmpty()<<endl;
    cout<<p.getMax()<<endl;
   
    
    while(!p.isEmpty()){
        cout<<p.removeMax()<<" ";
    }
    cout<<endl;
}
