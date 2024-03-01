#include <iostream>
#include<queue>
using namespace std;
int main() {
    priority_queue<int> pq;           //by default max pq
    pq.push(16);
    pq.push(1);
    pq.push(167);
    pq.push(34);
    pq.push(87);
    pq.push(23);
    pq.push(90);
    
    cout<<"Size : "<<pq.size()<<endl;
    cout<<"Top : "<<pq.top()<<endl;
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    return 0;
}
