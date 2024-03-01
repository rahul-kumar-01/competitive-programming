#include <iostream>
#include <string>
#include<stack>
using namespace std;

bool isBalanced(string expression)
{
    // Write your code here
    stack <char> bracket;
    for(int i=0;i<expression.length();++i){
        if(bracket.empty()){
            bracket.push(expression[i]);
        }
        else {
            if(expression[i] == ')' && bracket.top()=='(' ){
                    bracket.pop();
            } else {
              bracket.push(expression[i]);
            }
        }
}
    if(bracket.size() == 0) return true;
    else return false;
}

int main()
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}



#include<stack>
void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    if(input.size()==0){
        while (extra.size() != 0) {
          int temp = extra.top();
          input.push(temp);
          extra.pop();
        }
    }
    else if (extra.size()==0){
        int temp = input.top();
        input.pop();
        reverseStack(input,extra);
        while(input.size() != 0){
            int num = input.top();
            extra.push(num);
            input.pop();
        }
        input.push(temp);
        while(extra.size() != 0){
            int num = extra.top();
            input.push(num);
            extra.pop();
        }
    }
}

#include<queue>
void reverseQueue(queue<int> &input) {
    // Write your code here

    if(input.size()==0){
        return;
    }

    int temp = input.front();
    input.pop();
    reverseQueue(input);
    input.push(temp);

}
