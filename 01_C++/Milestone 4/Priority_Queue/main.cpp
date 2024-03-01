#include<iostream>
using namespace std;
#include"Priority_Queue.h"
int main(){
    priorityQueue p;
    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);
    
    cout<<p.getSize()<<endl;
    cout<<p.getMin()<<endl;
    
    while(!p.isEmpty()){
        cout<<p.removeMin()<<" ";       //heap sort (intenally sorting)
                                        //time = O(nlogn) (insetion) + O(nlogn) (removeMin) = O(nlogn)
        
                                        // space = we are using extra vector O(n)
    }
    cout<<endl;
    
    
}
