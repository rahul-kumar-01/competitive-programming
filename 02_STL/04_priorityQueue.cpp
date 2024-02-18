#include<iostream>
#include<queue>
using namespace std;

auto cmp = [](int a,int b){  // for min pq
    return a>b;
};


int main(){
    priority_queue<int>pq;  // max heap
    priority_queue<int , vector<int>, greater<int>> pq1; //min heap

    pq.empty();
    pq.size();
    pq.top();
    pq.push(10);
    pq.pop();

    //min heap using comparator function
    priority_queue<int,vector<int>,decltype(cmp)>pq_cmp(cmp);
    
}