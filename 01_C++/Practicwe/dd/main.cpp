#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<string>& result, string current, int open, int close, int max) {
    if (current.length() == max * 2) {
        result.push_back(current);
        return;
    }

    if (open < max) {
        backtrack(result, current + "(", open + 1, close, max);
    }
    if (close < open) {
        backtrack(result, current + ")", open, close + 1, max);
    }
}

vector<string> generateParentheses(int n) {
    vector<string> result;
    backtrack(result, "", 0, 0, n);
    return result;
}


 

int main() {
    int n = 3;
    vector<string> combinations = generateParentheses(n);
    for (const string& combination : combinations) {
        cout << combination << " ";
    }
    cout << endl;

    return 0;
}
