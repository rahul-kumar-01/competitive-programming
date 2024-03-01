
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string uniqueChar(string str) {
    string ans;
    unordered_map<char, int> map1;
    for(int i=0;i<str.length();++i){
        if(map1[str[i]]>0){                 //this will automatically create map1[str[i]] = 0;
            continue;
        }
        else{
            ans.push_back(str[i]);
            ++map1[str[i]];
        }
    }
    return ans;
}

int main() {
    
    string str;
    cin >> str;
    cout << uniqueChar(str)<<endl;

}
