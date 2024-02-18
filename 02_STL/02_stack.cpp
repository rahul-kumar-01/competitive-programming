#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main(){

    stack<int>s;
    s.empty();
    s.top();
    s.pop();
    s.size();
    s.push(10);

    queue<int>q;
    q.front();
    q.back();
    q.push(10);
    q.pop();
    q.size();
    q.empty();
    

    deque<int>dq;
    dq.front();
    dq.back();
    dq.push_front(10);
    dq.push_back(20);
    dq.pop_back();
    dq.pop_front();
    dq.size();
    dq.empty();

    

}